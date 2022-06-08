Diccionaris: Taules de dispersio

template <typename C, typename V>
class dicc {
	private:
		enum Estat {lliure, esborrat, ocupat};
		struct node_hash {
			C clau;
			V valor;
			Estat est;
		};
		node_hash *_taula;
		nat _quants; // N´umero d’elements guardats al diccionari
		nat _M; // Mida de la taula

		static nat h(const C &c); // Funci´o de dispersi´o

	 public:
		...
		dicc operator-(const dicc &d) const throw(error);
		...
	
};

a) Implementa el metode operator- que torna un nou diccionari amb el resultat de restar dos diccionaris. El resultat de la resta conte les parelles <clau,valor> del primer diccionari (parametre implıcit) les claus del qual no apareixen en el segon diccionari (el que ens passen per parametre).

template <class C, class V>
 dicc dicc<C, V>::operator- (const dicc &d) const throw(error) {
// Pre = -
// Post = torna un nou diccionari amb el resultat d’eliminar
// del diccionari del parametre impl´ıcit totes les claus
// que hi ha en el diccionari d.
	dicc<C, V> nou(_M);
	for (unsigned int i = 0; i < _M; ++i) {
		if (_taula[i].est == dicc::ocupat and not d.conte(_taula[i].clau)) { //si la clau de p.i esta ocupada y no   la contiene d, se inserta en el nuevo diccionario
			
			nou.insereix(_taula[i].clau, _taula[i].valor);	//insertar en el diccionario la palabra que no esta en d
		}
	}
	return nou;
}

template <class C, class V>
dicc<C, V>::dicc (nat &n) throw(error) {
// Pre = n > 0
// Post = crea un nou diccionari la mida de la taula ´es igual
// a n.
	 _M = n;
	_taula = new node_hash[_M];
	_quants = 0;
}

 template <class C, class V>
 dicc<C, V>::node_hash::node_hash () throw(error) {
// Pre = -
// Post = crea un nou node amb estat inicialitzat a lliure.
 	est = dicc::lliure;
}

template <class C, class V>
bool dicc<C, V>::conte (const C &cl) const throw() {
// Pre = -
// Post = torna true si i nom´es si el diccionari impl´ıcit
// cont´e la clau cl; false en cas contrari.

//COSTE CONSTANTE 
	int i = busca_node(cl);
	return _taula[i]::est == dicc:ocupat and _taula[i]::clau == cl;
}

 template <class C, class V>
void dicc<C, V>::insereix(const C &cl, const V &val) throw(error) {
 // Pre = -
 // Post = insereix la parella < cl, val > en el diccionari
 // impl´ıcit. Si la clau ja est`a present en el diccionari
// llavors actualiza el valor associat a aquesta clau.
	 int p = busca_node(cl);
	 if (_taula[p].est == dicc::ocupat and _taula[p].clau == cl) {
	 	_taula[p].valor = val;
	 }
	else {
		_taula[p].clau = cl;
		 _taula[p].valor = val;
		 _taula[p].est = dicc::ocupat;
		 ++_size;
	 }
 }

 template <class C, class V>
 int dicc<C, V>::busca_node (const C &cl) const throw() {
 // Pre = -
 // Post = torna la posici´o de la taula on es troba la clau cl.
 // En cas que no es trobi la clau en el diccionari llavors
 // torna la posici´o de la primera posici´o lliure o
 // esborrada.
 
 
	bool trobat = false;
	int ini = h(cl), i = 0;
	int p = ini%_M, primer = -1;
	while (_taula[p].est != dicc::lliure and not trobat) {
		if (_taula[p].est == dicc::ocupat and _taula[p].clau == cl) {
			trobat = true;
		}
		else {
			if (primer == -1 and _taula[p].est != dicc::ocupat) {
				primer = p;
			}
			++i;
			p = (ini + i)%_M;
		}
	}
	return (not trobat and primer != -1 ? primer : p);
}

b) Indica el cost d’aquest metode en el cas mig i en el cas pitjor respecte el nombre d’elements del diccionari. Raona la teva resposta

	//COSTE CONSTANTE ==> FUNCION CONTÉ
	En el cas *mig* hem de consultar totes les claus del diccionari implıcit i nomes afegir en el nou diccionari aquelles que no estan en el diccionari d. Tenint en compte que el cost de buscar una clau en el diccionari i inserir-ne una de nova te cost Θ(1) en el cas mig, el cost total de operator- es Θ(n) (on n es nombre d’elements del diccionari). ´

	En el cas *pitjor* el cost de buscar una clau en el diccionari o inserir-ne una nova te cost Θ(n) (on n es nombre d’elements del diccionari). Aquest cas es dona quan la funcio de  dispersio no dispersa correctament i totes les claus inserides son sinonimes. Tenint en `
	compte aixo, el cost total de  operator- es Θ(n^2) .
