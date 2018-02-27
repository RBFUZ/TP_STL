#ifndef BDMANAGER_H
#define BDMANAGER_H

#include "modeles/client.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QLineEdit>
#include <QDateEdit>

class BDManager
{
public:
    BDManager();
    static void addClient(Client * client);
    static QSqlTableModel * searchClient(QLineEdit * leNom, QLineEdit * lePrenom, QLineEdit * leIdentifiant, QDateEdit * deDebut, QDateEdit * deFin);
};

#endif // BDMANAGER_H
