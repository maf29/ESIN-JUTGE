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

	bool hi_ha_cami(nat ini, nat fi) const;
	// Pre: ini i fi són vèrtexs del graf (són menors que n)
	// Post: Retorna un booleà indicant si hi ha camí per anar d’ini a fi

	private:
	     nat n; // Nombre de vèrtexs
	     nat m; // Nombre d’arestes
	     vector<vector<nat> > a; // Vectors amb els successors de cada vèrtex
	 
	     // Aquí va l’especificació dels mètodes privats addicionals
	      void hi_ha_cami(const vector<vector<nat>> &a, vector<bool> &vist, nat ini, nat fi, bool & trobat_cami)const;
};
 
 // Aquí va la implementació del mètode públic hi_ha_cami i privats addicionals
bool graf::hi_ha_cami(nat ini, nat fi) const{
	
	vector<bool> c(n, false);	//lista donde T es que ya es visitada
	bool t = false;
	hi_ha_cami(a, c, ini, fi, t);
	
	return t;
	
	 
}

void graf::hi_ha_cami(const vector<vector<nat>> &a, vector<bool> &vist, nat ini, nat fi, bool & trobat_cami)const{

	if(ini == fi) trobat_cami =  true;
	
	vist[ini] = true;	//empezamos poniendo el primer vertice del que partimos en true
	
	int i = 0;
	while ( i < a[ini].size()){
		if(not vist[ a[ini][i] ]) hi_ha_cami(a, vist, a[ini][i], fi, trobat_cami);
		 ++i;
	}
}



