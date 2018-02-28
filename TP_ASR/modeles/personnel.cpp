#include "personnel.h"

Personnel::Personnel()
{

}

Personnel::Personnel(QString nom, QString prenom, int idType)
{
    this->nom = formatNom(nom);
    this->prenom = formatNom(prenom);
    this->idType = idType;
}

QString Personnel::formatNom (QString nom){
    nom=nom.toLower();
    nom[0]=nom[0].toUpper();
    return nom;
}
