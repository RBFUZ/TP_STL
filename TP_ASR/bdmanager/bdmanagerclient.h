#ifndef BDMANAGERCLIENT_H
#define BDMANAGERCLIENT_H

#include "modeles/client.h"
#include "modeles/personnel.h"
#include "modeles/compte.h"
#include "modeles/rdv.h"
#include "modeles/type.h"
#include "bdmanager/bdmanager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QLineEdit>
#include <QDateEdit>
#include <QSqlRecord>

class BDManagerClient
{
public:
    BDManagerClient();

    int addClient(Client * client);
    void modifyClient(Client * client);
    QSqlTableModel * searchClient(QLineEdit * leNom, QLineEdit * lePrenom, QLineEdit * leIdentifiant, QDateEdit * deDebut, QDateEdit * deFin);
    QSqlTableModel * selectAllClient();

private:
    void bindValue(QSqlQuery * query, Client * client); // Bind client value to the query

    static QSqlDatabase db;
    QSqlQuery * query;
    QSqlQueryModel * model;
};

#endif // BDMANAGERCLIENT_H
