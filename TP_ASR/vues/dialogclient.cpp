#include "dialogclient.h"
#include "ui_dialogclient.h"
#include "bdmanager.h"

DialogClient::DialogClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClient)
{
    ui->setupUi(this);

    // Set dialog to creation mode
    create = true;

    //Init Date
    ui->deJourRdv->setMinimumDate(QDate::currentDate());

    //InitResourcesList
    //String list of ressources names
    QStringList ressourcesNames;
    ressourcesNames <<"ressource1"<<"ressource2"<<"ressource3"<<"ressource4"<<"ressource5"<<"ressource6"<<"ressource1"<<"ressource2"<<"ressource3";

    ui->lwRessources->addItems(ressourcesNames);
    QListWidgetItem* pItem=0;
    for(int i = 0; i < ui->lwRessources->count(); ++i){
            pItem = ui->lwRessources->item(i);
            pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
            pItem->setCheckState(Qt::Unchecked);
        }
}

DialogClient::~DialogClient()
{
    delete ui;
}

void DialogClient::on_btnOk_clicked()
{
    bool leCompleted =true; //line edit all filled
    bool lwCompleted =false; //at least on resources (listWidget) checked
    bool leacceptable=true; //format respected for tel and cp

    QString ssRedBorder="border: 2px solid red"; //stle for red border

    QList<QLineEdit *> list=this->findChildren<QLineEdit *>();//get all lineEdit in the form
    list.removeOne(ui->leTel);//remove facultative fields

    foreach (QLineEdit * lineEdit, list) {
        if (lineEdit->text().isEmpty() ){//True for all empty field
            lineEdit->setStyleSheet(ssRedBorder);
            leCompleted = false;
        }else{
            lineEdit->setStyleSheet("");//remove an anterior red border
        };
    }

    if (!ui->leCp->hasAcceptableInput()){
        ui->leCp->setStyleSheet(ssRedBorder);
        leacceptable=false;
    }else ui->leCp->setStyleSheet("");

    if (!(ui->leTel->text().isEmpty())&&!(ui->leTel->hasAcceptableInput())){
        ui->leTel->setStyleSheet(ssRedBorder);
        leacceptable=false;
    }else ui->leTel->setStyleSheet("");

    for(int i=0;i<ui->lwRessources->count(); ++i)
    {
        QListWidgetItem* item = ui->lwRessources->item(i);
        if (item->checkState()==2)//TODO : constante check state true for checked ressources
            lwCompleted=true;
    }

    if (!lwCompleted)ui->lwRessources->setStyleSheet(ssRedBorder);//red border if no resources selected
            else ui->lwRessources->setStyleSheet("");

    if (leCompleted && lwCompleted && leacceptable){
        clientIsValid();
        create = true; // Reset the mode
        accept();
     }
    else ui->lblObligatoire->setStyleSheet("color:red");
}

void DialogClient::clientIsValid()
{
    Client * client = new Client(
        ui->leNom->text(),
        ui->lePrenom->text(),
        ui->leAdresse->text(),
        ui->leVille->text(),
        ui->leCp->text(),
        ui->teCommentaires->toPlainText(),
        ui->leTel->text(),
        ui->deJourRdv->date(),
        ui->sbDuree->value(),
        ui->sbPriorite->value()
    );

    if (create)
        BDManager::addClient(client); // Add the client to the database
    else
        BDManager::modifyClient(client, idClient); // Modify the client to the database
}

void DialogClient::setClient(Client * client)
{
    ui->leNom->setText(client->getNom());
    ui->lePrenom->setText(client->getPrenom());
    ui->leAdresse->setText(client->getAdresse());
    ui->leVille->setText(client->getVille());
    ui->leCp->setText(QString::number(client->getCp()));
    ui->teCommentaires->setText(client->getCommentaires());
    ui->leTel->setText(QString::number(client->getnumTel()));
    ui->deJourRdv->setDate(client->getJourPassage());
    ui->sbDuree->setValue(client->getDureeEstime());
    ui->sbPriorite->setValue(client->getPriorite());
}
