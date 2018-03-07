#include "bdmanager.h"

BDManager::BDManager()
{
    query = new QSqlQuery(QSqlDatabase::database());
}

int BDManager::addClient(Client * client)
{
    query->prepare("INSERT INTO TClient (id,nom,prenom,adresse,ville,cp,commentaire,tel,dateRdv,dureeRdv,priorite)"
                "VALUES (NULL,:nom,:prenom,:adresse,:ville,:cp,:commentaires,:tel,:date,:duree,:priorite)");

    bindValue(query, client); // Bind client value to the query

    query->exec();
    return query->lastInsertId().toInt();
}

void BDManager::modifyClient(Client * client)
{
    query->prepare("UPDATE TClient "
                   "SET nom = :nom, "
                   "prenom = :prenom, "
                   "adresse = :adresse, "
                   "ville = :ville, "
                   "cp = :cp, "
                   "commentaire = :commentaires, "
                   "tel = :tel, "
                   "dateRdv = :date, "
                   "dureeRdv = :duree,"
                   "priorite = :priorite "
                   "WHERE id = :id");

    query->bindValue(":id", client->getId());
    bindValue(query, client); // Bind client value to the query

    query->exec();
}

QSqlTableModel * BDManager::searchClient(QLineEdit * leNom, QLineEdit * lePrenom, QLineEdit * leIdentifiant, QDateEdit * deDebut, QDateEdit * deFin)
{
    QString nom = leNom->text(), prenom = lePrenom->text(), identifiant = leIdentifiant->text();
    QSqlTableModel * model = new QSqlTableModel(NULL, QSqlDatabase::database());
    model->setTable("TClient");
    model->select();

    if (nom.length() != 0) // Add % if not empty
        nom = nom.append('%');
    if (prenom.length() != 0) // Add % if not empty
        prenom = prenom.append('%');
    if (identifiant.length() == 0) // Set to 0 because problem if the string is empty
        identifiant = "0";

    // setFilter is equivalent to WHERE clause in SQL
    model->setFilter(QString("id = "+ identifiant +
                             " OR nom LIKE '"+ nom +
                             "' OR prenom LIKE '"+ prenom +
                             "' OR dateRdv between '"+ deDebut->text() +"' and '"+ deFin->text() +"'"));

    return model;
}

void BDManager::bindValue(QSqlQuery * query, Client * client)
{
    query->bindValue(":nom", client->getNom());
    query->bindValue(":prenom", client->getPrenom());
    query->bindValue(":adresse", client->getAdresse());
    query->bindValue(":ville", client->getVille());
    query->bindValue(":cp", client->getCp());
    query->bindValue(":commentaires", client->getCommentaires());
    query->bindValue(":tel", client->getnumTel());
    query->bindValue(":date", client->getJourPassage().toString("yyyy-MM-dd"));
    query->bindValue(":duree", client->getDureeEstime());
    query->bindValue(":priorite", client->getPriorite());
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

vector<Personnel *> BDManager::selectAllPersonnel()
{
    model = new QSqlQueryModel();
    query->exec("SELECT * FROM TRessource");
    model->setQuery(*query);

    return convertSqlToPersonnel(model);
}

vector<Personnel *> BDManager::selectPersonnelSpecificType(int idType)
{
    model = new QSqlQueryModel();
    query->prepare("SELECT * FROM TRessource WHERE idType = :idType");
    query->bindValue(":idType", idType);
    query->exec();
    model->setQuery(*query);

    return convertSqlToPersonnel(model);
}

Personnel * BDManager::selectPersonnelSpecificId(int id)
{
    Personnel * personnel = new Personnel();
    model = new QSqlQueryModel();
    query->prepare("SELECT * FROM TRessource WHERE id = :id");
    query->bindValue(":id", id);
    query->exec();
    model->setQuery(*query);

    personnel->convertRecordToPersonnel(model->record(0));
    return personnel;
}

vector<Personnel *> BDManager::convertSqlToPersonnel(QSqlQueryModel * model)
{
    vector<Personnel *> listPersonnel;

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
