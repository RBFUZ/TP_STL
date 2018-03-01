#ifndef BDMANAGER_H
#define BDMANAGER_H

#include "modeles/client.h"
#include "modeles/personnel.h"
#include "modeles/compte.h"
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
    static int addPersonnel(Personnel * personnel);
    static QSqlQueryModel * selectAllType();
    static QSqlQueryModel * selectPersonnelSpecificType(int idType);
    static void addCompte(Compte * compte);

private:
    static void bindValue(QSqlQuery * query, Client * client); // Bind client value to the query
};

#endif // BDMANAGER_H
