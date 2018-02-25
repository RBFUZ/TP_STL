#ifndef CONTROLEURCLIENT_H
#define CONTROLEURCLIENT_H

#include <QObject>
#include <QListWidget>
#include <QDateEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QTableView>

class ControleurClient : public QObject
{
    Q_OBJECT

public:
    ControleurClient();

signals:
    void clientOK(); // Sent to dialogClient if client information OK

private slots:
    // Signal emitted by dialogClient to verify if information is OK
    void verifyClientInfo(QList<QLineEdit*> listLineEdit, QTextEdit * teCommentaire, QDateEdit * deJourRdv, QList<QSpinBox*> sbDureePriorite, QListWidget * lwRessources);

    // // Signal emitted by mainWindow to recover information about client searched
    void searchClient(QList<QLineEdit *> listLineEdit, QList<QDateEdit *> listDateEdit, QTableView * tableView);

private:
    void createNewPatient(QList<QLineEdit*> listLineEdit, QTextEdit * teCommentaire, QDateEdit * deJourRdv, QList<QSpinBox*> sbDureePriorite, QListWidget * lwRessources);

};

#endif // CONTROLEURCLIENT_H
