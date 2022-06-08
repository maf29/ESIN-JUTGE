template <class Clau, class Valor>
void dicc<Clau, Valor>::rehash() throw(error) {
//Pre: -
//Post: duplica la mida de la taula i recol·loca totes les claus i valors en la nova taula 

	//t es la nova taula duplicada
	 node_hash** t = new (node_hash*)[_M*2]; 
	_M *= 2; //duplicar el size
	 for (int i=0; i < _M; ++i) { //inicialitzar taula
	 	t[i] = NULL;
	 }
	 for (int i=0; i < _M/2; ++i) {//recorre taula original
		 node_hash *n = _taula[i];
		 while (n != NULL) {
		 //inserir els parells <clau.valor> a la nova taula duplicada
			 node_hash *aux = n->seg;
			 insereix(t, n);
			 n = aux; //next posicio
		 }
	 }
	 //borrar taula original i assignar la nova duplicada
	 delete[] _taula; 
	 _taula = t;
}

template <class Clau, class Valor>
void dicc<Clau, Valor>::insereix(node_hash** t, node_hash *n)
throw() {
//Pre:-
//Post: Insereix a la taula el node <clau,valor>
	 int i = hash(n->k);//h(clau)
	 n->seg = t[i]; //arreglar punter
	 t[i] = n; //assignar el node a la posicio actual
}
