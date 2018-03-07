#include "personnel.h"
#include <QVariant>

Personnel::Personnel()
{

}

Personnel::Personnel(QString nom, QString prenom, int idType)
{
    this->nom = formatNom(nom);
    this->prenom = formatNom(prenom);
    this->idType = idType;
}

void Personnel::convertRecordToPersonnel(QSqlRecord record)
{
    this->id = record.value(0).toInt();
    this->nom = record.value(1).toString();
    this->prenom = record.value(2).toString();
    this->idType = record.value(3).toInt();
}

QString Personnel::formatNom (QString nom){
    nom=nom.toLower();
    nom[0]=nom[0].toUpper();
    return nom;
}
