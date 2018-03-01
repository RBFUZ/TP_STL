#ifndef DIALOGPERSONNEL_H
#define DIALOGPERSONNEL_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlQuery>

namespace Ui {
class DialogPersonnel;
}

class DialogPersonnel : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPersonnel(QWidget *parent = 0);
    ~DialogPersonnel();

private slots:
    void on_btnOk_clicked();
    void on_cbType_activated(const QString &arg1);

private:
    Ui::DialogPersonnel *ui;
    void initType();
    void personnelIsValid();
};

#endif // DIALOGPERSONNEL_H
