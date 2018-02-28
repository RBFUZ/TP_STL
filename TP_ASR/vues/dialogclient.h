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
    void clientIsValid();
    void setClient(Client * client);

    // Getters / Setters
    bool getCreate() {return create;}
    void setCreate(bool statut) {create = statut;}
    int getIdClient() { return idClient; }
    void setIdClient(int idClient) {this->idClient = idClient; }

private slots:
    void on_btnOk_clicked();

private:
    Ui::DialogClient *ui;
    bool create;
    int idClient; // Necessary for modifying client. Know which client must be modified
};

#endif // DIALOGCLIENT_H
