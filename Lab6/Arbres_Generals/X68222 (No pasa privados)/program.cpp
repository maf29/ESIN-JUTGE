#include <iostream>
#include <stack>
 #include <cstdlib>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class Arbre {
 
 public:
   // Construeix un Arbre format per un únic node que conté a x.
   Arbre(const T &x);
 
   // Tres grans.
   Arbre(const Arbre<T> &a);
   Arbre& operator=(const Arbre<T> &a);
   ~Arbre() throw();
 
   // Col·loca l’Arbre donat com a primer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
   void afegir_fill(Arbre<T> &a);
 
   static const int ArbreInvalid = 400;
 
   // Indica que si l’arbre és n-ari (tots els nodes excepte les fulles són de grau n)
   bool nari(nat n) const;
 
 private:
   Arbre(): _arrel(NULL) {};
   struct node {
     T info;
     node* primf;
     node* seggerm;
   };
   node* _arrel;
   static node* copia_arbre(node* p);
   static void destrueix_arbre(node* p) throw();
 
   // Aquí va l’especificació dels mètodes privats addicionals
   static bool nari(nat n, node* now);
 };
 
 // Aquí va la implementació del mètode nari
template <typename T>
bool Arbre<T>::nari(nat n) const{
	return nari(n, _arrel);
}

template <typename T>
bool Arbre<T>::nari(nat n, node* now){
	if(now != NULL){//hi ha arbre
		if(now->primf != NULL){	//No sea fulla
			nat cont = 0;
			node *aux = now->primf;
			while (aux != NULL){	//recorre. contem el grau de cada node
				++cont;
				aux = aux->seggerm;
			}
			
			if(cont != n) return false;
		}
		if(now->primf != NULL) nari(n, now->primf);
		if(now->seggerm != NULL) nari(n, now->seggerm);	
	}
	
	return true;
}

//*******************************************************************************
/*
template <typename T>				
typename Arbre<T>::node* Arbre<T>::copia_arbre(node* p) { 
  node* aux = NULL;
  if (p != NULL) {
    aux = new node;
    try {
      aux -> info = p -> info;
      aux -> primf = aux -> seggerm = NULL;
      aux -> primf = copia_arbre(p -> primf);
      aux -> seggerm = copia_arbre(p -> seggerm);
    }
    catch (...) {
      destrueix_arbre(aux);
    }
  }
  return aux;
}

template <typename T>	
void Arbre<T>::destrueix_arbre(node* p) throw() { 
  if (p != NULL) {
    destrueix_arbre(p -> primf);
    destrueix_arbre(p -> seggerm);
    delete p;
  }
}

template <typename T>	
Arbre<T>::Arbre(const T &x) {
  _arrel = new node; 
  try {
    _arrel -> info = x;
    _arrel -> seggerm = NULL;
    _arrel -> primf = NULL;
  } 
  catch (...) {
    delete _arrel;
    throw;
  }
}

template <typename T>	
Arbre<T>::Arbre(const Arbre<T> &a) { 
  _arrel = copia_arbre(a._arrel);
}

template <typename T>	
Arbre<T>&  Arbre<T>::operator=(const Arbre<T> &a) { 
  Arbre<T> tmp(a);
  node* aux = _arrel;
  _arrel = tmp._arrel;
  tmp._arrel = aux;
  return *this;
}

template <typename T>	
Arbre<T>::~Arbre() throw() { 
  destrueix_arbre(_arrel);
}

template <typename T>	
void Arbre<T>::afegir_fill(Arbre<T> &a) { 
  if (_arrel == NULL or a._arrel == NULL or 
    a._arrel -> seggerm != NULL) {
    throw ArbreInvalid;
  }
  a._arrel -> seggerm = _arrel -> primf;
  _arrel -> primf = a._arrel;
  a._arrel = NULL;
}

// Llegeix un arbre general des de cin i el retorna.
Arbre<int> arbre() {
  int valor, nf;
  cin >> valor >> nf;
  Arbre<int> a(valor);
  stack<Arbre<int> > pa;
  while (nf>0) {
    pa.push(arbre());
    nf--;
  }
  while (not pa.empty()) {
    a.afegir_fill(pa.top());
    pa.pop();
  }
  return a;
}

int main() {
  int n;
  Arbre<int> a(arbre());
  while (cin >> n) {
    cout << n << "-ari: " << (a.nari(n) ? "SI" : "NO") << endl;
  }
  return 0;
}
*/
