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
    model = new QSqlQueryModel();
    query->exec("SELECT * FROM TRessource");
    model->setQuery(*query);

    return convertSqlToPersonnel(model);
}

QList<Personnel *> BDManagerPersonnel::selectPersonnelSpecificType(int idType)
{
    model = new QSqlQueryModel();
    query->prepare("SELECT * FROM TRessource WHERE idType = :idType");
    query->bindValue(":idType", idType);
    query->exec();
    model->setQuery(*query);

    return convertSqlToPersonnel(model);
}

Personnel * BDManagerPersonnel::selectPersonnelSpecificId(int idPersonnel)
{
    model = new QSqlQueryModel();
    query->prepare("SELECT * FROM TRessource WHERE id = :idPersonnel");
    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();
    model->setQuery(*query);

    return convertSqlToPersonnel(model).at(0);
}

QList<Personnel *> BDManagerPersonnel::selectPersonnelSpecificClient(int idClient)
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

QList<Personnel *> BDManagerPersonnel::convertSqlToPersonnel(QSqlQueryModel * model)
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
    model = new QSqlQueryModel();
    query->prepare("SELECT label FROM TType WHERE id = :id");
    query->bindValue(":id", id);
    query->exec();
    model->setQuery(*query);
    return model->record(0).value(0).toString();
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
    model = new QSqlQueryModel();
    query->prepare("SELECT * FROM TCompte WHERE idRessource = :idPersonnel");
    query->bindValue(":idPersonnel", idPersonnel);
    query->exec();
    model->setQuery(*query);

    compte->convertRecordToCompte(model->record(0));
    return compte;
}

QList<Compte *> BDManagerPersonnel::selectAllCompte()
{
    QList<Compte *> listAllCompte;

    QSqlQueryModel * model = new QSqlQueryModel();
    query->prepare("SELECT * FROM TCompte");
    query->exec();
    model->setQuery(*query);

    for (int i = 0; i < model->rowCount(); ++i)
    {
        Compte * compte = new Compte();
        compte->convertRecordToCompte(model->record(i));
        listAllCompte.push_back(compte);
    }

    return listAllCompte;
}
