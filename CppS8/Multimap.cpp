#include "Multimap.h"
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Constructeur par défaut
Multimap::Multimap()
{
	multimap<int,string> mm;
	mm = addValue(mm);
	affiche(mm);
	saisieCle(mm);
	mm = supprimerElement(mm);
	affiche(mm);
}

// Demande à l'utilisateur de remplir le multimap
multimap<int,string> Multimap::addValue(multimap<int, string> mm)
{
	string chaine = "";
	string cle;

	cout << "--- AJOUT DES VALEURS DANS LE MULTIMAP - end pour quitter---" << endl;

	// Tant que l'utilisateur n'a pas écrit le mot end
	while (1)
	{
		cout << "Saisir une chaine : ";
		cin >> chaine;
		
		if (chaine._Equal("end"))
			break;

		// Saisie de la cle + verification de la saisie
		do {
			cout << "Saisir une cle : ";
			cin >> cle;
		} while (!all_of(cle.begin(), cle.end(), ::isdigit));

		mm.insert(pair<int, string>(stoi(cle), chaine));
	}

	return mm;
}

// Recherche la chaine en fonction de la clé saisie par l'utilisateur
void Multimap::saisieCle(multimap<int, string> mm)
{
	string cle;

	cout << endl << endl << "--- RECHERCHE DE CHAINE A PARTIR D'UNE CLE - end pour quitter ---" << endl;

	// Tant que l'utilisateur n'a pas écrit le mot end
	while (1)
	{
		// Saisie de la cle + verification de la saisie
		cout << "Saisir une cle : ";
		cin >> cle;

		if (cle._Equal("end"))
			break;

		// Récupération de l'iterateur qui pointe sur la pair souhaitee
		auto search = mm.find(stoi(cle));

		// Si la cle a ete trouvee
		if (search != mm.end())
			cout << search->first << " => " << search->second << endl;
		else // Si la cle n'existe pas dans le multimap
		{
			// Recherche de la pair la plus proche de la cle
			search = mm.upper_bound(stoi(cle));

			// Si une cle a ete trouvee
			if (search != mm.end())
				cout << search->first << " => " << search->second << endl;
		}
	}
}

// Supprimer des elements du multimap en fonction de la saisie utilisateur
multimap<int, string> Multimap::supprimerElement(multimap<int, string> mm)
{
	bool erase = false;
	string saisie, value;

	cout << endl << endl << "--- SUPPRESSION - end pour quitter ---" << endl;

	// Tant que l'utilisateur n'a pas écrit le mot end
	while (1)
	{
		cout << "Saisir une chaine : ";
		cin >> saisie;

		if (saisie._Equal("end"))
			break;
	
		// Pair d'une multimap passee une a une
		for (auto search = mm.begin(); search != mm.end();)
		{
			// Recuperation de la chaine et non de la cle
			value = search->second;

			// Sur la chaine courante, test si les caracteres saisies par l'utilisateur apparaisse dans la chaine.
			for (char& c : saisie) {

				// Si présence alors suppression de la pair du multimap
				if (value.find(c) != string::npos)
				{
					search = mm.erase(search);
					erase = true;
					break;
				}
			}

			// Si suppresion d'une chaine alors pas d'incrementation de l'iterateur car la methode erase() retourne directement l'iterateur sur la pair suivante.
			if (!erase)
				++search;
			else
				erase = false;
		}
		affiche(mm);
	}
	return mm;
}

// Affichage de l'ensemble des elements d'une multimap
void Multimap::affiche(multimap<int, string> mm)
{
	cout << endl << endl << "--- AFFICHAGE ---" << endl;

	for (multimap<int, string>::iterator it = mm.begin(); it != mm.end(); ++it)
		cout << (*it).first << " => " << (*it).second << '\n';
}

