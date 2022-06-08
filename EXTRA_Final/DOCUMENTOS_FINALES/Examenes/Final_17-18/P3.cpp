void variables::assign(const string &v, const expressio &e) throw(error){
//Pre: -
//Post: e donat un nom de variable i una expressio guarda en la taula de dispersio aquest parell <variable,expressio> (Clau,Valor). Si aquest nom de variable ja existeix s'actualitzara el seu valor
	if (_size/_M > 0.7) {//factor de carrega alt
		redispersio(); 
		//funcio que no cal implementar; 
	}
	bool trobat = false;
	int ini = hash(v), i = 0;
	int p = ini%_M, primer = -1;
	while (_taula[p].estat != variables::lliure and not trobat) {//Buscar el valor mentres hi ha valors
		if (_taula[p]).estat == variables::ocupat and _taula[p].clau == v) {//clau trobada
			trobat = true;
		}
		else {//clau no trobada, incrementem
			if (primer == -1 and _taula[p].estat != variables::ocupat) {//primer cop que s'accedeix i és ocupat
				primer = p;
			}
			++i;
			p = (ini + i*i)%_M;
		}
	}
	//~Acaba bucle~
	if (trobat) {//clau trobada, actualitzar valor
		_taula[p].valor = e;
	}
	else {//clau no trobada, afegir-la
		if (primer != -1) {//ultima posicio lliure
			primer = p;
		}
		//Afegir el nou parell a l'ultima posició (q te estat lliure)
		_taula[primer].clau = v;
		_taula[primer].valor = e;
		_taula[primer].estat = variables::ocupat;
		++_size;
	}
}
//#########---ANNEX--FUNCIÓ REDISPERSIO()---#############
//Es reinserta tota la informació que contenia la taula actual a la nova taula. Caldrà recórrer seqüencialment la taula actual i cadascun dels elements presents s'insereix a la nova taula utilitzant una nova funció de dispersió. Això té un cost proporcional a la grandària de la taula (O(n)) però es fa molt de tant en tant.




