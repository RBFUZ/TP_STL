#include "bdmanager.h"

BDManager * BDManager::instance;
QSqlDatabase BDManager::db;


BDManager::BDManager()
{
    open();
}

BDManager::~BDManager()
{
    close();
}

BDManager * BDManager::getInstance()
{
    if (instance == NULL)
        instance = new BDManager();

    return instance;
}

QSqlDatabase BDManager::getConnection()
{
    return db;
}

void BDManager::open()
{
    db = QSqlDatabase::database("Planification");

    if(db.isValid())
    {
        db.setDatabaseName("base_tmp.sqli");
        db.open();
    }
    else
    {
        qDebug() << db.lastError().text();
        qDebug() << "Erreur à l'ouverture de la base !\n";
    }
}

void BDManager::close()
{
    db.close();
    db.removeDatabase("Planification");
}
