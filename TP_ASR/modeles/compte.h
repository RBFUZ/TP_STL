#ifndef COMPTE_H
#define COMPTE_H

#include <QString>

class Compte
{
public:
    Compte();
    Compte(int idPersonnel, QString login, QString motdepasse);

    // Getters and Setters
    int getIdPersonnel() { return idPersonnel; }
    QString getLogin() { return login; }
    QString getMotdepasse() { return motdepasse; }

    void setIdPersonnel(int idPersonnel) { this->idPersonnel = idPersonnel; }
    void setLogin(int login) { this->login = login; }
    void setMotdepasse(int motdepasse) { this->motdepasse = motdepasse; }

private:
    int idPersonnel;
    QString login;
    QString motdepasse;
};

#endif // COMPTE_H
