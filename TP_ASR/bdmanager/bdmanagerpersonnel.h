#ifndef BDMANAGERPERSONNEL_H
#define BDMANAGERPERSONNEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "modeles/personnel.h"
#include "modeles/compte.h"
#include "bdmanager/bdmanager.h"

class BDManagerPersonnel
{
public:
    BDManagerPersonnel();

    int addPersonnel(Personnel * personnel);
    void modifyPersonnel(Personnel * personnel);
    void removePersonnel(int idPersonnel);
    QList<Personnel *> selectAllPersonnel();
    QList<Personnel *> selectPersonnelSpecificType(int idType);
    Personnel * selectPersonnelSpecificId(int idPersonnel);
    QList<Personnel *> selectPersonnelSpecificClient(int idClient);
    QList<Personnel *> convertSqlToPersonnel(QSqlQuery *model);
    bool isInformaticien(int idPersonnel);

    QSqlQueryModel * selectAllType();
    QString selectTypeSpecificId(int id);

    void addCompte(Compte * compte);
    void removeCompte(int idPersonnel);
    Compte * selectCompteSpecificIdPersonnel(int idPersonnel);
    bool verifyConnection(QString login, QString password);

private:
    static QSqlDatabase * db;
    QSqlQuery * query;
    QSqlQueryModel * model;
};

#endif // BDMANAGERPERSONNEL_H
