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

	for (vector<int>::iterator itR = ressources.begin(); itR != ressources.end(); ++itR)
	{
		heurePassage.insert(pair<int, int>(*itR, -1));
	}
		
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
	sortie << "Durée totale consultation : " << res.getDureeConsultation() << endl;
	sortie << "Priorité moyene : " << res.getPrioriteMoy() << endl;

	cout << endl;

}

void Patient::testAlgo()
{
	/* ORDRE : 12 / 13 / 7 / 9 / 15 / 14 / 17 / 10 / 6 / 16 / 11 / 19 / 5 / 4 / 2 / 3 / 18 / 8 / 1 */

	string nom;
	vector<Patient> patientList;
	vector<int> ressources{ 1, 2, 3, 4 };

	vector<int> ressources1{ 2, 3};
	vector<int> ressources2{ 2, 4};
	vector<int> ressources3{ 1 };
	vector<int> ressources4{ 1, 4};
	vector<int> ressources5{ 4 };

	Patient * patient1 = new Patient("nom1", "prenom", "adresse", 0, "tours", 0, 20, 1, "dz", ressources1);
	Patient * patient2 = new Patient("nom2", "prenom", "adresse", 0, "tours", 0, 40, 7, "dz", ressources2);
	Patient * patient3 = new Patient("nom3", "prenom", "adresse", 0, "tours", 0, 30, 2, "dz", ressources3);
	Patient * patient4 = new Patient("nom4", "prenom", "adresse", 0, "tours", 0, 80, 10, "dz", ressources4);
	Patient * patient5 = new Patient("nom5", "prenom", "adresse", 0, "tours", 0, 50, 12, "dz", ressources5);
	Patient * patient6 = new Patient("nom6", "prenom", "adresse", 0, "tours", 0, 60, 19, "dz", ressources1);
	Patient * patient7 = new Patient("nom7", "prenom", "adresse", 0, "tours", 0, 48, 50, "dz", ressources2);
	Patient * patient8 = new Patient("nom8", "prenom", "adresse", 0, "tours", 0, 65, 1, "dz", ressources3);
	Patient * patient9 = new Patient("nom9", "prenom", "adresse", 0, "tours", 0, 70, 45, "dz", ressources4);
	Patient * patient10 = new Patient("nom10", "prenom", "adresse", 0, "tours", 0, 100, 16, "dz", ressources5);
	Patient * patient11 = new Patient("nom11", "prenom", "adresse", 0, "tours", 0, 45, 17, "dz", ressources1);
	Patient * patient12 = new Patient("nom12", "prenom", "adresse", 0, "tours", 0, 32, 91, "dz", ressources2);
	Patient * patient13 = new Patient("nom13", "prenom", "adresse", 0, "tours", 0, 29, 64, "dz", ressources3);
	Patient * patient14 = new Patient("nom14", "prenom", "adresse", 0, "tours", 0, 78, 28, "dz", ressources4);
	Patient * patient15 = new Patient("nom15", "prenom", "adresse", 0, "tours", 0, 132, 37, "dz", ressources5);

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

	// TRIE
	sort(patientList.begin(), patientList.end(), SortPatient::SortPatient());

	multimap<int, vector<Creneau>> mp;
	vector<Creneau> vec;
	Creneau creneau;

	// Ajout des CRENEAUX
	for (int i = 0; i < 52; i++)
		vec.push_back(creneau);

	// Ajout des RESSOURCES
	for (unsigned int i = 1; i <= ressources.size() ; i++)
		mp.insert(pair<int, vector<Creneau>>(i, vec));

	int dureeParRessource;
	bool rdvTrouve = true;
	vector<Creneau>::iterator itCreneauTemp;

	// Passage des patients un par un
	for (vector<Patient>::iterator itP = patientList.begin(); itP != patientList.end(); ++itP)
	{
		// Calcul de la durée nécessaire par ressource
		dureeParRessource = itP->getDureeEstime() / itP->getRessources()->size();

		// Passage des ressources une par une pour un client donné
		for (vector<int>::iterator itR = itP->getRessources()->begin(); itR != itP->getRessources()->end(); ++itR)
		{
			auto search = mp.find(*itR);

			// Pour une ressources donnée, d'un client donnée, passage des créneaux un par un pour lui trouver une place
			for (vector<Creneau>::iterator itC = search->second.begin(); itC != search->second.end(); ++itC)
			{
				if (itC->getDisponible())
				{
					// Calcul du nombre de créneau nécessaire en fonction du nombre de ressources et de la durée estimée
					double nbCreneau = itP->getDureeEstime() / itP->getRessources()->size();
					nbCreneau = nbCreneau / 15;
					nbCreneau = ceil(nbCreneau);

					// Test si le patient en question n'a pas un rendez vous pour la même période sur une autre ressource
					for (multimap<int, int>::iterator itR2 = itP->getHeurePassage()->begin(); itR2 != itP->getHeurePassage()->end(); ++itR2)
					{
						// Si == - 1 alors pas de rendez-vous pour une ressource donnée
						if (itR2->second != -1)
						{
							// Si le créneau courant est avant un rendez-vous déjà pris (voir si ce créneau ne va pas débordé sur le rendez-vous plus tard dans la journée).
							if (distance(search->second.begin(), itC) < itR2->second)
							{
								// Test si débordement ou non. Si débordement alors le boolean est à faux et on break pour passer au créneau suivant pour voir si lui ça passe ou non.
								if (distance(search->second.begin(), itC) + nbCreneau > itR2->second)
								{
									rdvTrouve = false;
									break;
								}
							} // Si le créneau courant est après un rendez-vous déjà prit (voir si le rendez-vous déjà pris ne va pas débordé sur le créneau sur lequel on se trouve).
							else if (distance(search->second.begin(), itC) > itR2->second)
							{
								// Test si débordement ou non. Si débordement alors le boolean est à faux et on break pour passer au créneau suivant pour voir si lui ça passe ou non.
								if (distance(search->second.begin(), itC) < itR2->second + nbCreneau)
								{
									rdvTrouve = false;
									break;
								}
							}
							else // Un rendez-vous est déjà pris sur le même créneau sur lequel on se trouve (même heure). Donc passage au créneau suivant.
							{
								rdvTrouve = false;
								break;
							}
						}

						// Garde en mémoire l'itérateur car incrémentation pour voir si les créneaux supérieurs sont libres
						itCreneauTemp = itC;

						// Itération sur les créneaux supérieurs. Si créneaux alors passage du boolean à faux (donc pas de rendez-vous possible sur le créneau sur lequel on se trouve)
						for (int i = 1; i < nbCreneau; i++)
						{
							itC++;

							if (!itC->getDisponible())
							{
								rdvTrouve = false;
								break;
							}
						}

						// Remise de l'itérateur à l'état initial
						itC = itCreneauTemp;
					}
						
					// Quand il n'y a pas de conflit avec les autres rendez-vous
					if (rdvTrouve)
					{
						// Dans le patient concerné, ajout d'un indicateur pour lui indiquer ou se trouve son rendez-vous dans une ressource donnée (nécessaire pour l'affichage)
						itP->getHeurePassage()->find(*itR)->second = distance(search->second.begin(), itC);

						// Réservation d'autant de créneaux nécessaires
						for (int i = 0; i < nbCreneau; i++)
						{
							itC->setDisponible(false);
							itC->setPatient(*itP);
							itC++; // MODIFIER ICI CAR DEPASSEMENT POSSIBLE (2 jours)
						}

						// Reservation trouvée donc on passe à la ressource suivante
						break;
					}
					rdvTrouve = true;
				}
			}
		}
	}

	affichageRendezVous(patientList);
}

void Patient::affichageRendezVous(vector<Patient> patientList)
{
	// Passage des patients un par un
	for (vector<Patient>::iterator itP = patientList.begin(); itP != patientList.end(); ++itP)
	{
		int heure, minute = 0;

		cout << endl << itP->getNom() << endl;

		// Passage des ressources une par une pour un patient donnée
		for (multimap<int, int>::iterator itR = itP->getHeurePassage()->begin(); itR != itP->getHeurePassage()->end(); ++itR)
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

			minute = 0;
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