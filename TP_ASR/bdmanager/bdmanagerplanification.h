#ifndef BDMANAGERPLANIFICATION_H
#define BDMANAGERPLANIFICATION_H

#include <QSqlQueryModel>
#include <QSqlQuery>

#include "modeles/rdv.h"
#include "modeles/client.h"
#include "modeles/personnel.h"

#include "bdmanager/bdmanager.h"

class BDManagerPlanification
{
public:
    BDManagerPlanification();

    void createRdv(Rdv * rdv);
    void removeRdv(Client * client, Personnel * personnel);
    void removeRdv(int idPersonnel);

private:
    static QSqlDatabase * db;
    QSqlQuery * query;
    QSqlQueryModel * model;
};

#endif // BDMANAGERPLANIFICATION_H
