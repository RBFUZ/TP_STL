#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QString>

class Personnel
{
public:
    Personnel();
    Personnel(QString nom, QString prenom, int idType);
    QString formatNom (QString nom);

    // Getters and Setters
    QString getNom() { return nom; }
    void setNom(QString nom) { this->nom = nom; }
    QString getPrenom() { return prenom; }
    void setPrenom(QString prenom) { this->prenom = prenom; }
    int getIdType() { return idType; }
    void setIdType(int idType) { this->idType = idType; }

private:
    QString nom;
    QString prenom;
    int idType;
};

#endif // PERSONNEL_H
