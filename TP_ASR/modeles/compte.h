#ifndef COMPTE_H
#define COMPTE_H

#include <QString>
#include <QSqlRecord>

class Compte
{
public:
    Compte();
    Compte(int idPersonnel, QString login, QString motdepasse);
    void convertRecordToCompte(QSqlRecord record);

    // Getters and Setters
    int getId() { return id; }
    int getIdPersonnel() { return idPersonnel; }
    QString getLogin() { return login; }
    QString getMotdepasse() { return motdepasse; }

    void setId(int id) { this->id = id; }
    void setIdPersonnel(int idPersonnel) { this->idPersonnel = idPersonnel; }
    void setLogin(int login) { this->login = login; }
    void setMotdepasse(int motdepasse) { this->motdepasse = motdepasse; }

private:
    int id;
    int idPersonnel;
    QString login;
    QString motdepasse;
};

#endif // COMPTE_H
