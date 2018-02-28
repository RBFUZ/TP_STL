#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogclient.h"
#include "dialogpersonnel.h"
#include "dialogapropos.h"
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Init status bar
    ui->statusBar->showMessage("Connecté !");

    //Init Date
    ui->deRendezvousDebut->setMinimumDate(QDate::currentDate());
    ui->deRendezvousFin->setMinimumDate(QDate::currentDate().addDays(1));

    //model = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionA_propos_triggered()
{
    DialogAPropos dlgAPropos;
    dlgAPropos.exec();
}

void MainWindow::on_actionClient_triggered()
{

    DialogClient dlgClient;
    dlgClient.exec();
}

void MainWindow::on_actionPersonnel_triggered()
{
    DialogPersonnel dlgPersonnel;
    dlgPersonnel.exec();
}

void MainWindow::on_btnRechercherclient_clicked()
{
    model = BDManager::searchClient(ui->leNom, ui->lePrenom, ui->leIdentifiant, ui->deRendezvousDebut, ui->deRendezvousFin);

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // Not allow user to edit cell

    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->hideColumn(9);
    ui->tableView->hideColumn(10);

    // Add two columns (modification, suppression)
    model->insertColumns(11, 2);
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Modification"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("Suppression"));

    // Add labels for each rows
    for (int i = 0; i < model->rowCount(); i++)
    {
        ui->tableView->setIndexWidget(model->index(i,11), new QLabel("<font color='red'>Modifier</font>")); // Add label to the cell modification
        ui->tableView->setIndexWidget(model->index(i,12), new QLabel("<font color='red'>Supprimer</font>")); // Add label to the cell suppression
    }
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    if (index.column() == 11 || index.column() == 12)
    {
        if (index.column() == 11)
        {
            Client * client = new Client();
            client->setNom(model->index(index.row(), 1).data().toString());
            client->setPreom(model->index(index.row(), 2).data().toString());
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
            dialogClient.setIdClient(model->index(index.row(), 0).data().toInt()); // We need id to know which client must be modified
            dialogClient.setClient(client);
            dialogClient.exec();
        }
        else
        {
            // SUPPRESSION
        }

        // Refresh tableView
        model->selectRow(index.row());
    }
}
