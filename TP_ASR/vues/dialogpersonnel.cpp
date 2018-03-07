#include "dialogpersonnel.h"
#include "ui_dialogpersonnel.h"
#include "modeles/personnel.h"
#include "modeles/compte.h"
#include "bdmanager.h"

#define LBLINFORMATICIEN "Informaticien"

DialogPersonnel::DialogPersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPersonnel)
{
    ui->setupUi(this);

    bdManager = new BDManager();

    // Set dialog to creation mode
    create = true;

    // Recover label of TType table
    initType();

    // By default, disable QLineEdit (login + pass)
    ui->leLogin->setEnabled(false);
    ui->leMotdepasse->setEnabled(false);
}

DialogPersonnel::~DialogPersonnel()
{
    delete ui;
}

void DialogPersonnel::initType()
{
    QSqlQueryModel * model = bdManager->selectAllType();
    model->removeColumn(0); // Remove id column. Just keep label column for printing
    ui->cbType->setModel(model);
    ui->cbType->show();
}

void DialogPersonnel::on_btnOk_clicked()
{
    bool leCompleted =true; //line edit all filled
    QString ssRedBorder="border: 2px solid red"; //stle for red border

    if (ui->leNom->text().isEmpty())
    {
        ui->leNom->setStyleSheet(ssRedBorder);
        leCompleted = false;
    } else ui->leNom->setStyleSheet("");

    if (ui->lePrenom->text().isEmpty())
    {
        ui->lePrenom->setStyleSheet(ssRedBorder);
        leCompleted = false;
    } else ui->lePrenom->setStyleSheet("");

    // If informaticien is selected, check field login + pass
    if (ui->cbType->currentText().compare(LBLINFORMATICIEN) == 0)
    {
        if (ui->leLogin->text().isEmpty())
        {
            ui->leLogin->setStyleSheet(ssRedBorder);
            leCompleted = false;
        } else ui->leLogin->setStyleSheet("");

        if (ui->leMotdepasse->text().isEmpty())
        {
            ui->leMotdepasse->setStyleSheet(ssRedBorder);
            leCompleted = false;
        } else ui->leMotdepasse->setStyleSheet("");
    }

    if (leCompleted) {
       personnelIsValid();
       create = true; // Reset the mode
       accept();
    }
    else
        ui->lblObligatoire->setStyleSheet("color:red");
}

void DialogPersonnel::on_cbType_activated(const QString &arg1)
{
    // Need login and pass if informaticien selected
    if (arg1.compare(LBLINFORMATICIEN) == 0)
    {
        ui->leLogin->setEnabled(true);
        ui->leMotdepasse->setEnabled(true);
    }
    else
    {
        ui->leLogin->clear();
        ui->leMotdepasse->clear();

        ui->leLogin->setEnabled(false);
        ui->leMotdepasse->setEnabled(false);

        ui->leLogin->setStyleSheet("");
        ui->leMotdepasse->setStyleSheet("");
    }
}

void DialogPersonnel::personnelIsValid()
{
    int idPersonnel = getIdPersonnel();

    Personnel * personnel = new Personnel(
                ui->leNom->text(),
                ui->lePrenom->text(),
                ui->cbType->currentIndex() + 1
                );

    personnel->setId(getIdPersonnel()); // Set id because if modification, bdManager->modifyPersonnel need it.

    if (create)
        idPersonnel = bdManager->addPersonnel(personnel); // Add personnel to the database. Return the lastInsertId.
    else
        bdManager->modifyPersonnel(personnel); // Modify personnel to the database

    if (bdManager->isInformaticien(personnel->getId())) // Need to remove the account link the the personnel if he changes of Type.
        bdManager->removeCompte(personnel->getId()); // Remove account thanks to the personnel id.

    // If Informaticien has been selected
    if (ui->cbType->currentText().compare(LBLINFORMATICIEN) == 0)
    {
        Compte * compte = new Compte(
                    idPersonnel,
                    ui->leLogin->text(),
                    ui->leMotdepasse->text()
        );
            bdManager->addCompte(compte); // Add compte to the database
    }
}

void DialogPersonnel::setPersonnel(Personnel * personnel)
{
    QString nomType = bdManager->selectTypeSpecificId(personnel->getIdType());

    setIdPersonnel(personnel->getId()); // DialogPersonnel need to know which personnel is actually modified (id). Avoid to do a complex sql request.
    ui->leNom->setText(personnel->getNom());
    ui->lePrenom->setText(personnel->getPrenom());
    ui->cbType->setCurrentText(nomType);

    // Need to fill login and mdp fields if his type is Informaticien
    if (nomType.compare(LBLINFORMATICIEN) == 0)
    {
        Compte * compte = bdManager->selectCompteSpecificIdPersonnel(personnel->getId());
        ui->leLogin->setEnabled(true);
        ui->leMotdepasse->setEnabled(true);

        ui->leLogin->setText(compte->getLogin());
        ui->leMotdepasse->setText(compte->getMotdepasse());
    }
}
