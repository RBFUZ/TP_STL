#include "bdmanager.h"

BDManager::BDManager()
{
    query = new QSqlQuery(QSqlDatabase::database());
}






int BDManager::addPersonnel(Personnel * personnel)
{
    query->prepare("INSERT INTO TRessource (id,nom,prenom,idType)"
                "VALUES (NULL,:nom,:prenom,:idType)");

    query->bindValue(":nom", personnel->getNom());
    query->bindValue(":prenom", personnel->getPrenom());
    query->bindValue(":idType", personnel->getIdType());

    query->exec();

    return query->lastInsertId().toInt();
}

void BDManager::modifyPersonnel(Personnel * personnel)
{
    query->prepare("UPDATE TRessource "
                   "SET nom = :nom, "
                   "prenom = :prenom, "
                   "idType = :idType "
                   "WHERE id = :id");

    query->bindValue(":id", personnel->getId());
    query->bindValue(":nom", personnel->getNom());
    query->bindValue(":prenom", personnel->getPrenom());
    query->bindValue(":idType", personnel->getIdType());

    query->exec();
}

void BDManager::removePersonnel(int idPersonnel)
{
    query->prepare("DELETE FROM TRessource "
                "WHERE id = :idPersonnel");

    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();
}

QList<Personnel *> BDManager::selectAllPersonnel()
{
    model = new QSqlQueryModel();
    query->exec("SELECT * FROM TRessource");
    model->setQuery(*query);

    return convertSqlToPersonnel(model);
}

QList<Personnel *> BDManager::selectPersonnelSpecificType(int idType)
{
    model = new QSqlQueryModel();
    query->prepare("SELECT * FROM TRessource WHERE idType = :idType");
    query->bindValue(":idType", idType);
    query->exec();
    model->setQuery(*query);

    return convertSqlToPersonnel(model);
}

Personnel * BDManager::selectPersonnelSpecificId(int idPersonnel)
{
    model = new QSqlQueryModel();
    query->prepare("SELECT * FROM TRessource WHERE id = :idPersonnel");
    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();
    model->setQuery(*query);

    return convertSqlToPersonnel(model).at(0);
}

QList<Personnel *> BDManager::convertSqlToPersonnel(QSqlQueryModel * model)
{
    QList<Personnel *> listPersonnel;

    for (int i = 0; i < model->rowCount(); ++i) // For line of the query result
    {
        Personnel * personnel = new Personnel();
        personnel->convertRecordToPersonnel(model->record(i));
        listPersonnel.push_back(personnel);
    }
    return listPersonnel;
}

bool BDManager::isInformaticien(int idPersonnel)
{
    query->prepare("SELECT id FROM TCompte WHERE idRessource = :idPersonnel");
    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();
    return query->next();
}

QSqlQueryModel *BDManager::selectAllType()
{
    model = new QSqlQueryModel();
    query->exec("SELECT * FROM TType");
    model->setQuery(*query);

    return model;
}

QString BDManager::selectTypeSpecificId(int id)
{
    model = new QSqlQueryModel();
    query->prepare("SELECT label FROM TType WHERE id = :id");
    query->bindValue(":id", id);
    query->exec();
    model->setQuery(*query);
    return model->record(0).value(0).toString();
}

void BDManager::addCompte(Compte * compte)
{
    query->prepare("INSERT INTO TCompte (id,idRessource,login,mdp)"
                "VALUES (NULL,:idPersonnel,:login,:mdp)");

    query->bindValue(":idPersonnel", compte->getIdPersonnel());
    query->bindValue(":login", compte->getLogin());
    query->bindValue(":mdp", compte->getMotdepasse());

    query->exec();
}

void BDManager::removeCompte(int idPersonnel)
{
    query->prepare("DELETE FROM TCompte "
                "WHERE idRessource = :idPersonnel");

    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();
}

Compte * BDManager::selectCompteSpecificIdPersonnel(int idPersonnel)
{
    Compte * compte = new Compte();
    model = new QSqlQueryModel();
    query->prepare("SELECT * FROM TCompte WHERE idRessource = :idPersonnel");
    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();
    model->setQuery(*query);

    compte->convertRecordToCompte(model->record(0));
    return compte;
}

void BDManager::createRdv(Rdv * rdv)
{
    query->prepare("INSERT INTO TRdv (id,idClient,idRessource)"
                "VALUES (NULL,:idClient,:idRessource)");

    query->bindValue(":idClient", rdv->getIdClient());
    query->bindValue(":idRessource", rdv->getIdPersonnel());

    query->exec();
}

QList<Personnel *> BDManager::selectPersonnelSpecificClient(int idClient)
{
    QList<Personnel *> listPersonnel;

    QSqlQueryModel * model = new QSqlQueryModel();
    query->prepare("SELECT * FROM TRdv WHERE idClient = :idClient");
    query->bindValue(":idClient", idClient);
    query->exec();
    model->setQuery(*query);

    for (int i = 0; i < model->rowCount(); ++i)
        listPersonnel.push_back(selectPersonnelSpecificId(model->record(i).value(2).toInt())); // Add each Personnel object to the QList for a specific client

    return listPersonnel;
}
