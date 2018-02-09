#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Patient
{
private:
	string nom;
	string prenom;
	string adresse;
	string ville;
	string commentaire;
	int numTel;
	int cp;
	int dureeEstime;
	int priorite;

	vector<int> ressources;

public:
	Patient();
	Patient(string nom, vector<int> ressources);
	Patient(string nom, string prenom, string adresse, int cp, string ville, int numTel, int dureeEstime, int priorite, string commentaire, vector<int> ressources);
	~Patient();

	string getNom() { return nom; }
	void setNom(string nom) { this->nom = nom; }
	string getPrenom() { return prenom; }
	void setPreom(string prenom) { this->prenom = prenom; }
	string getAdresse() { return adresse; }
	void setAdress(string adresse) { this->adresse = adresse; }
	string getVille() { return ville; }
	void setVille(string ville) { this->ville = ville; }
	string getCommeentaire() { return commentaire; }
	void setComentaire(string commentaire) { this->commentaire= commentaire; }
	int getnumTel() { return numTel; }
	void setNumTel(int numTel) { this->numTel = numTel; }
	int getCp() { return cp; }
	void setCp(int cp) { this->cp = cp; }
	int getDureeEstime() { return dureeEstime; }
	void setDureeEstime(int dureeEstime) { this->dureeEstime= dureeEstime; }
	int getPriorite() { return priorite; }
	void setPriorite(int priorite) { this->priorite = priorite; }
	vector<int>*getRessources() { return &ressources; }
	void setResources(vector<int> resources) { this->ressources = resources; }

	//void displayPatient(ostream& sortie);
	static void test(ostream& sortie);
};

