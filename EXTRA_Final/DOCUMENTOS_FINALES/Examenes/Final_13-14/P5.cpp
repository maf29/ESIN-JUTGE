BST

IMPLEMENTAR:		bool es_bst (const Abin<T> &a) throw(); ??

Enunciado:
template <typename T>
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
//*********************************************************************************************
Resolucion:

	template <class T>
	bool es_bst(const Abin<T> &a) throw() {
		return es_bst(a.arrel(), a.final());
	}
	template <class T>
	bool es_bst(const Abin<T>::iterator &it, const Abin<T>::iterator &end) throw() {
		bool res = true;
		if (it != end) {
			res = mes_petit(*it, it.fesq(), end) and mes_gran(*it, it.fdret(), end);
			res = res and es_bst(it.fesq(), end) and es_bst(it.fdret());
		}
		return res;
	}
	template <class T>
	bool mes_petit(const T &x, const Abin<T>::iterator &it, const
	Abin<T>::iterator &end) throw() {
		bool res = true;
		if (it != end) {
			if (*it < x) {
				res = mes_petit(x, it.fesq(), end) and
				mes_petit(x, it.fdret(), end);
			}
			else {
				res = false;
			}
		}
		return res;
	}
	template <class T>
	bool mes_gran(const T &x, const Abin<T>::iterator &it, const Abin<T>::iterator &end) throw() {
		bool res = true;
		if (it != end) {
			if (*it > x) {
				res = mes_gran(x, it.fesq(), end) and
				mes_gran(x, it.fdret(), end);
			}
			else {
				res = false;
			}
		}
		return res;
	}
