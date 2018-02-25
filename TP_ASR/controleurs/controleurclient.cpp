#include "controleurclient.h"
#include <QString>
#include <QLineEdit>
#include <QDebug>
#include "modeles/client.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>


#define NAMECPOBJECT "leCp"
#define NAMETELOBJECT "leTel"
#define NBSPACEPHONE 4
#define CHECKSTATERESSOURCES 2
#define CONNECTIONNAME "Reservation"

ControleurClient::ControleurClient() {

}

void ControleurClient::verifyClientInfo(QList<QLineEdit*> listLineEdit, QTextEdit * teCommentaire, QDateEdit * deJourRdv, QList<QSpinBox*> sbDureePriorite, QListWidget * lwRessources) {
    bool leCompleted =true; //line edit all filled
    bool lwCompleted =false; //at least on resources (listWidget) checked
    bool leacceptable=true; //format respected for tel and cp

    QString ssRedBorder="border: 2px solid red"; //stle for red border

    foreach (QLineEdit * line, listLineEdit) { // Change border color to red if field empty or not correct

        if (line->objectName().compare(NAMECPOBJECT) == 0) { // Check postal code
            if (!line->hasAcceptableInput()) {
                line->setStyleSheet(ssRedBorder);
                leacceptable=false;
            }
            else
                line->setStyleSheet("");
        }
        else if (line->objectName().compare(NAMETELOBJECT) == 0) { // Check phone number
            if (line->text().length() > NBSPACEPHONE && !line->hasAcceptableInput()) {
                line->setStyleSheet(ssRedBorder);
                leacceptable=false;
            }
            else
                line->setStyleSheet("");
        }
        else { // Other line edit
            if (line->text().isEmpty() ) {//True for all empty field
                line->setStyleSheet(ssRedBorder);
                leCompleted = false;
            }
            else
                line->setStyleSheet("");//remove an anterior red border
        }
    }

    for(int i=0;i<lwRessources->count(); ++i) {
        QListWidgetItem* item = lwRessources->item(i);
        if (item->checkState() == CHECKSTATERESSOURCES)
            lwCompleted=true;
    }

    if (!lwCompleted)lwRessources->setStyleSheet(ssRedBorder);//red border if no resources selected
        else lwRessources->setStyleSheet("");

    if (leCompleted && lwCompleted && leacceptable) {
        createNewPatient(listLineEdit, teCommentaire, deJourRdv, sbDureePriorite, lwRessources);
        emit clientOK(); // Signal sent to dialogClient to accept() dialog
    }
}

void ControleurClient::createNewPatient(QList<QLineEdit*> listLineEdit, QTextEdit * teCommentaire, QDateEdit * deJourRdv, QList<QSpinBox*> sbDureePriorite, QListWidget * lwRessources) {
    /*QVector<QString> * ressources= new QVector<QString>;

    QListWidgetItem* pItem=0;
    for(int i = 0; i < lwRessources->count(); ++i){
        pItem = lwRessources->item(i);
        if (pItem->checkState()==2)
            ressources->append(pItem->text());
    }*/

    Client client(
        listLineEdit.at(0)->text(),
        listLineEdit.at(1)->text(),
        listLineEdit.at(2)->text(),
        listLineEdit.at(3)->text(),
        listLineEdit.at(4)->text(),
        teCommentaire->toPlainText(),
        listLineEdit.at(5)->text(),
        deJourRdv->date(),
        sbDureePriorite.at(0)->value(),
        sbDureePriorite.at(1)->value());

   client.addDatabase();
}

void ControleurClient::searchClient(QList<QLineEdit *> listLineEdit, QList<QDateEdit *> listDateEdit, QTableView * tableView)
{
    QString nom = listLineEdit.at(0)->text(), prenom = listLineEdit.at(1)->text(), identifiant = listLineEdit.at(2)->text();
    QSqlDatabase db = QSqlDatabase::database(CONNECTIONNAME);
    QSqlTableModel * model = new QSqlTableModel(NULL, db);
    model->setTable("TClient");
    model->select();

    if (nom.length() != 0) // Add % if not empty
        nom = nom.append('%');
    if (prenom.length() != 0) // Add % if not empty
        prenom = prenom.append('%');
    if (identifiant.length() == 0) // Set to 0 because problem if the string is empty
        identifiant = "0";

    // setFilter is equivalent to WHERE clause in SQL
    model->setFilter(QString("id = "+ identifiant +
                             " OR nom LIKE '"+ nom +
                             "' OR prenom LIKE '"+ prenom +
                             "' OR dateRdv between '"+ listDateEdit.at(0)->text() +"' and '"+ listDateEdit.at(1)->text() +"'"));

    tableView->setModel(model);
    tableView->hideColumn(3);
    tableView->hideColumn(4);
    tableView->hideColumn(5);
    tableView->hideColumn(6);
    tableView->hideColumn(7);
    tableView->hideColumn(9);
    tableView->hideColumn(10);
}
