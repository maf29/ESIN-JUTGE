#include <vector>
#include <iostream>
using namespace std;
typedef unsigned int nat;

class graf {
// Graf dirigit i no etiquetat.
// Les arestes es guarden en llistes d’adjacència (vector amb els successors).
	public:
	// Constructora per defecte. Crea un graf buit.
	graf();

	// Destructora
	~graf();

	// Llegeix les dades del graf del canal d’entrada
	void llegeix();

	vector<nat> quants_succ_succ() const;
	// Pre: Cert
	// Post: Retorna quants successors diferents tenen els successors de cada vèrtex
	// del graf

	private:
		nat n; // Nombre de vèrtexs
		nat m; // Nombre d’arestes
		vector<vector<nat> > a; // Vectors amb els successors de cada vèrtex

		// Aquí va l’especificació dels mètodes privats addicionals
		static nat quants_succ_succ(vector<nat> &aux);
};
 
 // Aquí va la implementació del mètode públic quants_succ_succ i privats addicionals
vector<nat> graf::quants_succ_succ() const{
	vector<nat> res;
	vector<nat> aux;
	nat num_succ;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < a[i].size(); ++j){	//recorrer los sucesores de a[i]
			for(int z = 0; z < a[a[i][j]].size(); ++z){	//recorrer los sucesores de sucesores
				aux.push_back(a[ a[i][j] ][z]);
			}
		}
		//llamar a la funcion que retorna numero de elementos
		if(aux.size() > 0){
			num_succ = quants_succ_succ(aux);
			res.push_back(num_succ);
		} else{
			res.push_back(0);
		}
		aux.clear();
	}	
	return res;
}
nat graf::quants_succ_succ(vector<nat> &aux){
//Pre:	aux vector que contiene los sucesores de los sucesores
//Post: retornar el numero de sucesores de sucesores que tiene un vertice
	nat contador = 0;
	for(int i = 0; i < aux.size(); ++i){
		++contador;
		for(int j = i+1; j < aux.size(); ++j){
			if(aux[i] == aux[j]){
				contador--;
			}
		}
	}
	return contador;
}


