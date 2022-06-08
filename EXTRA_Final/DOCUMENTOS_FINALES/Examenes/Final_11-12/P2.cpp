template <typename Clau, typename Valor>
void dicc<Clau, Valor>::elimina (const Clau &k) throw() {
//Pre: -
//Post: eliminar una clau d'una classe diccionari implementada amb taules de dispersió amb la tècnica d'encadenaments indirectes.
 
	 nat i = hash(k);
	 node_hash *p = _taula[i], *ant = NULL;
	 
	 bool trobat = false;
	 while (p != NULL and not trobat) { //recorre taula
		 if (p->_k == k) { //clau trobada
		 	trobat = true;
		 }
		 else {//no trobada, seguent valor
			 ant = p;
			 p = p->_seg;
		 }
	 }
	 if (trobat) { //s'ha trobat la clau
	 	//arreglar punters
		 if (ant == NULL) {//primer valor
		 	_taula[i] = p->seg; 
		 }
		 else {//mes d'un valor
		 	ant->seg = p->seg;
		 }
		 //eliminar node
		 delete(p);
		 --_quants;
	 }
}
