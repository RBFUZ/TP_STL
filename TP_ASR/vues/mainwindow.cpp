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

    // Init status bar
    ui->statusBar->showMessage("Connecté !");

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
    ui->tabClient->initClient();
}

void MainWindow::on_actionPersonnel_triggered()
{
    DialogPersonnel dlgPersonnel;
    dlgPersonnel.exec();
    initPersonnel();
}

void MainWindow::initPersonnel()
{
    QSqlQueryModel * listType = bdManager->selectAllType();
    QList<Personnel *> listPersonnel;

    QStandardItemModel * allItem = new QStandardItemModel(listType->rowCount(), 1); //  Contains all items

    for (int nodeNumber = 0; nodeNumber < listType->rowCount(); ++nodeNumber) // Iteration on each node
    {
        QStandardItem * item = new QStandardItem(listType->record(nodeNumber).value(1).toString()); // Node
        listPersonnel = bdManager->selectPersonnelSpecificType(listType->record(nodeNumber).value(0).toInt()); // Get all personnel of type item defined line above

        mapPersonnel.insert(listType->record(nodeNumber).value(1).toString(), listPersonnel); // Insert allPersonnel of one type to the map

        for (int childNumber = 0; childNumber < listPersonnel.size(); childNumber++) // Iteration on each child of one node
        {
            QStandardItem * child = new QStandardItem(listPersonnel.at(childNumber)->getNom()); // Child of one node
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

    DialogPersonnel dialogPersonnel;
    dialogPersonnel.setCreate(false); // Set to modification mode
    dialogPersonnel.setPersonnel(mapPersonnel.find(index.parent().data().toString()).value().at(index.row()));
    dialogPersonnel.exec();

    initPersonnel();
}

void MainWindow::on_btnSupprimer_clicked()
{
    QItemSelectionModel * model = ui->treeView->selectionModel();
    QModelIndex index = model->currentIndex();

    int idPersonnel = mapPersonnel.find(index.parent().data().toString()).value().at(index.row())->getId();

    if (bdManager->isInformaticien(idPersonnel))
    {
        bdManager->removeCompte(idPersonnel);
    }

    bdManager->removePersonnel(idPersonnel);

    initPersonnel();
}
