#include "llista.hpp"
#include <iostream>
void Llista::fusiona_suma(Llista &l2, nat n) {
    // El const en funció de l1 i l2 es la suma del tamany de les dues llistes per 2 en els pitjors dels casos
    // es a dir, (l2.size + l2.size) * 2
    // Cost = n
    
    // Exemple amb n=2:
    // p.i. [2 5 3 8 4] => [38 2 5 1 6 3 8 9 4]
    // l2   [1 6 9]     => []
    
 // Llista simplement encadenada, amb fantasma i no circular.
	node *x1 = _prim;
	node *x2 = l2._prim->seg;	//guardar la lista l2 en x
	l2._prim->seg = NULL;	//borrar l2
	l2._long = 0;		//longitud es 1 por el fantasma
	int sum = 0;

	while (x1 != NULL) {
		for (int i = 0; i < n; ++i) {
			if(x1->seg != NULL) {	//recorrer n elementos de x1 para comenzar a insertar los elem de l2
				
				x1 = x1->seg;
				sum = sum + x1->info;	//Sumar elemento x1 a la variable suma
				
			}
		}
		if(x1->seg == NULL) {
			break;
		}else{
			for (int i = 0; i < n; ++i) {	//recorrer n elementos de x2 e insertarlos en x1
				if(x2 != NULL) {
					sum = sum + x2->info;	//Sumar elemento x2 a la variable suma
					
					node *aux = x2->seg;
					x2->seg = x1->seg;
					x1->seg = x2;
					
					
					x1 = x1->seg;
					x2 = aux;
					++_long;
					
				}
			}
		}
	}

	while (x2 != NULL) { 	//si siguien habiendo elementos de la lista x2
		sum = sum + x2->info;	//Sumar elemento x2 a la variable suma
		node *aux = x2->seg;
		x2->seg = x1->seg;
		x1->seg = x2;

		x1 = x1->seg;
		x2 = aux;
		++_long;
	}
	
	
	//insertar en el primer nodo, despues del fantasma, la suma de todos los elementos
	node *p = new node();
	p->seg = _prim->seg;
	p->info = sum;
	_prim->seg = p;
	++_long;

}
