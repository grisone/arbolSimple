#include <stdio.h>
#include <stdlib.h>
struct nodo{
    int dato;
    struct nodo *der;
    struct nodo *izq;
};






typedef struct nodo _nodo;

_nodo *crear(int dato){
    _nodo  *nuevo ;
    nuevo = (_nodo *)malloc(sizeof(_nodo));
    nuevo->dato = dato;
    nuevo->der = NULL;
    nuevo->izq = NULL;
return nuevo;
}

_nodo *addDerecha(_nodo *nodoNuevo, _nodo *raiz){
raiz->der = nodoNuevo;
return raiz;
}

_nodo *addIzquierda(_nodo *nodoNuevo, _nodo *raiz){
raiz->izq = nodoNuevo;
return raiz;
}

void imprimir(_nodo *nodo){
if(nodo != NULL){
   printf("%d", nodo->dato);
   }else{
   printf("dato nulo");
   }
    }

void preOrden(_nodo *raiz){
    if (raiz!= NULL){
        imprimir(raiz);
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}
void inOrden(_nodo *raiz){
if (raiz !=NULL){
    inOrden(raiz->izq);
    imprimir(raiz);
    inOrden(raiz->der);
    }
}
 void postOrden(_nodo *raiz){
    if(raiz != NULL){
        postOrden(raiz->izq);
        postOrden(raiz->der);
        imprimir(raiz);
    }
 }



int main(){
  _nodo *raiz;
  raiz = crear(1);
  raiz->izq = crear(2);
  raiz->der = crear(3);
  raiz->izq->izq =crear(4);
  raiz->der->izq = crear(5);
  raiz->der->der = crear(6);

  printf("\n Preorden (R I D) ");
  preOrden(raiz);
  printf("\n inorden (I D R) ");
  inOrden(raiz);
  printf("\n postorden (D R I)");
  postOrden(raiz);
  return 0;
}

