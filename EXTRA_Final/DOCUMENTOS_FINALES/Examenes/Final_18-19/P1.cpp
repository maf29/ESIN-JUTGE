Diccionaris: TST

a) Escriu els atributs privats de la classe diccionari implementat amb un TST.

class diccionari {
	private:
		struct tst_node {
			char c_;
			tst_node* esq_;
			tst_node* cen_;
			tst_node* dre_;
		};
		tst_node* _arrel;
}


b) Implementa el mètode que retorni quantes claus (paraules) hi ha al diccionari que tinguin com a prefix l’string s 
int prefix(const string& s) const;

	int diccionari::prefix(const string& s) const throw(error) {
	// Pre: s=S
	// Post: Retorna nombre de claus del p.i. que tenen el prefix S
	 	return prefix(_arrel, 0, s);	
	}

	int diccionari::prefix(tst_node* t, nat i, const string& s) throw() {
	// Pre: t=T, i=I, s=S
	// Post: Retorna nombre de claus des del node T que tenen el prefix S
	// des de la posició I
		int n;
		if (t == NULL) n = 0;	//si es null, retorna 0 porque no hay nignua palabra con un caracter s
		else if (i < s.length()) { // Recorrem el prefix
			if (t->c_ > s[i]) n = prefix(t->esq_, i, s);		//si el caracter es mayor que string, recorrer izquierda 
			else if (t->c_ < s[i]) n = prefix(t->dre_, i, s);	//si el caracter es menor que string, recorrer dret
			
			//se suma i para comparar el caracter siguiente de la string 
			else if (t->c_ == s[i]) n = prefix(t->cen_, i+1, s);	//si el caracter es IGUAL que string, recorrer centro
		}else { // Comptem les paraules
			n = (t->c_ == '\0') ? 1 : 0;
			n += prefix(t->esq_, i, s) +
			prefix(t->dre_, i, s) +
			prefix(t->cen_, i, s);
		}
		return n;
	}

