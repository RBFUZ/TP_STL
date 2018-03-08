#ifndef BDMANAGER_H
#define BDMANAGER_H

#include "modeles/client.h"
#include "modeles/personnel.h"
#include "modeles/compte.h"
#include "modeles/rdv.h"
#include "modeles/type.h"

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

    int addClient(Client * client);
    void modifyClient(Client * client);
    QSqlTableModel * searchClient(QLineEdit * leNom, QLineEdit * lePrenom, QLineEdit * leIdentifiant, QDateEdit * deDebut, QDateEdit * deFin);

    int addPersonnel(Personnel * personnel);
    void modifyPersonnel(Personnel * personnel);
    void removePersonnel(int idPersonnel);
    QList<Personnel *> selectAllPersonnel();
    QList<Personnel *> selectPersonnelSpecificType(int idType);
    Personnel * selectPersonnelSpecificId(int idPersonnel);
    QList<Personnel *> convertSqlToPersonnel(QSqlQueryModel *model);
    bool isInformaticien(int idPersonnel);

    QSqlQueryModel * selectAllType();
    QString selectTypeSpecificId(int id);

    void addCompte(Compte * compte);
    void removeCompte(int idPersonnel);
    Compte *selectCompteSpecificIdPersonnel(int idPersonnel);

    void createRdv(Rdv *rdv);
    QList<Personnel *> selectPersonnelSpecificClient(int idClient);


private:
    void bindValue(QSqlQuery * query, Client * client); // Bind client value to the query
    QSqlQuery * query;
    QSqlQueryModel * model;
};

#endif // BDMANAGER_H
