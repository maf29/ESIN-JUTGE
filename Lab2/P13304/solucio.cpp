#ifndef _PILA_HPP
#define _PILA_HPP
#include <cstddef>
using namespace std;

class pila {
  public: 
     pila();	          // constructor
     
     // tres grans
     pila(const pila& p); // constructor per còpia
     ~pila();             // destructor
     pila& operator=(const pila& p); // operador assignació
    
     void apilar(int x);
     void desapilar();
     int cim() const;
     bool es_buida() const;
    
  private:
     struct node { // definició de tipus privat
        node* seg; // punter al següent 'node'
        int info;
     };
     
     node* _cim; // la pila consisteix en un punter al node del cim
                 
     // mètode privat de classe per alliberar memòria; allibera la cadena de 
     // nodes que s'inicia en el node \emph{n}. 
     static void esborra_pila(node* n);
     
     // mètode privat de classe per realitzar còpies; còpia tota la cadena de nodes 
     // a partir del node apuntat per \emph{origen} i retorna un punter al node inicial de 
     // la còpia; la paraula reservada const indica que no es pot modificar el valor
     // apuntat pel punter \emph{origen}.
     static node* copia_pila(const node* origen);
};
#endif

// -------------------------
// MÈTODES PRIVATS DE CLASSE
// -------------------------

void pila::esborra_pila(node* n) {
   if (n != NULL) {
      esborra_pila(n->seg); // p-$>$seg equival a (*p).seg 
      delete n; // allibera la memòria de l'objecte apuntat per \emph{n}.
   }
}

// és necessari posar ¿pila::node¿ com tipus del resultat per què ¿node¿ 
// està definit de la classe pila
pila::node* pila::copia_pila(const node* origen) {
   node* desti = NULL;
   if (origen != NULL) {
      desti = new node;
      desti->info = origen->info;
      
      // copia la resta de la cadena
      desti->seg = copia_pila(origen->seg);  
   }
   return desti; 
}

// -------------------------
// MÈTODES PÚBLICS
// -------------------------
pila::pila() : _cim(NULL) { }

// genera una còpia de la pila apuntada per 'p.\_cim'
pila::pila(const pila& p) {
   _cim = copia_pila(p._cim);
}

// allibera la memòria de la pila apuntada per '\_cim'
pila::~pila() {
   esborra_pila(_cim);
}

pila& pila::operator=(const pila& p) {
   if (this != &p) {
      node* aux = copia_pila(p._cim); 
      esborra_pila(_cim);
      _cim = aux;
   }
   return *this; // retorna una referència a la pila que invoca el mètode.
}

void pila::apilar(int x) {
   node* n = new node;
   n->info = x;
   n->seg = _cim; // connecta el nou node amb el primer node de la pila i
                  // fa que aquest sigui el cim
   _cim = n;
}

void pila::desapilar() {
   node* n = _cim;
   if (_cim != NULL) {
      _cim = _cim->seg;
      delete n;
   }
   // faltaria tractar l'error de pila buida
}

int pila::cim() const {
   if (_cim != NULL) {
      return _cim->info;
   }
   // faltaria tractar l'error de pila buida
   return 0;
}

bool pila::es_buida() const {
   return _cim == NULL;
}
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	
	string serie;
	while(getline(cin, serie)){
		int num;
		istringstream s(serie);
		pila par, impar;
		
		while(s>>num){
			if(num%2 == 0) par.apilar(num);
			else impar.apilar(num);
		}
		
		//Imprimiremos los elementos de la pila par de froma inversa
		
		bool vacia = true;
		if(par.es_buida()) vacia = false; //si par es false
		while(not par.es_buida()){
			cout << par.cim();//Imprimer el numero que esta en la cima que es el numero mayor de la pila par
			par.desapilar();
			
			if(not par.es_buida()) cout << " ";
		}
		
		//Imprimiremos los elementos de la pila par de froma inversa
		
		if(not impar.es_buida() and vacia) cout << " "; //Si la lista impar no es vacia y la par tampoco lo es, hacer un espacio entre el ultimo elemento par y el primero impar que se va al imprimir
		while(not impar.es_buida()){
			cout << impar.cim();//Imprimer el numero que esta en la cima que es el numero mayor de la pila par
			impar.desapilar();
			
			if(not impar.es_buida()) cout << " ";
		}
		
		cout << endl;
	}

}
