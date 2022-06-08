#include <vector>
#include <iostream>
using namespace std;
typedef unsigned int nat;

bool cami_x_y(vector<vector<int>> a, vector<bool> c,int ini, int fi){
	bool trobat_cami = false;
	if(ini == fi) trobat_cami = true;
	
	c[ini] = true;	//empezamos poniendo el primer vertice del que partimos en true
	
	int i = 0;
	while ( i < a[ini].size() and not trobat_cami){
		if(not c[ a[ini][i] ]) trobat_cami = cami_x_y(a, c, a[ini][i], fi);
		 ++i;
	}
	
	return trobat_cami;

}

int main(){
	int n, m;	//n = numero de vertices, m = numero de aristas
	cin >> n >> m;
	
	vector <vector<int>> a(n);
	
	int u, v;
	for(int i = 0; i < m; ++i){	//se van a introducir m aristas
		cin >> u >> v;
		a[u].push_back(v);
	}
	
	int x, y;
	cin >> x >> y;
	
	vector<bool> col(n, false);
	bool trobat = cami_x_y(a, col, x, y);
	
	if(trobat)cout <<"yes"<<endl;
	else cout <<"no"<<endl;

}
