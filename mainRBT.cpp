#include <iostream>
#include "rbtree.h"
#include<time.h>
#include<random>
using namespace std;

int main(){

    rbtree<int> rbTree;
    stack<int> pila;
    int size = 200;
    for(int i=0; i<7; ++i){
        int num = rand()%(size*2+1);
        rbnode<int>* nod = new rbnode<int>(num);
        rbTree.treeInsert(nod);
        cout<<num<<"  ";
    }
    cout<<endl;
    rbTree.inorderTreeWalk(rbTree.getRoot(), pila);
    for(int i = 0; i<7; ++i){
      int color = pila.top();
      pila.pop();
      int key = pila.top();
      pila.pop();
      cout<< "Llave: " << key <<"  "<< "Color: "<< color << endl;
    }

    /*
    clock_t timer;
    clock_t tInicio;
    clock_t tFinal;
    int contador = 0;
    int bE = 0;
    int bF = 0;
    int size = 1000000;

    random_device rd;
    mt19937 gen(rd());
    srand(time(NULL));
    uniform_real_distribution<> distribution(0, 2000000);
    /*
    //Busqueda random, elementos random
    for(int i=0; i<size; ++i){
        int num =  distribution(gen);
        //int num = 0+rand()%(size*2+1);
        node<int>* nod = new node<int>(num);
        bTree.treeInsert(nod);
    }
    timer = clock()/CLOCKS_PER_SEC;
    srand(time(0));
    while(timer<=10){
        //tInicio = clock();
        int num = (rand()*50)%(size*2+1);
        node<int>* nodo = bTree.treeSearch(num);
        //tFinal = clock();
        timer = (clock()-timer)/CLOCKS_PER_SEC;
        if(nodo != NULL){
            ++bE;
        }else{
            ++bF;
        }
        ++contador;
    }
    */

    /*
    bTree.treeInsert(new node<int>(0));
    node<int>* lastAdded = bTree.getRoot();
    for(int i=1; i<size; ++i){
        node<int>* nod = new node<int>(i);
        lastAdded = bTree.treeInsertSecuencial(nod, lastAdded);
    }
    timer = clock()/CLOCKS_PER_SEC;
    while(timer<=10){
        //int num = distribution(gen);
        int num = (rand()*50)%(size*2+1);
        //tInicio = clock();
        node<int>* nodo = bTree.iterativeTreeSearch(num);
        //tFinal = clock();
        timer = (clock()-timer)/CLOCKS_PER_SEC;
        if(nodo != NULL){
            ++bE;
        }else{
            ++bF;
        }
        ++contador;
    }


    cout<<"Cantidad de Busquedas: "<<contador<<endl;
    cout<<"Cantidad de Busquedas Efectivas: "<<bE<<endl;
    cout<<"Cantidad de Busquedas Fallidas: "<<bF<<endl;
    */
    return 0;
}
