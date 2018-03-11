#include "bdmanagerplanification.h"

BDManagerPlanification::BDManagerPlanification()
{
    query = new QSqlQuery(QSqlDatabase::database());
}

void BDManagerPlanification::createRdv(Rdv * rdv)
{
    query->prepare("INSERT INTO TRdv (id,idClient,idRessource)"
                "VALUES (NULL,:idClient,:idRessource)");

    query->bindValue(":idClient", rdv->getIdClient());
    query->bindValue(":idRessource", rdv->getIdPersonnel());

    query->exec();
}
