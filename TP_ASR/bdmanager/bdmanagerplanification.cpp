#include "bdmanagerplanification.h"

QSqlDatabase BDManagerPlanification::db;

BDManagerPlanification::BDManagerPlanification()
{
    db = BDManager::getInstance()->getConnection();
    query = new QSqlQuery(db);
}

void BDManagerPlanification::createRdv(Rdv * rdv)
{
    query->prepare("INSERT INTO TRdv (id,idClient,idRessource)"
                "VALUES (NULL,:idClient,:idRessource)");

    query->bindValue(":idClient", rdv->getIdClient());
    query->bindValue(":idRessource", rdv->getIdPersonnel());

    query->exec();
}
