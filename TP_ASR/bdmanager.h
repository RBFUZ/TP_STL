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
    static void modifyClient(Client * client, int idClient);
    static QSqlTableModel * searchClient(QLineEdit * leNom, QLineEdit * lePrenom, QLineEdit * leIdentifiant, QDateEdit * deDebut, QDateEdit * deFin);

private:
    static void bindValue(QSqlQuery * query, Client * client); // Bind client value to the query
};

#endif // BDMANAGER_H
