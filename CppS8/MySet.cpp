#include "MySet.h"
using namespace std;

MySet::MySet(void)
{
	set<S_Coord> ms;
	vector<vector<double>>  mvd;
	int pointA, pointB;

	mvd.resize(10);

	// Depuis C++ 11, tu peux utiliser cette boucle pour itérer sur un conteneur
	for (auto &it : mvd)
	{
		it.resize(10);
	}

	// Ajout des dix coordonnées
	ms = addValue(ms, 10);

	DisplaySet(ms);

	// Distance euclidienne TOUT LES POINTS
	mvd = distanceEucliAll(ms, mvd);

	// Distance euclidienne DEUX POINTS
	cout << "Distance entre deux points (0 à 9)" << endl;

	cout << "Point A : ";
	cin >> pointA;

	cout << "Point B :";
	cin >> pointB;

	distanceEucli(ms, pointA, pointB);
}

// Affichage
void MySet::DisplaySet(set<S_Coord> ms){
	cout << "Contenu du vecteur :" << endl;
	for (set<S_Coord>::iterator it = ms.begin() ;it != ms.end(); ++it)
		cout << ' ' << it->d_X << ' ' << it->d_Y << endl;
	cout << "------"<< endl;
}

// Ajout des valeurs dans le set
set<S_Coord> MySet::addValue(set<S_Coord> ms, int number) {
	for (int i = 0; i<number; i++) {
		S_Coord scoord;
		scoord.d_X = i;
		scoord.d_Y = i * 10;
		ms.insert(scoord);
	}
	return ms;
}

// Calcul de la distance euclidienne entre toutes les coordonnees
vector<vector<double>> MySet::distanceEucliAll(set < S_Coord> ms, vector<vector<double>> mvd) {
	double distance;
	int ligneres = 0, colonneres = 0;

	for (auto &itligne : ms) {
		for (auto &itcolonne : ms) {

			double x1 = S_Coord(itligne).d_X;
			double x2 = S_Coord(itcolonne).d_X;
			double y1 = S_Coord(itligne).d_Y;
			double y2 = S_Coord(itcolonne).d_Y;

			distance = (x2 - x1) + (y2 - y1);
			mvd[ligneres][colonneres] = distance;
			cout << mvd[ligneres][colonneres] << ' ';

			ligneres++;
		}
		cout << endl;
		colonneres++;
		ligneres = 0;
	}
	return mvd;
}

// Calcul de la distance euclidienne entre deux coordonnees
void MySet::distanceEucli(std::set<S_Coord> ms, int pointA, int pointB) {
	S_Coord A = *std::next(ms.begin(), pointA);
	S_Coord B = *std::next(ms.begin(), pointB);

	cout << "Distance entre le point " << pointA << " et le point " << pointB << " = " << (B.d_X - A.d_X) + (B.d_Y - A.d_Y) << ' ' << endl;
}

bool operator<(const S_Coord & s1, const S_Coord & s2){
	return s1.d_X < s2.d_X;
}