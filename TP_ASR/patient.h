#ifndef PATIENT_H
#define PATIENT_H
#define DEFAULT_DUREE_ESTIME 60
#define DEFAULT_PRIORITE 1
#include <QString>
#include <QDate>

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


class Patient
{
private:
    QString nom;
    QString prenom;
    QString adresse;
    QString ville;
    QString commentaire; //facultatif
    int numTel; //facultatif
    int cp;
    int dureeEstime = DEFAULT_DUREE_ESTIME; //in minute
    int priorite = DEFAULT_PRIORITE;// 5 high -> 1 low

    vector<int> ressources; //Liste d'Id de ressources
    QDate jourPassage;
    multimap<int, int> heurePassage;

    QString formatNom (QString nom);
    int formatCp (QString cp); //convert QString to int

public:
    Patient();
    Patient(QString nom, vector<int> ressources);
    Patient(QString nom, QString prenom, QString adresse, int cp, QString ville, int numTel, int dureeEstime, int priorite, QString commentaire, vector<int> ressources);
    ~Patient();

    QString getNom() { return nom; }
    void setNom(QString nom) { this->nom = formatNom(nom); }
    QString getPrenom() { return prenom; }
    void setPreom(QString prenom) { this->prenom = formatNom(prenom); }
    QString getAdresse() { return adresse; }
    void setAdress(QString adresse) { this->adresse = adresse; }
    QString getVille() { return ville; }
    void setVille(QString ville) { this->ville = formatNom(ville); }
    QString getCommentaire() { return commentaire; }
    void setComentaire(QString commentaire) { this->commentaire= commentaire; }
    int getnumTel() { return numTel; }
    void setNumTel(int numTel) { this->numTel = numTel; }
    int getCp() { return cp; }
    void setCp(QString cp) { this->cp = formatCp(cp); }//QString to int
    int getDureeEstime() { return dureeEstime; }
    void setDureeEstime(int dureeEstime) { this->dureeEstime= dureeEstime; }
    int getPriorite() { return priorite; }
    void setPriorite(int priorite) { this->priorite = priorite; }
    vector<int>* getRessources() { return &ressources; }//pointer
    void setResources(vector<int> resources) { this->ressources = resources; }
    multimap<int,int> * getHeurePassage() { return &heurePassage; }//pointer
    QDate getJourPassage(){return jourPassage;}
    void setJourPassge(QDate date){this->jourPassage=date;}

};

#endif // PATIENT_H
