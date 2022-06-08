#include <iostream>
#include <queue>
using namespace std;
//primero se va, el ultimo se va al final
//utilitzem com a pivot el primer element, creem 3 cues i despres les juntem
template <typename T>
void ordena(queue<T> &c){
  if (c.size() > 1){
    T pivot = c.front();

    queue<T> menor;
    queue<T> major;
    queue<T> igual;
    int s = c.size(); //mida de la cua
    for (unsigned int i = 0; i < s; i++){
      T valor = c.front();

      c.pop();
      if (valor == pivot)
        igual.push(valor);
      else if (valor > pivot)
        major.push(valor);
      else
        menor.push(valor);
    }
    ordena(menor);
    ordena(major);
    int s2 = menor.size();
    int s3 = major.size();
    for (unsigned int i = 0; i < s2; i++){
      c.push(menor.front());
      menor.pop();
    }
    for (unsigned int i = 0; i < igual.size(); i++){
      c.push(pivot);
    }
    for (unsigned int i = 0; i < s3; i++){
      c.push(major.front());
      major.pop();
    }
  }
}

