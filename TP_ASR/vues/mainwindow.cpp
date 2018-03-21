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

    connect(ui->tabClient, SIGNAL(changeStatus(QString)), this, SLOT(setStatus(QString))); // For status bar
    connect(ui->tabPersonnel, SIGNAL(changeStatus(QString)), this, SLOT(setStatus(QString))); // For status bar
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
    DialogClient * dlgClient = new DialogClient();
    connect(dlgClient, SIGNAL(changeStatus(QString)), this, SLOT(setStatus(QString))); // For status bar
    dlgClient->exec();
    ui->tabClient->initClient(); // Refresh the view to display new information

    delete dlgClient;
}

void MainWindow::on_actionPersonnel_triggered()
{
    DialogPersonnel * dlgPersonnel = new DialogPersonnel();
    connect(dlgPersonnel, SIGNAL(changeStatus(QString)), this, SLOT(setStatus(QString))); // For status bar
    dlgPersonnel->exec();
    ui->tabPersonnel->initPersonnel(); // Refresh the view to display new information

    delete dlgPersonnel;
}

void MainWindow::setStatus(QString message)
{
    ui->statusBar->showMessage(message);
}
