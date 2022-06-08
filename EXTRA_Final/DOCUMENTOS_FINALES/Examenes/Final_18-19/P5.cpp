Grafs ==> llistes d’adjacència - arestes

typedef vector<vector<int> > arestes; //Lista de adjacencia con los sucesores de cada vertice

int cami_mes_curt(const arestes &a, int ini, int fi); //retorni el camí més curt per anar d’ini fins a fi. En cas de que no existeixi camí retornar -1

	int cami_mes_curt(const arestes &a, int ini, int fi) {
	// Pre: a conté les arestes del graf en llistes d'adjacència,
	// els vèrtexs que hi apareixen < a.size().
	// ini<a.size(), fi<a.size()
	// Post: Retorna el camí més curt per anar d’ini fins a fi.
	// Si no existeixi camí retorna -1.
		vector<bool> vis(a.size(), false);
		
		int d = -1;
		queue<int> cv;	//guarda els següents vèrtexs a visitar
		queue<int> cd; //la distància per anar de ini a cadascun dels vèrtexs de cv
		
		cv.push(ini);	//poner push del inici porque es el primer vertex que se visita
		
		cd.push(0);
		vis[ini] = true;
		while (not cv.empty() and d == -1) {	//mientras no este vacia y d sea que no se ha encontrado camino
			int v = cv.front(); cv.pop();
			int dv = cd.front(); cd.pop();
			
			if (v == fi) d = dv;
			else {
				// Recorregut pels successors de v
				for(int i = 0; i < a[v].size(); i++) {
					int suc = a[v][i];
					
					if (not vis[suc]) {	//mientra sno haya sido visitado anteriormente
						
						cv.push(suc);	//guardar el sucesor en la cola de sucesores
						cd.push(dv+1);	//guardar la distancia en la cola de distancias
						
						vis[suc] = true;	//marcar el vertex como visitado
					}
				}
			}
		}
		return d;
	}

 
