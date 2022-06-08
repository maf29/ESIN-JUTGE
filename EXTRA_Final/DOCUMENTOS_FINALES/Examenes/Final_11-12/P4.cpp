TST

metodo comprova si existeix una clau en una classe diccionari implementada amb un arbre ternari de cerca. 
La representació d'aquesta classe és la següent:

template <class Simbol, class Clau, class Valor>
class diccDigital {
	private:
		struct node_tst { // tst = ternary search tree
			Simbol _c;
			node_tst* _esq;
			node_tst* _dret;
			node_tst* _cen;
			Valor _v;
		};
		node_tst *_arrel;
	public:
		bool existeix (const Clau &k) const throw();
		...
};

//***************************************************

	template <class Simbol, class Clau, class Valor>
	bool diccDigital::existeix (const Clau &k) const throw() {
		return rexisteix(_arrel, 0, k);
	}
	
	template <class Simbol, class Clau, class Valor>
	bool diccDigital::rexisteix (node_tst *n, nat i, const Clau &k) const throw() {
	// Cost: Θ(k.length() * log(#simbols))
		bool res = false;
		if (n != NULL) {
			if (n->c > k[i]) {	//si la clau que buscamos es menor que la clau de un nodo, ir por la izquierda
				res = rexisteix(n->esq, i, k);
			}
			else if (n->c < k[i]) {	//si la clau que buscamos es mayor que la clau de un nodo, ir por la derecha
				res = rexisteix(n->dret, i, k);
			}
			else { // (n->c == k[i])		//si esta en la central
				if (i == k.length()){		//si la posicion es igual al size de la clau, es que ya hemos encontrado la clau en el diccionario
				// Hem anat trobant tots els símbols de la clau, incloent el símbol especial fi de clau.
					res = true;
				}
				else{	//si todavia no hemos encontrado la clave, sumarle a uno la posicion
					res = rexisteix(n->cen, i+1, k);
				}
			}
		}
		return res;
	}

