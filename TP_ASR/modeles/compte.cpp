#include "compte.h"

Compte::Compte()
{
}

Compte::Compte(int idPersonnel, QString login, QString motdepasse)
{
    this->idPersonnel = idPersonnel;
    this->login = login;
    this->motdepasse = motdepasse;
}
