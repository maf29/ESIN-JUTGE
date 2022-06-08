AVL

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

un vector ordenat d’elements construeix un AVL

	template <typename T>
	abin<T>::abin(const vector<T> &v) throw(error) : _sz(v.size()){
	// Pre: v ´es un vector ordenat de manera creixent.
	// Post: construeix un AVL a partir dels elements de v.
		_arrel = crea_AVL(v, 0, v.size() - 1);
	}

	template <typename T>
	typename abin<T>::node* abin<T>::crea_AVL(const vector<T> &v, unsigned int e, unsigned int d) throw(error) {
	// Pre: v ´es un vector ordenat de manera creixent;
	// 0 <= e,d < v.size().
	// Post: retorna l’AVL corresponent al subvector v[e...d].
		node *nou;
		if (d < e) nou = NULL;
		else {
			int m = (e + d)/2;
			nou = new node;
			try {
				nou->info = v[m];
				nou->fesq = crea_AVL(v, e, m-1);
			}
			catch (error) {
				delete nou;
				throw;
			}
			try {
				nou->fdret = crea_AVL(v, m+1, d);
			}
			catch (error) {
				esborra(n->fesq);
				delete nou;
				throw;
			}
		}
		return nou;
	}

	template <typename T>
	void abin<T>::esborra(node *n) throw() {
	// Pre: -
	// Post: esborra l’arbre apuntat per n.
		if (n != NULL) {
			esborra(n->fesq);
			esborra(n->fdret);
			delete n;
		}
	}
