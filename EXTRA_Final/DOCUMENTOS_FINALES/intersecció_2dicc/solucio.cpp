#include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 typedef unsigned int nat;
 
template <typename Clau>
class dicc {

	public:
	// Constructora per defecte. Crea un diccionari buit.
	dicc();

	// Destructora
	~dicc();

	// Insereix la clau k en el diccionari. Si ja hi era, no fa res.
	void insereix(const Clau &k);

	vector<Clau> interseccio(const dicc<Clau> &d2) const;
	// Pre: True
	// Post: Retorna un vector amb les claus de la intersecció del p.i. amb d2
	// ordenades de menor a major

	private:
	struct node {
		Clau _k;      // Clau
		node* _esq;   // fill esquerre
		node* _dret;  // fill dret
		node(const Clau &k, node* esq = NULL, node* dret = NULL);
	};
	node *_arrel;

	static void esborra_nodes(node* m);
	static node* insereix_bst(node *n, const Clau &k);

	// Aquí va l’especificació dels mètodes privats addicionals
	static void interseccio_aux(node* n , node* m,vector<Clau> &aux,const dicc<Clau> &d2);
	static void ordenacion_vector(vector<Clau> &aux);
};
 
 // Aquí va la implementació dels mètodes públics i privats
template <typename Clau>
vector<Clau> dicc<Clau>::interseccio(const dicc<Clau> &d2) const{
// Pre: True
// Post: Retorna un vector amb les claus de la intersecció del p.i. amb d2
// ordenades de menor a major
	vector<Clau> aux; 
	node* n = _arrel;
	node* m = d2._arrel;
	interseccio_aux(n, m, aux, d2);
	ordenacion_vector(aux);
	return aux;
     
}
template <typename Clau>
void dicc<Clau>::interseccio_aux(node* n , node* m, vector<Clau> &aux,const dicc<Clau> &d2){
//Interseccion = ambos los contienene
	node* n2 = NULL;
	if(n!= NULL and m!=NULL){ //No ambos arboles sean vacíos
		
		if(n->_k == m->_k){
			
			interseccio_aux(n->_esq, m->_esq, aux, d2);
			
			aux.push_back(m->_k);
			
			interseccio_aux(n->_dret, m->_dret, aux, d2);
			
		}
		else if(n->_k > m->_k){
			if(n->_esq != NULL){
				interseccio_aux(n->_esq, m, aux, d2); 
				interseccio_aux(n,m->_dret, aux, d2);
			}
			else interseccio_aux(n,m->_dret, aux, d2);
			
		}
		else{ // n->_k < m->_k
			if(m->_esq != NULL){
				interseccio_aux(n,m->_esq, aux, d2); 
				interseccio_aux(n->_dret, m, aux, d2);
			}
			else interseccio_aux(n->_dret, m, aux, d2);
			
		}
	}

}
template <typename Clau>
void dicc<Clau>::ordenacion_vector(vector<Clau> &aux){
	int len = aux.size();
	for(int i=0; i<len-1; i++)
		for(int j=i+1; j<len; j++) {
		    ///Si encontramos un duplicado
			    if(aux[i] == aux[j]) {

				///Lo vamos intercambiando hasta que quede al final
				for(int k=j;k<len-1;k++)
				   swap(aux[k], aux[k+1]);

				///Disminuimos la longitud en 1, lo que significa
				///que se elimina un elemento
				len--;

				///Disminuimos a j para que se quede en el mismo
				///lugar (vease que el elemento que estaba en esa
				///posicion fue eliminado, si no disminuimos j en 1
				///nos saltamos un valor por analizar).
				j--;
		    }
      }
    
     for(int i = aux.size()-1; i >= len; --i){
     	aux.pop_back();
     }
	
}

 #include <sstream>
using namespace std;

template <typename Clau>
dicc<Clau>::dicc() : _arrel(NULL) {}

template <typename Clau>
dicc<Clau>::~dicc() {
  esborra_nodes(_arrel);
}

template <typename Clau>
void dicc<Clau>::insereix(const Clau &k) {
  _arrel = insereix_bst(_arrel, k);
}

template <typename Clau>
void dicc<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
dicc<Clau>::node::node (const Clau &k, node* esq, node* dret) :
	_k(k), _esq(esq), _dret(dret) {
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::insereix_bst(node *n, const Clau &k) {
  if (n == NULL) {
    return new node(k);
  }
  else {
    if (k < n->_k) {
      n->_esq = insereix_bst(n->_esq, k);
    }
    else if (k > n->_k) {
      n->_dret = insereix_bst(n->_dret, k);
    }
    return n;
  }
}


int main() {
  string linea;
  int n;

  // Obtenim d1
  dicc<int> d1;
  getline(cin, linea);
  istringstream ss1(linea);
  while (ss1 >> n) {
    d1.insereix(n);
  }

  // Obtenim d2
  dicc<int> d2;
  getline(cin, linea);
  istringstream ss2(linea);
  while (ss2 >> n) {
    d2.insereix(n);
  }

  vector<int> vr = d1.interseccio(d2);

  for (nat i = 0; i < vr.size(); i++) {
    cout << vr[i] << " ";
  }
  return 0;
}

