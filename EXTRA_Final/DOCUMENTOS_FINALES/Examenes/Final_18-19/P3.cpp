template <class Clau, class Valor>
bool dicc<Clau, Valor>::operator==(const dicc &d) const throw() {
// Pre: true
// Post: Retorna true si els dos diccionaris (d i el p.i.) tenen
// els mateixos parells <clau, valor>, false en cas contrari.
	 bool iguals = true;
	 if (_quants != d._quants){
	 //no tenen el mateix size de words
	 	iguals = false;
	 }
	 // Recorrem tots els parells <clau, valor> 
	 // del diccionari del p.i. i mira si 
	 // existeixen en els diccionari d
	 int i=0;
	 while (i<_M and iguals) {//recorre taula p.
		 node_hash* n = _taula[i];
		 while (n != NULL and iguals) {
		 //recorre taula i mira si existeixen als 2 dicc
			 iguals = d.existeix(n->_c, n->_v);
			 n = n->seg;
		 }
		 ++i;
	 }
	 return iguals;
}
template <class Clau, class Valor>
bool dicc<Clau, Valor>::existeix(Clau c, Valor v) const throw() {
// Pre: true
// Post: Retorna true si el parell <c,v> existeix, false en cas contrari.
	 bool trobat = false;
	 int i = h(c); //retorna posicio corresponent de la clau  a la taula implicita 
	 node_hash* n = _taula[i];
	 while (n != NULL and not trobat) {
	 //recorre mentre no es troba el parell
		 if (n->_c == c){//clau trobada
		 	trobat = true;
		 }
		 else{//no s'ha trobat la clau-->seg valor
		 	n = n->seg;
		 }
	 }
	 //comprovem si el valor tmb coincideix
	 return trobat and n->_v == v; 
}
