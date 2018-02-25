#include "dialogconnexion.h"
#include "ui_dialogconnexion.h"
#include <QMessageBox>

DialogConnexion::DialogConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnexion)
{
    ui->setupUi(this);
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
}

// Vérification du login et de mot de passe
bool DialogConnexion::verifyConnexion(QString qsLogin, QString qsMotdepasse)
{
    if (qsLogin.compare("a") == 0 && qsMotdepasse.compare("a") == 0)
        return true;
    else
        return false;
}

// Vérification du login et du mot de passe
void DialogConnexion::on_btnConnecter_clicked()
{
    if (verifyConnexion(ui->leLogin->text(), ui->leMotdepasse->text()))
    {
        accept();
    }
    else
    {
        QMessageBox mbIncorrectLogin;
        mbIncorrectLogin.setText("Login ou mot de passe incorrecte !");
        mbIncorrectLogin.setWindowTitle("Erreur d'indentification");
        mbIncorrectLogin.exec();
        ui->leMotdepasse->clear();
    }
}

// Femeture de l'application quand clique sur annuler
void DialogConnexion::on_btnAnnuler_clicked()
{
    reject();
}
