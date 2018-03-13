#ifndef BDMANAGERPLANIFICATION_H
#define BDMANAGERPLANIFICATION_H

#include <QSqlQueryModel>
#include <QSqlQuery>

#include "modeles/rdv.h"
#include "bdmanager/bdmanager.h"

class BDManagerPlanification
{
public:
    BDManagerPlanification();

    void createRdv(Rdv *rdv);

private:
    static QSqlDatabase db;
    QSqlQuery * query;
    QSqlQueryModel * model;
};

#endif // BDMANAGERPLANIFICATION_H
