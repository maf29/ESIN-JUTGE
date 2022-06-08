1)
a)Escriu la representacio de la classe, ´ es a dir, els atributs privats de la classe diccionari ´
implementada amb un TST.
	struct node_tst {
		node_tst *esq, *dret, *cent;
		char info; // el s´ımbol de final de paraula ´es ’#’
	}
	node_tst *_arrel;
	
b) void comencen(const string &pref, vector<string> &res) const;

void easydial::comencen (const string &pref, vector<string> &out) const throw(error) {
// Pre = out ´es un vector buit
// Post = insereix a out totes les paraules del TST que comencen per pref.
	node_tst *n = _arrel;
	unsigned int i = 0
	while (n != NULL and i < pref.size()) {	
		if (n->info > pref[i]) {	//recorrer por la izquierda si la info es mayor
			n = n->esq;
		}
		else if (n->info < pref[i]) {	//recorrer por la derecha si la info es menor
			n = n->dret;
		}
		else {				//recorrer por la central si la info es igual
			n = n->cent;
			++i;
		}
	}
	
	extreu(n, pref, out);		//llamar funcion privada cuando estamos en el subarbre que contiene la string pref 
}

void easydial::extreu (node_tst *n, const string &par, vector<string> &out) const throw(error) {
// Pre = -
// Post = insereix a out totes les paraules que hi ha en el subarbre n.
	if (n != NULL) {
	
		extreu(n->esq, pref, out);	//recorrer hasta llegar al final del subarbre izquierdo
		
		//tractar el subarbre centran 
		if (n->info == ’#’) {	//mientras no sea el final de la palabra
			out.push_back(par);	#hacer push_back de la palabra
		}
		else {
			extreu(n->cent, pref+n->info, out);
		}
		
		extreu(n->dret, pref, out);	//recorrer hasta llegar al final del subarbre derecho y salir de la funcion
	}
}
