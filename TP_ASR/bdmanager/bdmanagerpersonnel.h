#ifndef BDMANAGERPERSONNEL_H
#define BDMANAGERPERSONNEL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "modeles/personnel.h"
#include "modeles/compte.h"

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
    QList<Personnel *> convertSqlToPersonnel(QSqlQueryModel *model);
    bool isInformaticien(int idPersonnel);

    QSqlQueryModel * selectAllType();
    QString selectTypeSpecificId(int id);

    void addCompte(Compte * compte);
    void removeCompte(int idPersonnel);
    Compte *selectCompteSpecificIdPersonnel(int idPersonnel);

private:
    QSqlQuery * query;
    QSqlQueryModel * model;
};

#endif // BDMANAGERPERSONNEL_H
