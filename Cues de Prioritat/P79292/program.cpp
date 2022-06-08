#include <iostream>
#include <queue>
#include <sstream> 
#include <vector> 

using namespace std;


int main () {
    string s;

    getline (cin, s);
    istringstream ss (s);
    int number_of_queue;

    ss >> number_of_queue;
    
    vector <vector <queue <string >>> queue_list;

    for (int i = 0; i < number_of_queue; ++i){

        // Crear cues especifiques per rangs (de major a menor)
        queue <string> coronel;
        queue <string> sergent;
        queue <string> capita;
        queue <string> soldat;


        // Omplir les cues tal com s'indica
        getline(cin, s);

        istringstream ss (s);
        string nom;
        string rang;
        while (ss >> nom){
            ss >> rang;
            if (rang == "capita"){
                capita.push(nom);
            } 
            else if (rang == "sergent"){
                sergent.push(nom);
            } 
            else if (rang == "soldat"){
                soldat.push(nom);
            } 
            else if (rang == "coronel"){
                coronel.push(nom);
            }
        }

        // Guardar per ordre les cues: coronel, capita, sergent, soldat
        vector<queue<string>> prio;
        prio.push_back(coronel);
        prio.push_back(capita);
        prio.push_back(sergent);
        prio.push_back(soldat);

        // Afegir la llista de cues a la llista general
        queue_list.push_back(prio);
    }
    
    cout << "SORTIDES" << endl << "--------";
    while (getline(cin, s)) {
    
        istringstream ss(s);
        string command;
        ss >> command;
        
        if (command == "ENTRA"){
            string name;
            string rang;
            ss >> name;
            ss >> rang;

            int queue;
            ss >> queue;
            queue--;
           if (queue >= 0 and queue < number_of_queue){
                if (rang == "capita"){
                    queue_list[queue][1].push(name);
                } 
                else if (rang == "sergent"){
                    queue_list[queue][2].push(name);
                } 
                else if (rang == "soldat"){
                    queue_list[queue][3].push(name);
                } 
                else if (rang == "coronel"){
                    queue_list[queue][0].push(name);
                }
            }

        } 
        else if (command == "SURT" ){
            int queue;
            ss >> queue;
            queue--;
            if (queue >= 0 and queue < number_of_queue){
                    for (int i = 0; i < 4; i++){
                    
                        if (not queue_list[queue][i].empty()){
                        
                            cout << endl << queue_list[queue][i].front();
                            queue_list[queue][i].pop();
                            break;
                        }
                    }
            }
        }
    }
    
    cout << endl << endl << "CONTINGUTS FINALS" << endl << "-----------------";
    for (int i = 0; i < number_of_queue; ++i){
        cout << endl << "cua "<< i+1 << ":"; 
            for (int j = 0; j < 4; j++){
            
                while (not queue_list[i][j].empty()){
                
                    cout << " " << queue_list[i][j].front();
                    queue_list[i][j].pop();
                }
            }
    }
    cout <<endl;
}

