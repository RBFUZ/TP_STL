#include "bdmanager.h"

BDManager::BDManager()
{
    query = new QSqlQuery(QSqlDatabase::database());
}
