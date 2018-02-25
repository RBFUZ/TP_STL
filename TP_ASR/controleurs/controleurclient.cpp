#include "controleurclient.h"
#include <QString>
#include <QLineEdit>
#include <QDebug>
#include "modeles/client.h"

#define NAMECPOBJECT "leCp"
#define NAMETELOBJECT "leTel"
#define NBSPACEPHONE 4
#define CHECKSTATERESSOURCES 2

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
