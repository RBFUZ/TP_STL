#include "client.h"
#include "c_init_bd.h"

Client::Client()
{
}

Client::Client(QString nom, QString prenom, QString adresse, QString ville,QString cp, QString commentaires, QString numTel, QDate jourPassage, int dureeEstime, int priorite){
    this->nom = formatNom(nom);
    this->prenom = formatNom(prenom);
    this->adresse = adresse;
    this->ville = formatNom(ville);
    this->cp = cp.toInt(); //Format is defined in the view
    this->commentaires = commentaires;
    this->numTel = numTel.toInt(); //Format is defined in the view
    this->jourPassage=jourPassage;
    this->dureeEstime = dureeEstime;
    this->priorite = priorite;
}

QString Client::formatNom (QString nom){
    nom=nom.toLower();
    nom[0]=nom[0].toUpper();
    return nom;
}

int Client::formatCp(QString cp){
    if (cp.length()==5)
        return cp.toInt();
    else
        return 0;
}//Return 0 if invalid conversion or more/less than 5 number

Client::~Client()
{
}

void Client::display(){
    qDebug()<<"New client created :"
         <<"\n Nom : "<<nom
         <<"\n Prenom : "<<prenom
         <<"\n Adresse : "<<adresse
         <<"\n Ville : "<<ville
         <<"\n CP : "<<cp
         <<"\n Commentaires : "<<commentaires
         <<"\n Tel : "<<numTel
         <<"\n Date : "<<jourPassage
         <<"\n Duree : "<<dureeEstime
         <<"\n Priorite : "<<priorite;
}
