#include <iostream>
#include "llista.hpp"

//Eliminació dels elements de les posicions parells d'una llista doblement encadenada, circular i amb fantasma 

// Pre: True
// Post: S'han eliminat els elements del p.i. de les posicions parells
//       Exemple: [2 5 3 8 1] quedaria [2 3 1]
void Llista::eliminaposicionsparells(){
	node *now = _prim->seg, *aux = now->ant ;
	int cont = 1;
	while(now != _prim){
		if(cont % 2 == 0){
			aux->seg = now->seg; 
			
			now = aux->seg; 
			now->ant = aux; 

			_long--;
		}else{
			aux = now;
			now = now->seg;
		}
		
		cont++;
	}
}
