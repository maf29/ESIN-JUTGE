 #include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class pila { // pila en memòria dinàmica
   public:
     pila();
     // Crea pila buida
 
     ~pila();
     // Destrueix el p.i.
 
     pila(const vector<int> &v);
     // Crea pila amb els elements de v amb el mateix ordre.
 
     nat longitud() const;
     // Retorna el nombre d’elements del p.i.
 
     void mostra() const;
     // Mostra el p.i. pel canal estàndard de sortida.
 
     void fusiona(const pila<T> &p2);
     // Pre: Les piles del p.i. i p2 estan ordenades de menor a major
     // Post: Al p.i. se li han afegit els elements de p2 ordenadament. p2 no es modifica
 
   private:
     struct node {
       T info;
       node* seg;
     };
     node* _cim; // Apunta al cim de la pila
     nat _mida;  // Nombre d’elements de la pila
 
     // Aquí va l’especificació dels mètodes privats addicionals
     void fusiona_aux(vector<int> &aux, const pila<T> &p2);
 };
 
 // Aquí va la implementació del mètode públic fusiona i privats addicionals
template <typename T>
void pila<T>::fusiona(const pila<T> &p2){
// Pre: Les piles del p.i. i p2 estan ordenades de menor a major
// Post: Al p.i. se li han afegit els elements de p2 ordenadament. p2 no es modifica
	
	vector<int> a;
	fusiona_aux(a, p2);
	while (_cim != NULL) {
		node* aux = _cim;  
		_cim = _cim->seg;
		delete aux;
	}
	
	_mida = a.size();
	node *p, *pant = NULL;
	for (int i = 0; i < a.size(); i++) {
		p = new node;
		
		p->info = a[i];
		
		p->seg = NULL;
		if (pant == NULL)
			_cim = p;
		else
			pant->seg = p;
			pant = p;
	}
}
template <typename T>
void pila<T>::fusiona_aux(vector<int> &aux, const pila<T> &p2){
	node* now = _cim;
	node* now_p2 = p2._cim;
	T mida = _mida+p2._mida;
	for(int i = 0; i < mida and (now_p2 != NULL or now != NULL); ++i){
		if(now_p2 == NULL and now != NULL){ 
			aux.push_back(now->info);
			now = now->seg;
		}
		else if(now_p2 != NULL and now == NULL){
			aux.push_back(now_p2->info);
			now_p2 = now_p2->seg;
		}
		else if(now_p2->info < now->info ){ 
			aux.push_back(now_p2->info);
			now_p2 = now_p2->seg;
		}
		else if(now_p2->info > now->info){
			aux.push_back(now->info);
			now = now->seg;
		}
		else if(now_p2->info == now->info){
			aux.push_back(now->info);
			aux.push_back(now_p2->info);
			
			now_p2 = now_p2->seg;
			now = now->seg;
		}
	}
}

#include <sstream>

template <typename T>
pila<T>::pila() : _cim(NULL), _mida(0) {}

template <typename T>
pila<T>::~pila() {
  while (_cim != NULL) {
    node* aux = _cim;  
    _cim = _cim->seg;
    delete aux;
  }
}

template <typename T>
pila<T>::pila(const vector<int> &v) : _cim(NULL), _mida(v.size()) {
  node *p, *pant = NULL;
  for (int i=0; i<v.size(); i++) {
    p = new node;
    try {
      p->info = v[i];
    } catch (const char* message) {
      cerr << message << endl;
      delete p;
      throw;
    }
    p->seg = NULL;
    if (pant == NULL)
      _cim = p;
    else
      pant->seg = p;
    pant = p;
  }
}

template <typename T>
nat pila<T>::longitud() const {
  return _mida;
}

template <typename T>
void pila<T>::mostra() const {
  node *p = _cim;
  cout << "[";
  if (p != NULL) {
    cout << p->info;
    p = p->seg;
    while (p != NULL) {
      cout << " " << p->info;
      p = p->seg;
    }
  }
  cout << "]" << endl;
}

int main() {
  int n;
  string linea;

  // Obtenim v1
  vector<int> v1;
  getline(cin, linea);
  istringstream ss1(linea);
  while (ss1 >> n) {
    v1.push_back(n);
  }

  // Obtenim v2
  vector<int> v2;
  getline(cin, linea);
  istringstream ss2(linea);
  while (ss2 >> n) {
    v2.push_back(n);
  }

  pila<int> p1(v1);
  pila<int> p2(v2);
  p1.fusiona(p2);
  cout << p1.longitud() << " ";
  p1.mostra();
  cout << p2.longitud() << " ";
  p2.mostra();
  return 0;
}

