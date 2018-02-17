#include "patient.h"

Patient::Patient()
{
}

Patient::Patient(QString nom, vector<int> ressources) {
    this->nom=nom;
    this->ressources = ressources;
}

Patient::Patient(QString nom, QString prenom, QString adresse, int cp, QString ville, int numTel, int dureeEstime, int priorite, QString commentaire, vector<int> ressources) {
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->cp = cp;
    this->ville = ville;
    this->numTel = numTel;
    this->dureeEstime = dureeEstime;
    this->priorite = priorite;
    this->commentaire = commentaire;
    this->ressources = ressources;

    for (vector<int>::iterator itR = ressources.begin(); itR != ressources.end(); ++itR)
    {
        heurePassage.insert(pair<int, int>(*itR, -1));
    }

}


Patient::~Patient()
{
}
