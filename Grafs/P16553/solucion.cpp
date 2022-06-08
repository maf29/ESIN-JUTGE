//
// Created by tonix on 10/01/2021.
//
#include <vector>
#include <iostream>

using namespace std;


typedef pair<int, int> nod;


bool is_in(vector< pair<int, int> > cami, int c){
    for(auto &p : cami){
        if(p.first == c) return true;
    }
    return false;
}

void cerca_cicles(vector<vector<int>> g, vector< vector< pair<int, int> > > &camins, vector< pair<int, int> > cami, int i, int prof) {
    if(prof > 1 ) {
        for(int j = 1; j < (int)g[i].size(); j++) {
            if(g[i][j] != 0 and !is_in(cami, j)){
                cami.emplace_back(j, g[i][j]);
                cerca_cicles(g, camins, cami, j, prof - 1 );
                cami.pop_back();
            }
        }
    }else{
        if(g[i][0] != 0){
            cami.emplace_back(0, g[i][0]);
            camins.push_back(cami);
        }
    }
}

int main() {
	int n;
	
	while (cin >> n) {
		vector<vector<int>> g(n);	//generar una matriz
		int x;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
			    cin >> x;
			    g[i].push_back(x);
			}
		}

		vector< vector< pair<int, int> > > camins;
		vector< pair<int, int> > cami;
		cami.emplace_back(0, 0);

		cerca_cicles(g, camins, cami, 0, n);

		for(auto & camin : camins) {
		    int sum = 0;
		    for(auto & p : camin) {
			cout << p.first << " ";
			sum += p.second;
		    }
		    cout << "(" << sum << ")" << endl;
		}
		cout << "--------------------" << endl;
	}
}
