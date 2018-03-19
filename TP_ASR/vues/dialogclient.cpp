#include "dialogclient.h"
#include "ui_dialogclient.h"
#include "bdmanager/bdmanagerclient.h"

#include <QList>

DialogClient::DialogClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClient)
{
    ui->setupUi(this);

    bdManagerClient = new BDManagerClient();
    bdManagerPersonnel = new BDManagerPersonnel();
    bdManagerPlanification = new BDManagerPlanification();

    client = nullptr;

    // Set dialog to creation mode
    create = true;

    // Set validator to CP
    ui->leCp->setValidator(new QIntValidator(0,99999));

    // Set validator to Tel
    QRegExp regx("0[1-9]\\d{8}");
    ui->leTel->setValidator(new QRegExpValidator(regx, NULL));

    //Init Date
    ui->deJourRdv->setMinimumDate(QDate::currentDate());

    //Init Ressources
    initRessources();
}

DialogClient::~DialogClient()
{
    delete ui;

    // Delete BDManager
    delete bdManagerClient;
    delete bdManagerPersonnel;
    delete bdManagerPlanification;

    // Delete List
    qDeleteAll(listAllPersonnel);
    qDeleteAll(listSpecificPersonnel);

    delete client;
}

void DialogClient::initRessources()
{
    listAllPersonnel = bdManagerPersonnel->selectAllPersonnel();

    QListWidgetItem * pItem = 0;
    for (int boucle = 0; boucle < listAllPersonnel.size(); ++boucle)
    {
        ui->lwRessources->addItem(listAllPersonnel.at(boucle)->getNom());
        pItem = ui->lwRessources->item(boucle);
        pItem->setFlags(pItem->flags() | Qt::ItemIsUserCheckable);
        pItem->setCheckState(Qt::Unchecked);
    }
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

    if (ui->leCp->text().size() != 5){
        ui->leCp->setStyleSheet(ssRedBorder);
        leacceptable=false;
    }else ui->leCp->setStyleSheet("");

    if (!(ui->leTel->text().isEmpty())&&!(ui->leTel->hasAcceptableInput())){
        ui->leTel->setStyleSheet(ssRedBorder);
        leacceptable=false;
    }else ui->leTel->setStyleSheet("");

    for(int boucle=0;boucle<ui->lwRessources->count(); ++boucle)
    {
        QListWidgetItem* item = ui->lwRessources->item(boucle);
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
    bool newRdv = true, removeRdv = false;
    int idClientAdded = 0;

    if (create)
    {
        this->client = new Client();
    }

    this->client->setNom(ui->leNom->text());
    this->client->setPrenom(ui->lePrenom->text());
    this->client->setAdress(ui->leAdresse->text());
    this->client->setVille(ui->leVille->text());
    this->client->setCp(ui->leCp->text());
    this->client->setComentaires(ui->teCommentaires->toPlainText());
    this->client->setNumTel(ui->leTel->text().toInt());
    this->client->setJourPassge(ui->deJourRdv->date());
    this->client->setDureeEstime(ui->sbDuree->value());
    this->client->setPriorite(ui->sbPriorite->value());

    if (create)
    {
        idClientAdded = bdManagerClient->addClient(client); // Add the client to the database

        // Create each RDV. Depend on personnel selected
        for (int boucle = 0; boucle < ui->lwRessources->count(); ++boucle)
            if (ui->lwRessources->item(boucle)->checkState())
                bdManagerPlanification->createRdv(new Rdv(idClientAdded, listAllPersonnel.at(boucle)->getId()));

        emit(changeStatus("Client ajouté"));
    }
    else
    {
        bdManagerClient->modifyClient(client); // Modify the client to the database

        listSpecificPersonnel = bdManagerPersonnel->selectPersonnelSpecificClient(client->getId()); // All personnel linked to the client (old version)

        for (int numRowRessource = 0; numRowRessource < ui->lwRessources->count(); ++numRowRessource)
        {
            if (ui->lwRessources->item(numRowRessource)->checkState()) // Checked
            {
                for (int indexList = 0; indexList < listSpecificPersonnel.size(); ++indexList) // Make difference between own list and item checked.
                    if (*(listSpecificPersonnel.at(indexList)) == *(listAllPersonnel.at(numRowRessource)))
                        newRdv = false;

                if (newRdv)
                    bdManagerPlanification->createRdv(new Rdv(client->getId(), listAllPersonnel.at(numRowRessource)->getId())); // new item checked so add rdv

                newRdv = true;
            }
            else
            {
                for (int indexList = 0; indexList < listSpecificPersonnel.size(); ++indexList) // Make difference between own list and item checked.
                    if (*(listSpecificPersonnel.at(indexList)) == *(listAllPersonnel.at(numRowRessource)))
                        removeRdv = true;

                if (removeRdv)
                {
                    bdManagerPlanification->removeRdv(client, listAllPersonnel.at(numRowRessource)); // Item unchecked so remove rdv
                    removeRdv = false;
                }
            }
        }
    }
}

void DialogClient::setClient(Client * client)
{
    ui->leNom->setText(client->getNom());
    ui->lePrenom->setText(client->getPrenom());
    ui->leAdresse->setText(client->getAdresse());
    ui->leVille->setText(client->getVille());
    ui->leCp->setText(QString::number(client->getCp()));
    ui->teCommentaires->setText(client->getCommentaires());

    if (client->getnumTel()!=0){
        ui->leTel->setText("0"+QString::number(client->getnumTel()));
    }

    ui->deJourRdv->setDate(client->getJourPassage());
    ui->sbDuree->setValue(client->getDureeEstime());
    ui->sbPriorite->setValue(client->getPriorite());

    this->client = client; // Keep an instance of the current client


    // Check personnel checkbox associated to the client
    listSpecificPersonnel = bdManagerPersonnel->selectPersonnelSpecificClient(this->client->getId());

    for (int loopSpecific = 0; loopSpecific < listSpecificPersonnel.size(); ++loopSpecific)
        for (int loopAll = 0; loopAll < listAllPersonnel.size(); ++loopAll)
            if (listAllPersonnel.at(loopAll)->getId() == listSpecificPersonnel.at(loopSpecific)->getId())
                ui->lwRessources->item(loopAll)->setCheckState(Qt::Checked);
}
