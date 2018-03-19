#ifndef DIALOGPERSONNEL_H
#define DIALOGPERSONNEL_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "modeles/personnel.h"
#include "bdmanager/bdmanagerpersonnel.h"

namespace Ui {
class DialogPersonnel;
}

class DialogPersonnel : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPersonnel(QWidget *parent = 0);
    ~DialogPersonnel();
    void setPersonnel(Personnel * personnel);

    // Getters and Setters
    int getCreate() { return create; }
    void setCreate(bool value) { this->create = value; }

private slots:
    void on_btnOk_clicked();
    void on_cbType_activated(const QString &arg1);

    void on_btnAnnuler_clicked();

private:
    Ui::DialogPersonnel *ui;

    BDManagerPersonnel * bdManagerPersonnel;

    Personnel * personnel;

    bool create;
    QSqlQueryModel * model;

    void initType();
    void personnelIsValid();

signals:
    void changeStatus(QString message);
};

#endif // DIALOGPERSONNEL_H
