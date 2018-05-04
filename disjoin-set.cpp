#include <bits/stdc++.h>

using namespace std;

// Crio dois ponteiros que server para apontar para
// uma array de v inteiros, um contem o id de cada v
// o outro contem o pai do vertice
int *ids;
int *parents;   

// Essa funcao cria a memoria dos arrays
// e inicia cada um a partir do 0
void makeSet(int size){
    int i;
    
    ids = new int[size];
    parents = new int[size];

    for(i = 0; i < size; ++i){
        ids[i] = i;
        parents[i] = i;
    }
}

// Essa funcao acha o parent de um elemento
// ela acessa o array parent e caso ele n seja x
// ele procura pelo parent do x
int findSet(int x){
    if(parents[x] == x)
        return x;
    else
        return findSet(parents[x]);
}

// Essa funcao junta dois elementos dos parents
// por ordem do menor parent
void unionSet(int x, int y){
    int parentX, parentY;

    parentX = findSet(x);
    parentY = findSet(y);

    if(parentX == parentY)
        return;

    if(parentX < parentY)
        parents[parentY] = parentX;
    else
        parents[parentX] = parentY;
}


//Alguns testes
int main(){

    makeSet(6);

    unionSet(1, 5);
    unionSet(2, 3);
    unionSet(3, 5);

    for(int i = 0; i < 6; i++)
        cout << findSet(i) << endl;
}
