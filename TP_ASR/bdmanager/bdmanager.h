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


private :
    QSqlQuery * query;
    QSqlQueryModel * model;
};

#endif // BDMANAGER_H
