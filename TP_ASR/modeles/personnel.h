#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QString>
#include <QSqlRecord>

class Personnel
{
private:
    int id;
    QString nom;
    QString prenom;
    int idType;

public:
    Personnel();
    Personnel(QString nom, QString prenom, int idType);
    void convertRecordToPersonnel(QSqlRecord record);
    QString formatNom (QString nom);

    // Getters and Setters
    int getId() { return id; }
    void setId(int id) { this->id = id; }
    QString getNom() { return nom; }
    void setNom(QString nom) { this->nom = nom; }
    QString getPrenom() { return prenom; }
    void setPrenom(QString prenom) { this->prenom = prenom; }
    int getIdType() { return idType; }
    void setIdType(int idType) { this->idType = idType; }
};

#endif // PERSONNEL_H
