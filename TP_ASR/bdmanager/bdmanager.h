#ifndef BDMANAGER_H
#define BDMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class BDManager
{
public:
    static BDManager * getInstance();
    static QSqlDatabase getConnection();

private:
    BDManager();
    ~BDManager();

    void open();
    void close();

    static BDManager * instance;
    static QSqlDatabase db;
};

#endif // BDMANAGER_H
