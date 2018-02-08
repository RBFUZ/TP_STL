#include "MyVector.h"
using namespace std;


MyVector::MyVector (){
	cout<<"Debut prog"<<endl;

	vector<int> vi;
	int input, input2;

	cout << "Inserez 5 valeurs :";
	for (int i=0; i<5; i++){
		cin>>input;
		vi.push_back(input);
	}

	displayIntVector(vi);

	cout << "Choisir un indice pour la supression (min 0, max "<<vi.size()-1<<") :";
	cin >> input;

	vi.erase(vi.begin()+input);

	displayIntVector(vi);

	cout << "Choisir un indice pour l'ajout (min 0, max "<<vi.size()<<") :";
	cin >> input;
	cout << "Quelle valeur ? :";
	cin >> input2;

	vi.insert(vi.begin()+input,input2);

	displayIntVector(vi);

	vi.clear();
}

void MyVector::displayIntVector(vector<int> vi){
	cout << "Contenu du vecteur :";
	for (vector<int>::iterator it = vi.begin() ; it != vi.end(); ++it)
		cout << ' ' << *it;
	cout << endl;
}