#pragma once
#include<map>

using namespace std;

class Multimap
{
public:
	Multimap();
	multimap<int, string> addValue(multimap<int, string> mm);
	void affiche(multimap<int, string> mm);
	void saisieCle(multimap<int, string> mm);
	multimap<int, string> supprimerElement(multimap<int, string> mm);
};