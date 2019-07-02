#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "arbolbinario.h"

class ArbolAVL : public ArbolArreglo{
	private:
	
	public:
		ArbolAVL(int max);
		int altura(int);
		void insertarAVL(int);
		bool equilibrar(int);
};

ArbolAVL::ArbolAVL(int max):ArbolArreglo(max){
	
}

//Calcula las arturas de los nodos
int ArbolAVL::altura(int pos){
	nodo *recorrer = arbol[pos];
	if (pos == 0)//Si el nodo está vació entonces que salga.
		return 0 ; //Devuelve el valor cero.
	else{
		if(recorrer->izq != 0){
			recorrer->alturaIzq=altura(recorrer->izq);
			//cout<<"AltIzq:"<<recorrer->alturaIzq<<endl;
		}
		if(recorrer->der != 0){
			recorrer->alturaDer=altura(recorrer->der);
			//cout<<"AltDer:"<<recorrer->alturaDer<<endl;
		}
		recorrer->FE=recorrer->alturaDer-recorrer->alturaIzq;
		
		if (recorrer->alturaIzq > recorrer->alturaDer)
			return recorrer->alturaIzq + 1;
		else
			return recorrer->alturaDer + 1;
	}
}

void ArbolAVL::insertarAVL(int v){
	//insertar el nodo
	insertar(v);
	//Calcular Factor de equilibrio
	altura(arbol[0]->izq);
	//verificar si es necesario balancear
	equilibrar(posN);
}

bool ArbolAVL::equilibrar(int pos){
	cout<<"Pos Fuera: "<<pos<<endl;
	nodo *recorrer = arbol[pos];
	cout<<"Dato Fuera: "<<recorrer->clave<<endl;
	//Mientras no se llegue a la raiz y el FE sea deferente de -2 o 2
	while(pos=!arbol[0]->izq && (recorrer->FE !=-2) && (recorrer->FE != 2)){
		pos = arbol[pos]->padre;
		recorrer = arbol[pos];
		cout<<"Pos: "<<pos<<endl;
		cout<<"Dato: "<<recorrer->clave<<endl;
	}
	
	return true;
}



#endif
