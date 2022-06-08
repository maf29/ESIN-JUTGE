void variables::unassign(const string &var) throw() {
// Pre: -
// Post: esborra el parell <var, expressio> (Clau, Valor) identificat per la clau var. No fa res si la clau var no esta present a l’estructura.
	bool trobat = false;
	unsigned int p = h(var) % _M; //retorna l'index valid de la taula entre 0 i _M-1 (posició vàlida del param. implicit)
	unsigned int i = 0;
	while ( (_taula[p].estat != variables::lliure) and i < _M and not trobat){
	//recorre si hi ha claus, i no sha trobat per eliminar-la
		if (_taula[p].clau == var and _taula[p].estat == variables::ocupat){ //es troba la clau 
			trobat = true;
		}
		else {//continuem buscant
			++i;
			p = (p + 1) % _M;
		}
	}
	if (trobat) {//clau trobada, eliminem-la
		_taula[p].estat = variables::esborrat;
	}
}
