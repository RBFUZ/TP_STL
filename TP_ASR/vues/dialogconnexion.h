#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include "bdmanager/bdmanagerpersonnel.h"
#include <QDialog>

namespace Ui {
class DialogConnexion;
}

class DialogConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConnexion(QWidget *parent = 0);
    ~DialogConnexion();

private slots:
    void on_btnConnecter_clicked();
    void on_btnAnnuler_clicked();

private:
    Ui::DialogConnexion * ui;
    BDManagerPersonnel * bdManagerPersonnel;
};

#endif // DIALOGCONNEXION_H
