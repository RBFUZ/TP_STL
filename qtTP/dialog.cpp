#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

// Vérification du login et de mot de passe
bool Dialog::verifyIdentification(QString qsLogin, QString qsMotdepasse)
{
    if (qsLogin.compare("a") == 0 && qsMotdepasse.compare("a") == 0)
        return true;
    else
        return false;
}

// Vérification du login et du mot de passe
void Dialog::on_btnConnecter_clicked()
{
    if (verifyIdentification(ui->leLogin->text(), ui->leMotDePasse->text()))
    {
        accept();
    }
    else
    {
        QMessageBox mbIncorrectLogin;
        mbIncorrectLogin.setText("Login ou mot de passe incorrecte !");
        mbIncorrectLogin.exec();
        ui->leMotDePasse->clear();
    }
}

// Femeture de l'application quand clique sur annuler
void Dialog::on_btnAnnuler_clicked()
{
    reject();
}
