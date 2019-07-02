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
		//Rotaciones
		void rotarSenIzq(int);
		void rotarSenDer(int);
		void rotarDobIzq(int);
		void rotarDobDer(int);
};

ArbolAVL::ArbolAVL(int max):ArbolArreglo(max){
	
}

//Calcula las arturas de los nodos
int ArbolAVL::altura(int pos){
	nodo *recorrer = arbol[pos];
	if (pos == 0)//Si el nodo está vació entonces que salga.
		return 0 ; //Devuelve el valor cero.
	else{
		cout<<"Dato:"<<recorrer->clave<<endl;
		if(recorrer->izq != 0){
			recorrer->alturaIzq=altura(recorrer->izq);
			cout<<"AltIzq:"<<recorrer->alturaIzq<<endl;
		}
		if(recorrer->der != 0){
			recorrer->alturaDer=altura(recorrer->der);
			cout<<"AltDer:"<<recorrer->alturaDer<<endl;
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
	
	for(int i=0; i<tam+1; i++){
		arbol[i]->FE = arbol[i]->alturaDer = arbol[i]->alturaIzq = 0;
	}
	//Calcular Factor de equilibrio
	altura(arbol[0]->izq);
	//verificar si es necesario balancear
	equilibrar(posN);
}

bool ArbolAVL::equilibrar(int pos){
	nodo *recorrer = arbol[pos];
	//Mientras no se llegue a la raiz y el FE sea deferente de -2 o 2
	while((pos != arbol[0]->izq) && (recorrer->FE != -2) && (recorrer->FE != 2)){
		pos = recorrer->padre;
		recorrer = arbol[pos];
	}
	
	if(recorrer->FE == -2 || recorrer->FE == 2){
		cout<<"Recorrer: "<<recorrer->clave<<endl;
		
		//Rotacion derecha
		if(recorrer->FE == -2){
			//sencilla derecha
			if(arbol[recorrer->izq]->FE == -1){
				rotarSenDer(pos);
				//altura(arbol[0]->izq); //Recalcular factor de equilibrio
			}
		}
	}

	return true;
}

//Rotacion sencilla a la izquierda
void ArbolAVL::rotarSenIzq(int pos){			//Falta caso si es raiz por que no tiene padre
	nodo *act = arbol[pos];	
	int posH = act->der;
	nodo *hijoDer = arbol[posH];
	//Rama izquierda del hijo pasa a ser la rama derecha del padre
	act->der = hijoDer->izq;
	//Padre pasa a ser el hijo izquierdo del hijo
	hijoDer->izq = pos;
	//Abuelo pasa a ser el padre del hijo
	hijoDer->padre = act->padre;
	//Posicion del hijo pasa a ser la del padre del actual
	act->padre = posH;
}

//Rotacion sencilla a la derecha
void ArbolAVL::rotarSenDer(int pos){
	nodo *act = arbol[pos];	
	int posH = act->izq;
	nodo *hijoIzq = arbol[posH];
	//Rama derecha del hijo pasa a ser la rama izquierda del padre
	act->izq = hijoIzq->der;
	//Padre pasa a ser el hijo derecho del hijo
	hijoIzq->der = pos;
	//Abuelo pasa a ser el padre del hijo
	hijoIzq->padre = act->padre;
	//Nodo izquierda del abuelo pasa a ser el hijo
	arbol[act->padre]->izq = posH;
	//Posicion del hijo pasa a ser la del padre del actual
	act->padre = posH;
}

void ArbolAVL::rotarDobIzq(int pos){
}
void ArbolAVL::rotarDobDer(int pos){
}

#endif
