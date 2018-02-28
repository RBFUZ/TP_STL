#include "bdmanager.h"

BDManager::BDManager()
{
}

void BDManager::addClient(Client * client)
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery * query = new QSqlQuery(db);

    query->prepare("INSERT INTO TClient (id,nom,prenom,adresse,ville,cp,commentaire,tel,dateRdv,dureeRdv,priorite)"
                "VALUES (NULL,:nom,:prenom,:adresse,:ville,:cp,:commentaires,:tel,:date,:duree,:priorite)");

    bindValue(query, client); // Bind client value to the query

    query->exec();
}

void BDManager::modifyClient(Client * client, int idClient)
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery * query = new QSqlQuery(db);

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

    query->bindValue(":id", idClient);
    bindValue(query, client); // Bind client value to the query

    query->exec();
}

QSqlTableModel * BDManager::searchClient(QLineEdit * leNom, QLineEdit * lePrenom, QLineEdit * leIdentifiant, QDateEdit * deDebut, QDateEdit * deFin)
{
    QString nom = leNom->text(), prenom = lePrenom->text(), identifiant = leIdentifiant->text();
    QSqlDatabase db = QSqlDatabase::database();
    QSqlTableModel * model = new QSqlTableModel(NULL, db);
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
