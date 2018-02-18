#ifndef PATIENT_H
#define PATIENT_H
#define DEFAULT_DUREE_ESTIME 60 //TODO : useless ? default value in the view
#define DEFAULT_PRIORITE 1
#include <QString>
#include <QDate>

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#include <QDebug>

using namespace std;


class Patient
{
private:
    QString nom;
    QString prenom;
    QString adresse;
    QString ville;
    int cp;
    int numTel; //facultatif
    QDate jourPassage;
    int dureeEstime = DEFAULT_DUREE_ESTIME; //in minute
    int priorite = DEFAULT_PRIORITE;// 5 high -> 1 low
    vector<int> ressources; //TODO :Pasage a un QVector
    QString commentaires; //facultatif

    multimap<int, int> heurePassage;

    QString formatNom (QString nom);
    int formatCp (QString cp); //convert QString to int

public:
    Patient();
    //Patient(QString nom, vector<int> ressources) Obsolete
    Patient(QString nom, QString prenom, QString adresse, QString ville,QString cp, QString numTel, QDate jourPassage, int dureeEstime, int priorite, vector<int> * ressources, QString commentaires);
    ~Patient();

    //inline get/set
    QString getNom() { return nom; }
    void setNom(QString nom) { this->nom = formatNom(nom); }
    QString getPrenom() { return prenom; }
    void setPreom(QString prenom) { this->prenom = formatNom(prenom); }
    QString getAdresse() { return adresse; }
    void setAdress(QString adresse) { this->adresse = adresse; }
    QString getVille() { return ville; }
    void setVille(QString ville) { this->ville = formatNom(ville); }
    QString getCommentaires() { return commentaires; }
    void setComentaires(QString commentaires) { this->commentaires= commentaires; }
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

    //test_only
    void display();


};

#endif // PATIENT_H
