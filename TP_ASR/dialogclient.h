#ifndef DIALOGCLIENT_H
#define DIALOGCLIENT_H

#include <QDialog>

#include "patient.h"

namespace Ui {
class DialogClient;
}

class DialogClient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClient(QWidget *parent = 0);
    ~DialogClient();

private slots:
    void on_btnOk_clicked();

private:
    Ui::DialogClient *ui;
    void createNewPatient();//for debug only
};

#endif // DIALOGCLIENT_H
