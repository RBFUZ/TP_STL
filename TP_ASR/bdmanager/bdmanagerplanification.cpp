#include "bdmanagerplanification.h"

QSqlDatabase * BDManagerPlanification::db;

BDManagerPlanification::BDManagerPlanification()
{
    db = BDManager::getInstance()->getConnection();
    query = new QSqlQuery(*db);
}

void BDManagerPlanification::createRdv(Rdv * rdv)
{
    query->prepare("INSERT INTO TRdv (id,idClient,idRessource)"
                "VALUES (NULL,:idClient,:idRessource)");

    query->bindValue(":idClient", rdv->getIdClient());
    query->bindValue(":idRessource", rdv->getIdPersonnel());

    query->exec();

    BDManager::COUNTER_INSERT++;
}

void BDManagerPlanification::removeRdv(Client * client, Personnel * personnel)
{
    query->prepare("DELETE FROM TRdv "
                "WHERE idClient = :idClient and idRessource = :idPersonnel");

    query->bindValue(":idClient", client->getId());
    query->bindValue(":idPersonnel", personnel->getId());
    query->exec();
}

void BDManagerPlanification::removeRdv(int idPersonnel)
{
    query->prepare("DELETE FROM TRdv "
                "WHERE idRessource = :idPersonnel");

    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();
}
