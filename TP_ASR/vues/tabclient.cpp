#include "tabclient.h"
#include "ui_tabclient.h"
#include "vues/dialogclient.h"
#include <QSortFilterProxyModel>

TabClient::TabClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabClient)
{
    ui->setupUi(this);

    // Init BD connexion
    bdManagerClient = new BDManagerClient();

    //Init Date
    ui->deRendezvousDebut->setMinimumDate(QDate::currentDate());
    ui->deRendezvousFin->setMinimumDate(QDate::currentDate().addDays(1));

    ui->lePrenom->setPlaceholderText("son prénom");

    model = NULL;

    // Fill TableView (client)
    initClient();
}

TabClient::~TabClient()
{
    delete ui;
    delete bdManagerClient;
    delete model;
}

void TabClient::on_btnRechercherclient_clicked()
{
    if (model != NULL)
        delete model; // Free old model

    model = bdManagerClient->searchClient(ui->leNom, ui->lePrenom, ui->leIdentifiant, ui->deRendezvousDebut, ui->deRendezvousFin);

    setPropertyTableView();
    addModifAndRemoveOption();
}

void TabClient::setPropertyTableView()
{
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // Not allow user to edit cell

    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->hideColumn(9);
    ui->tableView->hideColumn(10);
}

void TabClient::addModifAndRemoveOption()
{
    // Add two columns (modification, suppression)
    model->insertColumns(11, 2);
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Modification"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("Suppression"));

    // Add labels for each rows
    for (int indexRow = 0; indexRow < model->rowCount(); indexRow++)
    {
        ui->tableView->setIndexWidget(model->index(indexRow,11), new QLabel("<font color='red'>Modifier</font>")); // Add label to the cell modification
        ui->tableView->setIndexWidget(model->index(indexRow,12), new QLabel("<font color='red'>Supprimer</font>")); // Add label to the cell suppression
    }
}

void TabClient::on_tableView_activated(const QModelIndex &index)
{
    if (index.column() == 11 || index.column() == 12)
    {
        if (index.column() == 11)
        {
            Client * client = new Client();
            client->setId(model->index(index.row(), 0).data().toInt());
            client->setNom(model->index(index.row(), 1).data().toString());
            client->setPrenom(model->index(index.row(), 2).data().toString());
            client->setAdress(model->index(index.row(), 3).data().toString());
            client->setVille(model->index(index.row(), 4).data().toString());
            client->setCp(model->index(index.row(), 5).data().toString());
            client->setComentaires(model->index(index.row(), 6).data().toString());
            client->setNumTel(model->index(index.row(), 7).data().toInt());
            client->setJourPassge(QDate::fromString(model->index(index.row(), 8).data().toString(), "yyyy-MM-dd"));
            client->setDureeEstime(model->index(index.row(), 9).data().toInt());
            client->setPriorite(model->index(index.row(), 10).data().toInt());

            DialogClient dialogClient;
            dialogClient.setCreate(false); // Change mode of dialogClient because we need to modify the client and not add an other.
            dialogClient.setClient(client); // Print information to the dialogClient
            dialogClient.exec();

            // Refresh tableView
            model->selectRow(index.row());
            emit(changeStatus("Client modifié"));

            delete client;
        }
        else
        {
            model->removeRow(index.row());
            model->submitAll(); // Push modification to the database
            model->select(); // Refresh entries
            addModifAndRemoveOption();
            emit(changeStatus("Client supprimé"));
        }
    }
}

void TabClient::initClient()
{
    if (model != NULL)
        delete model; // Free old model

    model = bdManagerClient->selectAllClient();
    setPropertyTableView();
    addModifAndRemoveOption();

    // Reset all search fields
    ui->leIdentifiant->setText("");
    ui->leNom->setText("");
    ui->lePrenom->setText("");
    ui->deRendezvousDebut->setDate(QDate::currentDate());
    ui->deRendezvousFin->setDate(QDate::currentDate().addDays(1));
}
