#include "bdmanager.h"

BDManager * BDManager::instance;
QSqlDatabase * BDManager::db;
int BDManager::COUNTER_INSERT = 0;


BDManager::BDManager()
{
    open();
}

BDManager * BDManager::getInstance()
{
    if (instance == NULL)
        instance = new BDManager();

    return instance;
}

QSqlDatabase * BDManager::getConnection()
{
    return db;
}

void BDManager::open()
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", "myConnection"));

    if(db->isValid())
    {
        db->setDatabaseName("base_tmp.sqli");
        db->open();
    }
    else
    {
        qDebug() << db->lastError().text();
        qDebug() << "Erreur à l'ouverture de la base !\n";
    }
}

void BDManager::close()
{
    db->close();
    db->removeDatabase("QSQLITE");
    std::cout << "Nombre d'insert = " << COUNTER_INSERT;
    delete instance;
    delete db;
}
