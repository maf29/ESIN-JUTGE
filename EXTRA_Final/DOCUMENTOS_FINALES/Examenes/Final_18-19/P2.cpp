Ordenació i eficiència algorísmica

a) Implementa l’acció void ordena(vector<int> &v) 		MergeSort

vector<int> partir(vector<int> &v, nat m) {
// Pre: m>=0
// Post: Parteix els elements de v en dos vectors:
// 1. A v hi queden els seus m primers elements
// 2. Retorna un vector amb els elements de v menys els m primers
	vector<int> v2(v.size()-m);
	for(nat i=0; i<v2.size(); i++)
		v2[i] = v[m+i];
	v.resize(m);
	return v2;
}
vector<int> fusionar(vector<int> &v1, vector<int> &v2) {
// Pre: v1 i v2 estan ordenats
// Post: Retorna un vector ordenat amb tots els elements de v1 i v2
	
	vector<int> v3(v1.size()+v2.size());
	nat j=0, k=0;
	for(nat i=0; i<v3.size(); i++) {
		if (j == v1.size()) {
			v3[i] = v2[k];
			k++;
		} else if (k == v2.size()) {
			v3[i] = v1[j];
			j++;
		} else if (v1[j] < v2[k]) {
			v3[i] = v1[j];
			j++;
		} else {
			v3[i] = v2[k];
			k++;
		}
	}
	return v3;
}

void ordena(vector<int> &v) {
// Pre: true
// Post: Els elements de v estan ordenats de menor a major
	if (v.size()>1) {
		nat m = v.size() / 2;
		// partim el vector v en dos: v i v2
		vector<int> v2 = partir(v, m);
		// ordenem recursivament els vectors v i v2
		mergeSort(v);
		mergeSort(v2);

		// fusionem els vectors v i v2 en v
		v = fusionar(v, v2);
	}
}

b) Calcula el cost asimptòtic de l’acció ordena i de les accions/funcions auxiliars en funció de n, sent n el nombre d’elements del vector v. Raona la teva resposta.

	El cost de partir() i fusionar() un vector de n elements és Θ(n) (la funció fusionar() visita cada element dels vectors v1 i v2 una vegada). Per això el cost d’executar una sola vegada 		l’acció ordena() és lineal o Θ(n).
	Com que ordena() fa dues crides recursives amb vectors que cada vegada són la meitat de grans que els anteriors, tenim la següent equació de recurrència:
		Tordena(n) = 2 · Tordena(n/2) + Θ(n)
		Per tant, a=2, b=2 i k=1, i el cost temporal d'ordenar un vector de n elements és
		Tordena(n) = Θ( n · log(n) )
