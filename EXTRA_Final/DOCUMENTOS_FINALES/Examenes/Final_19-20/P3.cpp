max-heap: 
Es a dir, nomes cal complir que l’element de cada node es major o igual que tots els elements emmagatze-mats en els fills esquerre i dret

template <typename T>
class abin {
	private:
	struct node {
		node *fesq;
		node *fdret;
		T info;
	};
	
	node* _arrel;
	int _sz;
};

a) Implementa un metode de la classe abin que indiqui si aquest arbre es quasi maxheap.

template <typename T>
bool abin<T>::quasi_maxheap() const throw() {
// Pre = -
// Post = torna true si l’arbre binari compleix la propietat
// de quasi maxheap; false en cas contrari.
	
	return quasi_maxheap(_arrel);
}

template <typename T>
bool abin<T>::quasi_maxheap(node *n) const throw() {
// Pre = -
// Post = torna true si el subarbre binari apuntat pel node n
// compleix la propietat de quasi maxheap; false en cas
// contrari.
	bool b = true;
	if (n != NULL) {
		if (n->fesq != NULL) {
			b = n->fesq->info <= n->info and quasi_maxheap(n->fesq);	//los elemento del subarbre esq es menor o igual que el arrel
		}
		if (b and n->fdret != NULL) {
			b = n->fdret->info <= n->info and quasi_maxheap(n->fdret);	//los elemento del subarbre dret es menor o igual que el arrel
		}
	}
	return b
}

b) Indica el cost de la teva solucio en el cas mig respecte el nombre d’elements de l’arbre. Raona la teva resposta.

	En el cas *mig* trobarem que NO es quasi maxheap a la meitat de l’arbre. Aixo vol dir que si l’arbre te n elements haurem recorregut n/2 elements. 
		Per tant el cost sera Θ(n).
	En el cas *pitjor* (el cas que SI sigui quasi maxheap) haurem de recorrer tots els nodes de l’arbre. 
		Per tant el cost tambe sera de l’ordre linial,  Θ(n).
