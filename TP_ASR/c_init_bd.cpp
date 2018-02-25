#include "c_init_bd.h"

#define PATHDATABASE "base_tmp.sqli"
#define CONNECTIONNAME "Reservation"

QSqlDatabase c_init_bd::db;

c_init_bd::c_init_bd()
{
}

void c_init_bd::Close_BD()
{
    db.close();
}

void c_init_bd::Creation_BD()
{
    QFile::remove(PATHDATABASE); // Remove old database

    db = QSqlDatabase::addDatabase("QSQLITE", CONNECTIONNAME);
    db.setDatabaseName(PATHDATABASE);
    db.open();

    QSqlQuery * query = new QSqlQuery(db);
    query->exec("CREATE TABLE TClient "
              "(id integer primary key AUTOINCREMENT, "
              "nom varchar(25), "
              "prenom varchar(25), "
              "adresse varchar(50), "
              "ville varchar(20), "
              "cp varchar(8), "
              "commentaire varchar(200), "
              "tel integer, "
              "dateRdv date, "
              "dureeRdv integer, "
              "priorite integer)");

    query->exec("CREATE TABLE TType "
              "(id integer primary key AUTOINCREMENT, "
              "label varchar(25))");

    query->exec("CREATE TABLE TRessource "
              "(id integer primary key AUTOINCREMENT, "
              "nom varchar(25), "
              "prenom varchar(25), "
              "idType integer, "
              "FOREIGN KEY(idType) REFERENCES TType(id))");

    query->exec("CREATE TABLE TRdv "
              "(id integer primary key AUTOINCREMENT, "
              "idClient integer, "
              "idRessource integer, "
              "FOREIGN KEY(idClient) REFERENCES TClient(id), "
              "FOREIGN KEY(idRessource) REFERENCES TRessource(id))");

    query->exec("CREATE TABLE TCompte "
              "(id integer primary key AUTOINCREMENT, "
              "idRessource integer, "
              "login varchar(25), "
              "mdp varchar(25), "
              "FOREIGN KEY(idRessource) REFERENCES TRessource(id))");
}
