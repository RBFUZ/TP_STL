#include "patient.h"

Patient::Patient()
{
}

/*Obsolete
  Patient::Patient(QString nom, vector<int> ressources) {
    this->nom=nom;
    this->ressources = ressources;
}
*/

Patient::Patient(QString nom, QString prenom, QString adresse, QString ville,QString cp, QString numTel, QDate jourPassage, int dureeEstime, int priorite, QVector<QString> * ressources, QString commentaires){
    this->nom = formatNom(nom);
    this->prenom = formatNom(prenom);
    this->adresse = adresse;
    this->ville = formatNom(ville);
    this->cp = cp.toInt();//Format is defined in the view
    this->numTel = numTel.toInt();//Format is defined in the view
    this->jourPassage=jourPassage;
    this->dureeEstime = dureeEstime;
    this->priorite = priorite;
    this->ressources = ressources;//TODO : QVector ? Transformation des QString en ID ? passage a un pointeur ?
    this->commentaires = commentaires;
/*
    for (vector<int>::iterator itR = ressources.begin(); itR != ressources.end(); ++itR)
    {
        heurePassage.insert(pair<int, int>(*itR, -1));
    }
*/
}

QString Patient::formatNom (QString nom){
    nom=nom.toLower();
    nom[0]=nom[0].toUpper();
    return nom;
}

int Patient::formatCp(QString cp){
    if (cp.length()==5)
        return cp.toInt();
    else
        return 0;
}//Return 0 if invalid conversion or more/less than 5 number

Patient::~Patient()
{
}

void Patient::display(){
    qDebug()<<"New client created :"
         <<"\n Nom : "<<nom
         <<"\n Prenom : "<<prenom
         <<"\n Adresse : "<<adresse
         <<"\n Ville : "<<ville
         <<"\n CP : "<<cp
         <<"\n Tel : "<<numTel
         <<"\n Date : "<<jourPassage
         <<"\n Duree : "<<dureeEstime
         <<"\n Priorite : "<<priorite
         <<"\n Ressources : "<<*ressources
         <<"\n Commentaires : "<<commentaires;

}
