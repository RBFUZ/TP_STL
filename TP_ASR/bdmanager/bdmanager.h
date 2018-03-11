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

private :
    QSqlQuery * query;
    QSqlQueryModel * model;
};

#endif // BDMANAGER_H
