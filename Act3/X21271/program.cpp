#include <sstream>
 #include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class dicc {
 
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const Clau &k);
 
     // Retorna quants elements (claus) té el diccionari.
     nat quants() const;
 
     // Pre: El diccionari no està buit. 1 <= i <= j <= quants()
     // Post: Retorna les claus entre la posició i-èssima i j-èssima
     // (comptant-les en ordre ascendent).
     vector<Clau> ijessim(nat i, nat j) const;
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
       nat _n;       // Nombre de nodes del subarbre
       node(const Clau &k, node* esq = NULL, node* dret = NULL);
     };
     node *_arrel;
 
     static void esborra_nodes(node* m);
     static node* insereix_bst(node *n, const Clau &k, bool &ins);
 
     // Aquí va l’especificació dels mètodes privats addicionals
     void ijessim2(nat i,nat j,vector<Clau> &ere,node *nodo,nat ant,nat pos)const;
 };
 
    template <typename Clau>
    vector<Clau> dicc<Clau>::ijessim(nat i, nat j)const{
    // Pre: El diccionari no està buit. 1 <= i <= j <= quants()
    // Post: Retorna les claus entre la posició i-èssima i j-èssima
    // (comptant-les en ordre ascendent).
    // Aquí va la implementació dels mètodes públics i privats
    vector <Clau> ere;
    nat ant;
    if(_arrel!=NULL){

      if(_arrel->_dret!=NULL)ant=_arrel->_n - _arrel->_dret->_n;

      else ant=_arrel->_n;
      //---------------------- Calculem el ordre en Inordre


      if(j<ant){//Cridem a la esquerra ja que es mes petit
        if(_arrel->_esq!=NULL)ijessim2(i,j,ere,_arrel->_esq,ant,1);

      }
      else if(i>ant){//Cridem a la dreta ja que es mes petit
        if(_arrel->_dret!=NULL)ijessim2(i,j,ere,_arrel->_dret,ant,2);

      }
      else{//L'arrel està entre les claus
        if(_arrel->_esq!=NULL)ijessim2(i,j,ere,_arrel->_esq,ant,1);
        ere.push_back(_arrel->_k);
        if(_arrel->_dret!=NULL)ijessim2(i,j,ere,_arrel->_dret,ant,2);

      }


    }
    return ere;





 }
  template <typename Clau>
  void dicc<Clau>::ijessim2(nat i, nat j,vector<Clau> &ere,node *nodo,nat ant,nat pos)const{
    if(nodo!=NULL){
      //pos 1=esq pos 2=dret
      if(pos==1){
        if(nodo->_dret!=NULL)ant=ant -1 -nodo->_dret->_n;

        else ant=ant -1;
      }
      else if(pos==2){
        if(nodo->_esq!=NULL)ant=ant + nodo->_esq->_n + 1;
              


        else ant=ant + 1;
      }
      
      //---------------------- Calculem el ordre en Inordre


      if(j<ant){//Cridem a la esquerra ja que es mes petit
        //cout<<"a"<<endl;
        if(nodo->_esq!=NULL)ijessim2(i,j,ere,nodo->_esq,ant,1);

      }
      else if(i>ant){//Cridem a la dreta ja que es mes petit
        //cout<<ant<<endl;
        if(nodo->_dret!=NULL)ijessim2(i,j,ere,nodo->_dret,ant,2);

      }
      else{//L'arrel està entre les claus
        if(nodo->_esq!=NULL)ijessim2(i,j,ere,nodo->_esq,ant,1);
        ere.push_back(nodo->_k);
        if(nodo->_dret!=NULL)ijessim2(i,j,ere,nodo->_dret,ant,2);
      }
      
    }
  }
