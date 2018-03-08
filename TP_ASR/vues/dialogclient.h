#ifndef DIALOGCLIENT_H
#define DIALOGCLIENT_H

#include "modeles/client.h"
#include "bdmanager.h"

#include <QDialog>
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
    void clientIsValid();
    void setClient(Client * client);

    // Getters / Setters
    bool getCreate() {return create;}
    void setCreate(bool statut) {create = statut;}

private slots:
    void on_btnOk_clicked();

private:
    Ui::DialogClient *ui;
    BDManager * bdManager;
    vector<Personnel *> vecPersonnel;
    Client * client;

    bool create;
    void initRessources();
};

#endif // DIALOGCLIENT_H
