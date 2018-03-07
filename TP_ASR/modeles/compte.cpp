#include "compte.h"
#include <QVariant>

Compte::Compte()
{
}

Compte::Compte(int idPersonnel, QString login, QString motdepasse)
{
    this->idPersonnel = idPersonnel;
    this->login = login;
    this->motdepasse = motdepasse;
}

void Compte::convertRecordToCompte(QSqlRecord record)
{
    this->id = record.value(0).toInt();
    this->idPersonnel = record.value(1).toInt();
    this->login = record.value(2).toString();
    this->motdepasse = record.value(3).toString();
}
