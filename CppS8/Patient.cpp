#include "Patient.h"

class DisplayPatient
{
private:
	std::ostream& sortie;

public:
	DisplayPatient(ostream& out) :sortie(out) {}
	void operator()(Patient patient) {
		sortie << "Patient :" << patient.getNom().c_str() << endl;
	}
};


Patient::Patient()
{
}

Patient::Patient(string nom, vector<int> ressources) {
	this->nom=nom;
	this->ressources = ressources;
}

Patient::Patient(string nom, string prenom, string adresse, int cp, string ville, int numTel, int dureeEstime, int priorite, string commentaire, vector<int> ressources) {
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
}


Patient::~Patient()
{
}

void Patient::test(ostream& sortie)
{

	vector<Patient> patients;

	vector<int> ressources1(4, 100);
	vector<int> ressources2(4, 200);

	Patient *patient1 = new Patient("patient1", "patient1nom","add1",23455,"ville1",980973,98,1,"comm1", ressources1);
	Patient *patient2 = new Patient("patient2", "patient2nom", "add2", 23455, "ville2", 980973, 98, 1, "comm2", ressources2);

	patients.push_back(*patient1);
	patients.push_back(*patient2);

	for_each(patients.begin(), patients.end(), DisplayPatient(sortie));

	
}
