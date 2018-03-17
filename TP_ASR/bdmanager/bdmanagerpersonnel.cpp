#include "bdmanagerpersonnel.h"

QSqlDatabase * BDManagerPersonnel::db;

BDManagerPersonnel::BDManagerPersonnel()
{
    db = BDManager::getInstance()->getConnection();
    query = new QSqlQuery(*db);
}

int BDManagerPersonnel::addPersonnel(Personnel * personnel)
{
    query->prepare("INSERT INTO TRessource (id,nom,prenom,idType)"
                "VALUES (NULL,:nom,:prenom,:idType)");

    query->bindValue(":nom", personnel->getNom());
    query->bindValue(":prenom", personnel->getPrenom());
    query->bindValue(":idType", personnel->getIdType());

    query->exec();

    return query->lastInsertId().toInt();
}

void BDManagerPersonnel::modifyPersonnel(Personnel * personnel)
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

void BDManagerPersonnel::removePersonnel(int idPersonnel)
{
    query->prepare("DELETE FROM TRessource "
                "WHERE id = :idPersonnel");

    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();
}

QList<Personnel *> BDManagerPersonnel::selectAllPersonnel()
{
    query->exec("SELECT * FROM TRessource");

    return convertSqlToPersonnel(query);
}

QList<Personnel *> BDManagerPersonnel::selectPersonnelSpecificType(int idType)
{
    query->prepare("SELECT * FROM TRessource WHERE idType = :idType");
    query->bindValue(":idType", idType);
    query->exec();

    return convertSqlToPersonnel(query);
}

Personnel * BDManagerPersonnel::selectPersonnelSpecificId(int idPersonnel)
{
    QSqlQuery * query = new QSqlQuery(*db); // Local variable because query is already used.

    query->prepare("SELECT * FROM TRessource WHERE id = :idPersonnel");
    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();

    return convertSqlToPersonnel(query).at(0);
}

QList<Personnel *> BDManagerPersonnel::selectPersonnelSpecificClient(int idClient)
{
    QList<Personnel *> listPersonnel;

    query->prepare("SELECT * FROM TRdv WHERE idClient = :idClient");
    query->bindValue(":idClient", idClient);
    query->exec();

    while (query->next())
        listPersonnel.push_back(selectPersonnelSpecificId(query->record().value(2).toInt())); // Add each Personnel object to the QList for a specific client

    return listPersonnel;
}

QList<Personnel *> BDManagerPersonnel::convertSqlToPersonnel(QSqlQuery * query)
{
    QList<Personnel *> listPersonnel;

    while (query->next())
    {
        Personnel * personnel = new Personnel();
        personnel->convertRecordToPersonnel(query->record());
        listPersonnel.push_back(personnel);
    }

    return listPersonnel;
}

bool BDManagerPersonnel::isInformaticien(int idPersonnel)
{
    query->prepare("SELECT id FROM TCompte WHERE idRessource = :idPersonnel");
    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();
    return query->next();
}

QSqlQueryModel * BDManagerPersonnel::selectAllType()
{
    model = new QSqlQueryModel();
    query->exec("SELECT * FROM TType");
    model->setQuery(*query);

    return model;
}

QString BDManagerPersonnel::selectTypeSpecificId(int id)
{
    query->prepare("SELECT label FROM TType WHERE id = :id");
    query->bindValue(":id", id);
    query->exec();

    if (!query->next())
        return NULL;
    else
        return query->record().value(0).toString();
}

void BDManagerPersonnel::addCompte(Compte * compte)
{
    query->prepare("INSERT INTO TCompte (id,idRessource,login,mdp)"
                "VALUES (NULL,:idPersonnel,:login,:mdp)");

    query->bindValue(":idPersonnel", compte->getIdPersonnel());
    query->bindValue(":login", compte->getLogin());
    query->bindValue(":mdp", compte->getMotdepasse());

    query->exec();
}

void BDManagerPersonnel::removeCompte(int idPersonnel)
{
    query->prepare("DELETE FROM TCompte "
                "WHERE idRessource = :idPersonnel");

    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();
}

Compte * BDManagerPersonnel::selectCompteSpecificIdPersonnel(int idPersonnel)
{
    Compte * compte = new Compte();

    query->prepare("SELECT * FROM TCompte WHERE idRessource = :idPersonnel");
    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();

    query->next();

    compte->convertRecordToCompte(query->record());
    return compte;
}

bool BDManagerPersonnel::verifyConnection(QString login, QString password)
{
    query->prepare("SELECT * FROM TCompte WHERE Login LIKE :login AND mdp LIKE :password");
    query->bindValue(":login", login);
    query->bindValue(":password", password);
    query->exec();

    if (query->next())
        return true;
    else
        return false;
}
