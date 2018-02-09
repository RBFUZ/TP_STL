#include "Patient.h"


class DisplayPatient
{
private:
	std::ostream& sortie;
	int dureeConsultation =0;
	int priorite =0;
	int nbPatient =0;

public:
	DisplayPatient(ostream& out) :sortie(out) {}
	void operator()(Patient patient) {
		sortie << "Patient -> nom: " << patient.getNom().c_str() << " /prenom : "<<patient.getPrenom().c_str() << endl;
		nbPatient++;
		priorite += patient.getPriorite();
		dureeConsultation += patient.getDureeEstime();
	}
	int getDureeConsultation() { return dureeConsultation; }
	int getPrioriteMoy() { return priorite / nbPatient; }
};

class SortResources
{
public:
	SortResources() {}
	Patient operator()(Patient patient) {
				
		sort(patient.getRessources()->begin(), patient.getRessources()->end());

		return patient;
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
	vector<Patient> patientsSorted;

	vector<int> ressources1{ 4, 100, 20, 30 };
	vector<int> ressources2{ 4, 200, 0, 8 };

	Patient *patient1 = new Patient("patient1", "patient1nom","add1",23455,"ville1",980973,666,1,"comm1", ressources1);
	Patient *patient2 = new Patient("patient2", "patient2nom", "add2", 23455, "ville2", 980973, 111, 3, "comm2", ressources2);

	patients.push_back(*patient1);
	patients.push_back(*patient2);

	patientsSorted.resize(patients.size());
	transform(patients.begin(), patients.end(), patientsSorted.begin(), SortResources());

	DisplayPatient res = for_each(patientsSorted.begin(), patientsSorted.end(), DisplayPatient(sortie));
	sortie << "Durée totale consultation : " << res.getDureeConsultation() << endl;
	sortie << "Priorité moyene : " << res.getPrioriteMoy() << endl;

	cout << endl;
	
}
