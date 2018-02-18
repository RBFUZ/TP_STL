#include "dialogclient.h"
#include "ui_dialogclient.h"

DialogClient::DialogClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClient)
{
    ui->setupUi(this);

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

void DialogClient::createNewPatient(){
    Patient patient1(
                ui->leNom->text(),
                ui->lePrenom->text(),
                ui->leAdresse->text(),
                ui->leVille->text(),
                ui->leCp->text(),
                ui->leTel->text(),
                ui->deJourRdv->date(),
                ui->sbDuree->value(),
                ui->sbPriorite->value(),
                Q_NULLPTR,
                ui->teCommentaires->toPlainText());

    /*qDebug()<<"New client created :"
         <<"\n Nom : "<<ui->leNom->text()
         <<"\n Prenom : "<<ui->lePrenom->text()
         <<"\n Adresse : "<<ui->leAdresse->text()
         <<"\n Ville : "<<ui->leVille->text()
         <<"\n CP : "<<ui->leCp->text()
         <<"\n Tel : "<<ui->leTel->text()
         <<"\n Date : "<<ui->deJourRdv->date()
         <<"\n Duree : "<<ui->sbDuree->value()
         <<"\n Priorite : "<<ui->sbPriorite->value()
         <<"\n Ressources : "<<Q_NULLPTR
         <<"\n Commentaires : "<<ui->teCommentaires->toPlainText();*/
    patient1.display();
}

void DialogClient::on_btnOk_clicked()
{
    bool leCompleted =true; //line edit all filled
    bool lwCompleted =false; //at least on resources (listWidget) checked
    bool leacceptable=true; //format respected for tel and cp

    QList<QLineEdit *> list=this->findChildren<QLineEdit *>();//get all lineEdit in the form
    list.removeOne(ui->leTel);//remove facultative fields
    QList<QLineEdit *>::iterator i;

    for (i=list.begin();i!=list.end();i++){
        if ((*i)->text().isEmpty() ){//True for all empty field
            (*i)->setStyleSheet("border: 2px solid red");//apply red border
            leCompleted = false;
        }else{
            (*i)->setStyleSheet("");//remove an anterior red border
        };
    }

    if (!ui->leCp->hasAcceptableInput()){
        ui->leCp->setStyleSheet("border: 2px solid red");
        leacceptable=false;
    }else ui->leCp->setStyleSheet("");
    if (!(ui->leTel->text().isEmpty())&&!(ui->leTel->hasAcceptableInput())){
        ui->leTel->setStyleSheet("border: 2px solid red");
        leacceptable=false;
    }else ui->leTel->setStyleSheet("");

    for(int i=0;i<ui->lwRessources->count(); ++i)
    {
        QListWidgetItem* item = ui->lwRessources->item(i);
        if (item->checkState()==2)//true for checked ressources
            lwCompleted=true;
    }
    if (!lwCompleted)ui->lwRessources->setStyleSheet("border: 2px solid red");//red border if no resources selected
            else ui->lwRessources->setStyleSheet("");

    if (leCompleted && lwCompleted && leacceptable){
        createNewPatient();
        accept();
     }
    else ui->lblObligatoire->setStyleSheet("color:red");
}

