#include "dialogclient.h"
#include "ui_dialogclient.h"
#include "controleurs/controleurclient.h"

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

    ControleurClient * controleurClient = new ControleurClient();
    connect(this,SIGNAL(verifyClientInfo(QList<QLineEdit*>,
                                          QTextEdit *,
                                          QDateEdit *,
                                          QList<QSpinBox*>,
                                          QListWidget *)), controleurClient, SLOT(verifyClientInfo(QList<QLineEdit*>,
                                                                                                   QTextEdit *,
                                                                                                   QDateEdit *,
                                                                                                   QList<QSpinBox*>,
                                                                                                   QListWidget *)));
    connect(controleurClient, SIGNAL(clientOK()), this, SLOT(clientOk()));
}

DialogClient::~DialogClient()
{
    delete ui;
}

void DialogClient::on_btnOk_clicked()
{
    QList<QSpinBox *> listSB;
    listSB.append(ui->sbDuree);
    listSB.append(ui->sbPriorite);

    emit verifyClientInfo(this->findChildren<QLineEdit *>(), ui->teCommentaires, ui->deJourRdv, listSB, ui->lwRessources);
}

void DialogClient::clientOk()
{
    accept();
}
