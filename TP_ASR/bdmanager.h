#ifndef BDMANAGER_H
#define BDMANAGER_H

#include "modeles/client.h"
#include "modeles/personnel.h"
#include "modeles/compte.h"
#include "modeles/rdv.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QLineEdit>
#include <QDateEdit>
#include <QSqlRecord>

class BDManager
{
public:
    BDManager();

    static int addClient(Client * client);
    static void modifyClient(Client * client);
    static QSqlTableModel * searchClient(QLineEdit * leNom, QLineEdit * lePrenom, QLineEdit * leIdentifiant, QDateEdit * deDebut, QDateEdit * deFin);

    static int addPersonnel(Personnel * personnel);
    static void modifyPersonnel(Personnel * personnel);
    static void removePersonnel(int idPersonnel);
    static QSqlQueryModel * selectAllPersonnel();
    static QSqlQueryModel * selectPersonnelSpecificType(int idType);
    static QSqlQueryModel * selectPersonnelSpecificId(int id);
    static bool isInformaticien(int idPersonnel);

    static QSqlQueryModel * selectAllType();
    static QString selectTypeSpecificId(int id);

    static void addCompte(Compte * compte);
    static void removeCompte(int idPersonnel);
    static QSqlQueryModel * selectCompteSpecificIdPersonnel(int idPersonnel);

    static void createRdv(Rdv *rdv);


private:
    static void bindValue(QSqlQuery * query, Client * client); // Bind client value to the query
};

#endif // BDMANAGER_H
