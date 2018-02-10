#include "Patient.h"
#include "Creneau.h"
#include <math.h>


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

// Trie des patients pour attribution de rendez-vous
class SortPatient
{
public:
	SortPatient() {}
	bool operator()(Patient patient1, Patient patient2)
	{
		int priorite1, priorite2;

		priorite1 = (patient1.getPriorite() * 100) + (patient1.getRessources()->size() * 10) + patient1.getDureeEstime();
		priorite2 = (patient2.getPriorite() * 100) + (patient2.getRessources()->size() * 10) + patient2.getDureeEstime();

		return (priorite2 < priorite1);
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

	heurePassage.insert(pair<int, int>(1, -1));
	heurePassage.insert(pair<int, int>(2, -1));
	heurePassage.insert(pair<int, int>(3, -1));
	heurePassage.insert(pair<int, int>(4, -1));
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

	Patient *patient1 = new Patient("patient1", "patient1nom", "add1", 23455, "ville1", 980973, 666, 1, "comm1", ressources1);
	Patient *patient2 = new Patient("patient2", "patient2nom", "add2", 23455, "ville2", 980973, 111, 3, "comm2", ressources2);

	patients.push_back(*patient1);
	patients.push_back(*patient2);

	patientsSorted.resize(patients.size());
	transform(patients.begin(), patients.end(), patientsSorted.begin(), SortResources());

	DisplayPatient res = for_each(patientsSorted.begin(), patientsSorted.end(), DisplayPatient(sortie));
	sortie << "Dur�e totale consultation : " << res.getDureeConsultation() << endl;
	sortie << "Priorit� moyene : " << res.getPrioriteMoy() << endl;

	cout << endl;

}

void Patient::testAlgo()
{
	/* ORDRE : 12 / 13 / 7 / 9 / 15 / 14 / 17 / 10 / 6 / 16 / 11 / 19 / 5 / 4 / 2 / 3 / 18 / 8 / 1 */

	string nom;
	vector<Patient> patientList;
	vector<int> ressources{ 1, 2, 3, 4 };

	Patient * patient1 = new Patient("nom1", "prenom", "adresse", 0, "tours", 0, 20, 1, "dz", ressources);
	Patient * patient2 = new Patient("nom2", "prenom", "adresse", 0, "tours", 0, 40, 7, "dz", ressources);
	Patient * patient3 = new Patient("nom3", "prenom", "adresse", 0, "tours", 0, 30, 2, "dz", ressources);
	Patient * patient4 = new Patient("nom4", "prenom", "adresse", 0, "tours", 0, 80, 10, "dz", ressources);
	Patient * patient5 = new Patient("nom5", "prenom", "adresse", 0, "tours", 0, 50, 12, "dz", ressources);
	Patient * patient6 = new Patient("nom6", "prenom", "adresse", 0, "tours", 0, 60, 19, "dz", ressources);
	Patient * patient7 = new Patient("nom7", "prenom", "adresse", 0, "tours", 0, 48, 50, "dz", ressources);
	Patient * patient8 = new Patient("nom8", "prenom", "adresse", 0, "tours", 0, 65, 1, "dz", ressources);
	Patient * patient9 = new Patient("nom9", "prenom", "adresse", 0, "tours", 0, 70, 45, "dz", ressources);
	Patient * patient10 = new Patient("nom10", "prenom", "adresse", 0, "tours", 0, 559, 16, "dz", ressources);
	Patient * patient11 = new Patient("nom11", "prenom", "adresse", 0, "tours", 0, 45, 17, "dz", ressources);
	Patient * patient12 = new Patient("nom12", "prenom", "adresse", 0, "tours", 0, 32, 91, "dz", ressources);
	Patient * patient13 = new Patient("nom13", "prenom", "adresse", 0, "tours", 0, 29, 64, "dz", ressources);
	Patient * patient14 = new Patient("nom14", "prenom", "adresse", 0, "tours", 0, 78, 28, "dz", ressources);
	Patient * patient15 = new Patient("nom15", "prenom", "adresse", 0, "tours", 0, 132, 37, "dz", ressources);
	Patient * patient16 = new Patient("nom16", "prenom", "adresse", 0, "tours", 0, 16, 19, "dz", ressources);
	Patient * patient17 = new Patient("nom17", "prenom", "adresse", 0, "tours", 0, 19, 25, "dz", ressources);
	Patient * patient18 = new Patient("nom18", "prenom", "adresse", 0, "tours", 0, 20, 2, "dz", ressources);
	Patient * patient19 = new Patient("nom19", "prenom", "adresse", 0, "tours", 0, 90, 16, "dz", ressources);

	patientList.push_back(*patient1);
	patientList.push_back(*patient2);
	patientList.push_back(*patient3);
	patientList.push_back(*patient4);
	patientList.push_back(*patient5);
	patientList.push_back(*patient6);
	patientList.push_back(*patient7);
	patientList.push_back(*patient8);
	patientList.push_back(*patient9);
	patientList.push_back(*patient10);
	patientList.push_back(*patient11);
	patientList.push_back(*patient12);
	patientList.push_back(*patient13);
	patientList.push_back(*patient14);
	patientList.push_back(*patient15);
	patientList.push_back(*patient16);
	patientList.push_back(*patient17);
	patientList.push_back(*patient18);
	patientList.push_back(*patient19);

	// TRIE
	sort(patientList.begin(), patientList.end(), SortPatient::SortPatient());

	multimap<int, vector<Creneau>> mp;
	vector<Creneau> vec;
	Creneau creneau;

	// Ajout des CRENEAUX
	for (int i = 0; i < 52; i++)
		vec.push_back(creneau);

	// Ajout des RESSOURCES (4 ressources)
	for (int i = 1; i <= 4; i++)
		mp.insert(pair<int, vector<Creneau>>(i, vec));

	int dureeParRessource;

	// Passage des patients un par un
	for (vector<Patient>::iterator itP = patientList.begin(); itP != patientList.end(); ++itP)
	{
		// Calcul de la dur�e n�cessaire par ressource
		dureeParRessource = itP->getDureeEstime() / itP->getRessources()->size();

		// Passage des ressources une par une pour un client donn�
		for (vector<int>::iterator itR = itP->getRessources()->begin(); itR != itP->getRessources()->end(); ++itR)
		{
			auto search = mp.find(*itR);

			// Pour une ressources donn�e, d'un client donn�e, passage des cr�neaux un par un pour lui trouver une place
			for (vector<Creneau>::iterator itC = search->second.begin(); itC != search->second.end(); ++itC)
			{
				if (itC->getDisponible())
				{
					// Calcul du nombre de cr�neau n�cessaire en fonction du nombre de ressources et de la dur�e estim�e
					double nbCreneau = itP->getDureeEstime() / itP->getRessources()->size();
					nbCreneau = nbCreneau / 15;
					nbCreneau = ceil(nbCreneau);

					// Dans le patient concern�, ajout d'un indicateur pour lui indiquer ou se trouve son rendez-vous dans une ressource donn�e (n�cessaire pour l'affichage)
					itP->getHeurePassage()->find(*itR)->second = distance(search->second.begin(), itC);

					// R�servation d'autant de cr�neaux n�cessaires
					for (int i = 0; i < nbCreneau; i++)
					{
						itC->setDisponible(false);
						itC->setPatient(*itP);
						itC++; // MODIFIER ICI CAR DEPASSEMENT POSSIBLE (2 jours)
					}

					// Reservation trouv�e donc on passe � la ressource suivante
					break;
				}
			}
		}
	}
	
	// Affichage

	// Passage des patients un par un
	for (vector<Patient>::iterator itP = patientList.begin(); itP != patientList.end(); ++itP)
	{
		int heure, minute = 0;

		cout << itP->getNom() << endl;

		// Passage des ressources une par une pour un patient donn�e
		for (multimap<int,int>::iterator itR = itP->getHeurePassage()->begin(); itR != itP->getHeurePassage()->end(); ++itR)
		{
			// Calcul des heures
			heure = (int)itR->second / 4;

			// Calcul des minutes
			if (itR->second % 4 != 0)
			{
				if (itR->second % 4 == 1)
					minute = 15;
				else if (itR->second % 4 == 2)
					minute = 30;
				else
					minute = 45;
			}

			cout << "Ressource " << itR->first << " : " << heure + 8 << " H " << minute << endl;
		}
	}
}

bool Patient::operator==(Patient patient1)
{
	if (this->nom._Equal(patient1.nom))
		return true;
	else
		return false;
}