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
    QSqlQueryModel * model = BDManager::selectAllType();
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
    int id;

    Personnel * personnel = new Personnel(
                ui->leNom->text(),
                ui->lePrenom->text(),
                ui->cbType->currentIndex() + 1
                );

    id = BDManager::addPersonnel(personnel); // Add personnel to the database

    // If Informaticien has been selected
    if (ui->cbType->currentText().compare(LBLINFORMATICIEN) == 0)
    {
        Compte * compte = new Compte(
                    id,
                    ui->leLogin->text(),
                    ui->leMotdepasse->text()
        );

        BDManager::addCompte(compte); // Add compte to the database
    }
}
