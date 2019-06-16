//Utiliza arreglos en lugar de listas enlazadas

#ifndef PILA_H
#define PILA_H
using namespace std;

struct nodo{
	char clave; struct nodo *siguiente;
};

class Pila{
	char *pila;
  	int p;
public:
		
	Pila (int max=100){
		pila = new char[max]; p=0;
	}
	~Pila(){
		delete pila;
	}
	inline void meter (char v){
		pila[p++]=v;
	}
	inline char sacar(){
		return pila [--p];
	}
	inline int vacia(){
		return !p;
	} 
};

#endif
