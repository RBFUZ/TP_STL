#ifndef C_INIT_BD_H
#define C_INIT_BD_H

#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>

class c_init_bd
{
public:
    c_init_bd();
    void static Creation_BD();

    QSqlDatabase static Open_BD();
    void static Close_BD();
private:
    static QSqlDatabase db;
};

#endif // C_INIT_BD_H
