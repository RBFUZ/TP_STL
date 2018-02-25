#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogclient.h"
#include "dialogpersonnel.h"
#include "dialogapropos.h"
#include "c_init_bd.h"
#include "controleurs/controleurclient.h"

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

    ControleurClient * controleurClient = new ControleurClient();
    connect(this, SIGNAL(searchClient(QList<QLineEdit *>, QList<QDateEdit *>, QTableView *)), controleurClient, SLOT(searchClient(QList<QLineEdit *>, QList<QDateEdit *>, QTableView *)));
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
    QList<QLineEdit *> listLineEdit;
    listLineEdit.append(ui->leNom);
    listLineEdit.append(ui->lePrenom);
    listLineEdit.append(ui->leIdentifiant);

    QList<QDateEdit *> listDateEdit;
    listDateEdit.append(ui->deRendezvousDebut);
    listDateEdit.append(ui->deRendezvousFin);

    emit searchClient(listLineEdit, listDateEdit, ui->tableView);
}
