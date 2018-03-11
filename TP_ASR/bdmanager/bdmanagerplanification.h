#ifndef BDMANAGERPLANIFICATION_H
#define BDMANAGERPLANIFICATION_H

#include <QSqlQueryModel>
#include <QSqlQuery>

#include "modeles/rdv.h"

class BDManagerPlanification
{
public:
    BDManagerPlanification();

    void createRdv(Rdv *rdv);

private:
    QSqlQuery * query;
    QSqlQueryModel * model;
};

#endif // BDMANAGERPLANIFICATION_H
