#ifndef DIALOGPERSONNEL_H
#define DIALOGPERSONNEL_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "modeles/personnel.h"

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
    int getIdPersonnel() { return idPersonnel; }
    void setIdPersonnel(int idPersonnel) { this->idPersonnel = idPersonnel; }
    int getCreate() { return create; }
    void setCreate(bool value) { this->create = value; }

private slots:
    void on_btnOk_clicked();
    void on_cbType_activated(const QString &arg1);

private:
    Ui::DialogPersonnel *ui;
    int idPersonnel;
    void initType();
    void personnelIsValid();
    bool create;
};

#endif // DIALOGPERSONNEL_H
