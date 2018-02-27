#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogclient.h"
#include "dialogpersonnel.h"
#include "dialogapropos.h"

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
    QSqlTableModel * model = BDManager::searchClient(ui->leNom, ui->lePrenom, ui->leIdentifiant, ui->deRendezvousDebut, ui->deRendezvousFin);

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->hideColumn(9);
    ui->tableView->hideColumn(10);

    // Add new column with actions buttons
    /*model->insertColumn(11);
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Actions"));
    QPushButton * modifier = new QPushButton("Modifier");
    QPushButton * supprimer = new QPushButton("Supprimer");
    tableView->setIndexWidget(model->index(1,11), modifier);
    tableView->setIndexWidget(model->index(1,11), supprimer);*/
}
