#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogclient.h"
#include "dialogpersonnel.h"
#include "dialogapropos.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QSqlRecord>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bdManager = new BDManager();
    model = NULL;

    // Init status bar
    ui->statusBar->showMessage("Connecté !");

    //Init Date
    ui->deRendezvousDebut->setMinimumDate(QDate::currentDate());
    ui->deRendezvousFin->setMinimumDate(QDate::currentDate().addDays(1));

    // Fill TreeView (personnel)
    initPersonnel();
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
    model = bdManager->searchClient(ui->leNom, ui->lePrenom, ui->leIdentifiant, ui->deRendezvousDebut, ui->deRendezvousFin);

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // Not allow user to edit cell

    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->hideColumn(9);
    ui->tableView->hideColumn(10);

    addModifAndRemoveOption();
}

void MainWindow::addModifAndRemoveOption()
{
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
            client->setId(model->index(index.row(), 0).data().toInt()); // We need id to know which client must be modified or removed
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
            dialogClient.setClient(client);
            dialogClient.exec();

            // Refresh tableView
            model->selectRow(index.row());
        }
        else
        {
            model->removeRow(index.row());
            model->submitAll(); // Push modification to the database
            model->select(); // Refresh entries
            addModifAndRemoveOption();
        }
    }
}

void MainWindow::initPersonnel()
{
    QSqlQueryModel * listType = bdManager->selectAllType();
    vector<Personnel *> listPersonnel;

    QStandardItemModel * allItem = new QStandardItemModel(listType->rowCount(), 1); //  Contains all items

    for (int nodeNumber = 0; nodeNumber < listType->rowCount(); ++nodeNumber) // Iteration on each node
    {
        QStandardItem * item = new QStandardItem(listType->record(nodeNumber).value(1).toString()); // Node
        listPersonnel = bdManager->selectPersonnelSpecificType(listType->record(nodeNumber).value(0).toInt()); // Get all personnel of type item defined line above

        for (size_t childNumber = 0; childNumber < listPersonnel.size(); childNumber++) // Iteration on each child of one node
        {
            QStandardItem * child = new QStandardItem(QString::number(listPersonnel.at(childNumber)->getId()) + " " + listPersonnel.at(childNumber)->getNom()); // Child of one node
            item->appendRow(child); // Add child to the current node
        }
        allItem->setItem(nodeNumber, item); // Add the current node to the tree
    }

    ui->treeView->setModel(allItem);
    ui->treeView->show();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers); // Disable edit mode
    allItem->setHeaderData(0, Qt::Horizontal, "", Qt::DisplayRole); // Set empty title to the column because print "1" by default
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    if (index.parent().data().toString().compare("") != 0) // Check if child or node. If != child else node.
    {
        // Change properties of buttons
        ui->btnModifier->setEnabled(true);
        ui->btnSupprimer->setEnabled(true);
    }
    else
    {
        ui->btnModifier->setEnabled(false);
        ui->btnSupprimer->setEnabled(false);
    }
}

void MainWindow::on_btnModifier_clicked()
{
    QItemSelectionModel * model = ui->treeView->selectionModel();
    QModelIndex index = model->currentIndex();
    qDebug() << index.row();
    QString idPersonnel = index.data().toString().split(" ").at(0); // Recover the id of the personnel selected
    Personnel * personnel = bdManager->selectPersonnelSpecificId(idPersonnel.toInt()); // Recover the personnel selected

    DialogPersonnel dialogPersonnel;
    dialogPersonnel.setCreate(false); // Set to modification mode
    dialogPersonnel.setPersonnel(personnel);
    dialogPersonnel.exec();

    initPersonnel(); // Peut être à revoir ?? Regénération de toute la liste juste pour une modification ?? Code complexe pour ne rafraichir que la ligne modifier.
}

void MainWindow::on_btnSupprimer_clicked()
{
    QItemSelectionModel * model = ui->treeView->selectionModel();
    QModelIndex index = model->currentIndex();
    QString idPersonnel = index.data().toString().split(" ").at(0); // Recover the id of the personnel selected

    if (bdManager->isInformaticien(idPersonnel.toInt()))
    {
        bdManager->removeCompte(idPersonnel.toInt());
    }

    bdManager->removePersonnel(idPersonnel.toInt());

    initPersonnel(); // Peut être à revoir ?? Regénération de toute la liste juste pour une modification ?? Code complexe pour ne rafraichir que la ligne modifier.
}
