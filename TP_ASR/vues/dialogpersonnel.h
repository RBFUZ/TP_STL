#ifndef DIALOGPERSONNEL_H
#define DIALOGPERSONNEL_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "modeles/personnel.h"
#include "bdmanager.h"

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

private:
    Ui::DialogPersonnel *ui;
    BDManager * bdManager;
    Personnel * personnel;
    void initType();
    void personnelIsValid();
    bool create;
};

#endif // DIALOGPERSONNEL_H
