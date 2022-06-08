Grafs

b) Un graf torneig es un graf dirigit on per a cada parell de vertexs diferents hi ha exactament un arc, i sense arcs des de cap vertex cap a ell mateix. 

template <typename T>
bool graf<V>::es_torneig() throw() {
// Pre: -
// Post:
	bool trobat = false;
	unsigned int i = 0;
	while (i < _graf.size() and not trobat) {
		unsigned int j = 0;
		trobat = _graf[i][i];
		while (j < _graf[j].size() and not trobat) {
			if (_graf[i][j] == _graf[j][i]) {
				trobat = true;
			}
			else ++j;
		}
		if (not trobat) ++i;
	}
	
	return not trobat;
}
