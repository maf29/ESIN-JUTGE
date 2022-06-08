Cues de prioritat ==> MaxHeap   VECTOOOOOOOR

class CuaPrio {
	private:
		nat _nelems; // Nombre d’elements del MaxHeap
		float _h[1000]; // Vector amb les prioritats del MaxHeap
	public:
		...
		void insereix(float p); // Insereix la prioritat p a la cua de prioritat
		...
};

a) Implementa el mètode insereix de la classe CuaPrio. Cal que implementis els mètodes addicionals que utilitzis explícitament.

void CuaPrio::insereix(float p) throw(error) {
// Pre: true
// Post: p s'ha inserit en la cua de prioritat implementada amb un max-heap
	if (_nelems == 1000) throw error(CuaPrioPlena);	//se retorna error porque llega al limite del size de la CuaPrio
	
	++_nelems;	//como se inserta un nuevo elemento, size++
	_h[_nelems] = p;	//inserta el elemento p al final del vector 
	surar(_nelems);
}
void CuaPrio::surar(nat i) throw() {
// Pre: p>0
// Post: Fa surar el node i-èssim fins a restablir l’ordre del max-heap
	nat pare;
	bool fi = false;	
	while (i > 1 and not fi) {	//
		pare = i / 2;		//dividir por la mitad el vector y coger el subvextor
		if (_h[pare] < _h[i]) {	//haciendo que el padre sea mayor que sus hijos
			swap(_h[pare], _h[i]);
			i = pare;		//iterar i poniendo que i sea la mitad del subvector
		}
		else {
			fi = true;
		}
	}
}

b) Calcula el seu cost en funció del nombre d’elements de la cua de prioritat.

L’element s’insereix al darrer nivell de l’arbre i va surant, intercanviant-se amb el pare, fins
arribar a un punt d’equilibri (menor o igual que el pare) o arribant a l’arrel. Per tant com a molt es
faran tants intercanvis com l’altura que tingui l’arbre. Com que els heaps són arbres quasicomplerts (tots els seus nivells estan plens exceptuant el darrer en algunes ocasions), l’altura de
l’arbre és log(n), sent n el nombre d’elements de l’arbre. Deduïm doncs que el cost d’inserir en un
heap és Θ(log n).
Arribarem al mateix resultat si analitzem les iteracions del while(): Com a molt es fan tantes
iteracions com vegades podem dividir i/2 fins arribar a i==1. O sigui dividim i per la meitat, i
aquest per la meitat, i així successivament fins arribar a 1. Per tant log i iteracions, sent i el
nombre d’elements de l’arbre, per tant si n és el nombre d’elements de l’arbre el cost és Θ(log n).
