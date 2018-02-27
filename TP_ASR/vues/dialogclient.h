#ifndef DIALOGCLIENT_H
#define DIALOGCLIENT_H

#include <QDialog>
#include "modeles/client.h"
#include <QListWidget>
#include <QDateEdit>
#include <QTextEdit>
#include <QSpinBox>

namespace Ui {
class DialogClient;
}

class DialogClient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClient(QWidget *parent = 0);
    ~DialogClient();
    void createNewPatient();

private slots:
    void on_btnOk_clicked();

private:
    Ui::DialogClient *ui;
};

#endif // DIALOGCLIENT_H
