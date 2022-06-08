#include <vector>
#include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 class graf {
   // Graf dirigit i no etiquetat.
   // Les arestes es guarden en una matriu d’adjacència.
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
     vector<vector<bool> > a; // Matriu d’adjacència
 
     // Aquí va l’especificació dels mètodes privats addicionals
     static nat quants_succ_succ(vector<nat> aux);
 };
 
 // Aquí va la implementació del mètode públic quants_succ_succ i privats addicionals
vector<nat> graf::quants_succ_succ() const{
	vector<nat> res;
	vector<nat> aux;
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){ //sucesores de a[i]
			if(a[i][j] == true){
				for(int z = 0; z < n; ++z){
					if(a[j][z] == true){
						aux.push_back(z);
					}
				}
			}
		}
		
		if(aux.size() > 0){
			nat num = quants_succ_succ(aux);
			res.push_back(num);
		}
		else{
			res.push_back(0);
		}
		aux.clear();
	}
	
	return res;
}

nat graf::quants_succ_succ(vector<nat> aux){
//Pre: aux contiene todos los sucesores de los sucesores de un vertice
//Post: retorna el numero de sucesores de sucesores sin repetir de un vertice
	int quants = 0;
	for(int i = 0; i < aux.size(); ++i){
		++quants;
		for(int j = i+1; j < aux.size(); ++j){
			if(aux[i] == aux[j]) --quants;
		}
	}
	return quants;
}
#include <iostream>
using namespace std;

graf::graf() : n(0), m(0) {}

graf::~graf() {}

void graf::llegeix() {
  // Llegim el nombre de vèrtexs i arestes
  cin >> n >> m;

  // Creem la matriu d'adjacència
  a = vector<vector<bool> >(n, vector<bool>(n, false));

  // Llegim les m arestes
  nat u, v;
  for(nat i = 0; i < m; i++) {
    cin >> u >> v; // Aresta que connecta vèrtex u amb vèrtex v
    a[u][v] = true;
  }
}

int main() {
  graf g;
  g.llegeix();
  vector<nat> resultat = g.quants_succ_succ();
  for(nat i=0; i<resultat.size(); i++) {
    cout << resultat[i] << " ";
  }
  cout << endl;
  return 0;
}
