Arbres binaris de cerca (BST)

template <typename T>
class abin {
	private :
		struct node {
			node *fesq;
			node *fdret;
			T info;
		};
		node* _arrel;
		int _sz;
};

Implementa un metode d’aquesta classe elimina que donat un element x esborra totes les ocurrencies de x de l’arbre. x pot estar repetit!

	template <typename T>
	void abin<T>::elimina(const T &x) throw() {
	// Pre: l’arbre ´es un ABC.
	// Post: esborra els elements igual a x d’aquest arbre.
		elimina(NULL, _arrel, x);
	}

	template <typename T>
	void abin<T>::elimina(node* pare, node *n, const T &x) throw() {
	// Pre: n != NULL i info del node >= que la informaci´o del
	// fesq i < que la informaci´o del f dret.
	// Post: elimina del subarbre apuntat per n totes les
	// ocurr`encies de x.
		if (n != NULL) {
			if (n->info == x) {
				// cal esborrar el node n
				elimina(pare, pare->fesq, x);
				elimina_node(pare, n);
			}
			else if (x < n->info) elimina(n, n->fesq, x);		
			else elimina(n, n->fdret, x);
		}
	}
	
	//funcion normalmente implementada en la clase BST
	
	template <typename T>
	void abin<T>::elimina_node(node* p, node* q) throw() {		
	//Pre: n != NULL i info del node >= que la informaci´o del
	// fesq i < que la informaci´o del f dret.
	// Post: elimina el node q substituint-lo en cas necessari
	// pel seu antecessor.
		if (q->fesq == NULL and q->fdret == NULL) {
		// Cas node fulla
			if (p == NULL) {
				_arrel = NULL;
			}
			else {
				if (p->info >= q->info) p->fesq = NULL;
				else p->fdret = NULL;
			}
			delete q;
		}
		else if (q->fesq == NULL and q->fdret != NULL){
			// Cas fill esquerre buit
			if (p == NULL) {
				_arrel = q->fdret;
			}
			else {
				if (p->info >= q->info) p->fesq = q->fdret;
				else p->fdret = q->fdret;
			}
			delete q;
		}
		else if (q->fesq != NULL and q->fdret == NULL) {
			// Cas fill dret buit
			if (p == NULL) {
			_arrel = q->fesq;
			}
			else {
			if (p->info >= q->info) p->fesq = q->fesq;
			else p->fdret = q->fesq;
			}
			delete q;
		}
		else {
			// Cas els dos fills diferents de buit
			node *pred = obte_pred(q);
			pred->fesq = q->fesq;
			pred->fdret = q->fdret;
			if (p == NULL) {
				_arrel = pred;
			}
			else {
				if (p->info >= q->info) p->fesq = pred;
				else p->fdret = pred;
			}
			delete q;
		}
	}

	template <typename T>
	typename abin<T>::node* abin<T>::obte_pred(node *n) throw() {
	// Pre: n != NULL i info del node >= que la informaci´o del
	// fesq i < que la informaci´o del f dret
	// Post: retorna el node amb el valor predecessor al node n,
	// i a m´es aquest node el desvincula de l’arbre.
		node *pred = n->fesq, *pare = n;

		while (ant->fdret != NULL) {
			pare = pred;
			pred = pred->fdret;
		}

		pare->fdret = pred->fesq;
		pred->fesq = NULL;
		return pred;
	}
