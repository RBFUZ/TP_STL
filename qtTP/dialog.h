#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_btnConnecter_clicked();

    void on_btnAnnuler_clicked();

private:
    Ui::Dialog *ui;
    bool verifyIdentification(QString qsLogin, QString qsMotdepasse);
};

#endif // DIALOG_H
