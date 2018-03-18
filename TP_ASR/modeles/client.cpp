#include "client.h"

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

void Client::convertRecordToClient(QSqlRecord record)
{
    this->id = record.value(0).toInt();
    this->nom = record.value(1).toString();
    this->prenom = record.value(2).toString();
    this->adresse = record.value(3).toString();
    this->ville = record.value(4).toString();
    this->cp = record.value(5).toInt();
    this->commentaires = record.value(6).toString();
    this->numTel = record.value(7).toInt();
    this->jourPassage = record.value(8).toDate();
    this->dureeEstime = record.value(9).toInt();
    this->priorite = record.value(10).toInt();
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
