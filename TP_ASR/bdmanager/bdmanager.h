#ifndef BDMANAGER_H
#define BDMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <iostream>

class BDManager
{
public:
    static BDManager * getInstance();
    static QSqlDatabase * getConnection();
    static void close();
    static int COUNTER_INSERT;

private:
    BDManager();

    void open();

    static BDManager * instance;
    static QSqlDatabase * db;
};

#endif // BDMANAGER_H
