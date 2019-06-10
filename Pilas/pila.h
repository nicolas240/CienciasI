#ifndef PILA_H
#define PILA_H
using namespace std;

struct nodo{
	char clave; struct nodo *siguiente;
};
class Pila{
	public:
      Pila (int max);
    ~Pila();
		void meter(char V);
		char sacar();
		int vacia();
 	private:
		struct  nodo *cabeza, *z;
 };

Pila::Pila(int max){
	cabeza = new nodo;  z=new nodo;
  	cabeza->siguiente=z; z->siguiente =z; //Centinelas, no guardan informacion
}

Pila::~Pila(){
	struct nodo *t=cabeza;
	while (t!=z){
		cabeza=t;  t->siguiente;  delete cabeza;
	}
}

void Pila:: meter (char v){
	struct nodo *t=new nodo;
	t->clave = v;  t->siguiente=cabeza->siguiente;
	cabeza->siguiente=t;
}

char Pila:: sacar(){
	char x;
	struct nodo *t = cabeza->siguiente;
	cabeza->siguiente = t->siguiente; x=t->clave;
	delete t; return x;
}

int Pila::vacia(){
	return cabeza->siguiente == z;
}

/*
class Pila{ tipoElemento *pila;
  Int p;
Public:
		
  Pila (int max=100)
   {pila = new tipoElemento[max]; p=0;}
~Pila()
   {delete pila;}
Inline void meter (tipoElemento v)
   {pila[p++]=v;}
Inline tipoElemento sacar()
  {return pila [--p];}
Inline int vacia()
  {return !p;} 
};
*/
#endif
