Arbres binaris de cerca i llistes

la següent funció que, a partir d'una llista d'enters que és el recorregut en preordre d'un BST, ens retorni el BST corresponent:

Abin<int> recupera_bst (const list<int> &lst);

template class<typename T>
class Abin {
	public:
		Abin() throw(error);
		Abin(const Abin<T> &a) throw(error);
		Abin& operator=(const Abin<T> &a) throw(error);
		~Abin() throw();
		Abin(Abin<T> &fesq, const T &x, Abin<T> &fdret) throw(error);

		bool es_buit() const throw();
		
		friend class iterator;
		Iterador sobre arbres binaris.
		class iterator {
			public:
			friend class Abin;
			iterator() throw();
			T operator*() const throw(error);
			iterator fesq() const throw(error);
			iterator fdret() const throw(error);
			bool operator==(const iterator &it) const throw();
			bool operator!=(const iterator &it) const throw();
			static const int IteratorInvalid = 410;
		};
		iterator arrel() const throw();
		iterator final() const throw();
};

//****************************************************************

	dicc<int> recupera_bst (const list<int> &lst) throw(error) {
		return rrecupera_bst(lst.begin(), lst.end());
	}
	dicc<int> rrecupera_bst (list<int>::const_iterator beg, list<int>::const_iterator end) throw(error) {
		Abin<int> res;
		if (beg != end) {	//mientras no llegamos al final de la lista
			int arrel = *beg;
			++beg;
			
			list<int>::const_iterator it = beg;
			
			while (beg != end and *it < arrel) {
				++it;
			}
			
			//llamadas recursivas para insertar en el arbol
			Abin<int> esq = rrecupera_bst(beg, it);	
			Abin<int> dret = rrecupera_bst(it, end);
			
			res = Abin<int>(esq, arrel, dret);
		}
		
		return res;
	}
