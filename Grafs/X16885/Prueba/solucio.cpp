#include <vector>
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
 };
 
 // Aquí va la implementació del mètode públic quants_succ_succ i privats addicionals

vector<nat> graf::quants_succ_succ() const{
// Pre: Cert
// Post: Retorna quants successors diferents tenen els successors de cada vèrtex
// del graf
	vector<nat> v;
	vector<nat> succ_succ;
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a[i].size(); j++){
			if(a[i][j]){ //si es true
				for(int z = 0; z < a[j].size(); z++){
					if(a[j][z]) succ_succ.push_back(z);
				}
			}
		}
		int cont = 0;
		for(int j = 0; j < succ_succ.size(); j++){	//mirar si esta repetido
			for(int z = j+1; z < succ_succ.size(); z++){
				if(succ_succ[j] == succ_succ[z]) --cont;
			}
			++cont;
		}
		v.push_back(cont);
		succ_succ.clear();
	}
	
	return v;
}
