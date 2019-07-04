#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "arbolbinario.h"

class ArbolAVL : public ArbolArreglo{
	private:
	
	public:
		ArbolAVL(int max);
		int altura(int);
		void insertarAVL(int);
		void eliminarAVL(int);
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
	if (pos == 0)//Si el nodo est? vaci? entonces que salga.
		return 0 ; //Devuelve el valor cero.
	else{
		//cout<<"Dato:"<<recorrer->clave<<endl;
		recorrer->alturaIzq=altura(recorrer->izq);
		recorrer->alturaDer=altura(recorrer->der);

		recorrer->FE=recorrer->alturaDer-recorrer->alturaIzq;
		
		if (recorrer->alturaIzq > recorrer->alturaDer)
			return recorrer->alturaIzq + 1;
		else
			return recorrer->alturaDer + 1;
	}
}

void ArbolAVL::insertarAVL(int v){
	cout<<"Insertando: "<<v<<endl;
	//insertar el nodo
	insertar(v);
	//Calcular Factor de equilibrio
	altura(arbol[0]->izq);
	//verificar si es necesario balancear
	equilibrar(posN);
	
	//imprimir();
}

void ArbolAVL::eliminarAVL(int v){
	cout<<"Eliminado: "<<v<<endl;
	//Eliminar nodo
	eliminar(v);
	//Calcular Factor de equilibrio
	altura(arbol[0]->izq);
	//verificar si es necesario balancear
	equilibrar(posBorrado);	
}

bool ArbolAVL::equilibrar(int pos){
	nodo *recorrer = arbol[pos];
	//Mientras no se llegue a la raiz y el FE sea deferente de -2 o 2
	while((pos != arbol[0]->izq) && (recorrer->FE != -2) && (recorrer->FE != 2)){
		pos = recorrer->padre;
		recorrer = arbol[pos];
	}
	
	if(recorrer->FE == -2 || recorrer->FE == 2){
		//imprimir();
		cout<<endl<<"Desequilibrio en: "<<recorrer->clave<<endl;
		cout<<"Factor de Equilibrio: "<<recorrer->FE<<endl;
		//Rotacion derecha
		if(recorrer->FE == -2){
			//sencilla derecha
			if(arbol[recorrer->izq]->FE == -1){
				cout<<"Rotacion Sencilla a la Derecha"<<endl;
				rotarSenDer(pos);
				altura(arbol[0]->izq); //Recalcular factor de equilibrio
			}
			//doble (Izq->Der)
			if(arbol[recorrer->izq]->FE == 1){
				cout<<"Rotacion Doble a la Derecha"<<endl;
				rotarSenIzq(recorrer->izq);	//Rotacion sencilla a la izquierda sobre el hijo
				//cout<<"Aqui"<<endl;
				//imprimir();
				rotarSenDer(pos);	//Rtacion sencilla a la izquierda sobre el nodo actual
				//imprimir();
				altura(arbol[0]->izq); //Recalcular factor de equilibrio
			}
		}
		
		//Rotacion izqierda
		if(recorrer->FE == 2){
			//sencilla izquierda
			if(arbol[recorrer->der]->FE == 1){
				cout<<"Rotacion Sencilla a la Izquierda"<<endl;
				rotarSenIzq(pos);
				altura(arbol[0]->izq); //Recalcular factor de equilibrio
			}
			//doble (Der->Izq)
			if(arbol[recorrer->der]->FE == -1){
				cout<<"Rotacion Doble a la Izquierda"<<endl;
				rotarSenDer(recorrer->der);	//Rotacion sencilla a la derecha sobre el hijo
				rotarSenIzq(pos);	//Rtacion sencilla a la izquierda sobre el nodo actual
				altura(arbol[0]->izq); //Recalcular factor de equilibrio
			}
		}
	}

	return true;
}

//Rotacion sencilla a la izquierda
void ArbolAVL::rotarSenIzq(int pos){
	nodo *act = arbol[pos];	
	int posH = act->der;
	nodo *hijoDer = arbol[posH];

	//Rama izquierda del hijo pasa a ser la rama derecha del padre
	act->der = hijoDer->izq;
	//Si el nodo del hijo es diferente de cero se le asigna su padre (es decir la posicion actual)
	if(act->der!=0)
		arbol[act->der]->padre=pos;
	//Padre pasa a ser el hijo izquierdo del hijo
	hijoDer->izq = pos;
	//Si es la raiz, el hijo pasa a ser la raiz, asi que el padre del hijo es 0
	if(pos==arbol[0]->izq){	
		hijoDer->padre=0;
		arbol[0]->izq=posH;
	// Si no el abuelo pasa a ser el padre del hijo
	}else{
		hijoDer->padre = act->padre;
		//Segun el lado del desbalance el nodo izquierdo o derecho del abuelo para a ser el nieto (posH)
		if(arbol[act->padre]->izq==pos)
			arbol[act->padre]->izq = posH;
		else
			arbol[act->padre]->der = posH;	
	}
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
	//Si el nodo del hijo es diferente de cero se le asigna su padre (es decir la posicion actual)
	if(act->izq!=0)
		arbol[act->izq]->padre=pos;
	//Padre pasa a ser el hijo derecho del hijo
	hijoIzq->der = pos;
	//Si es la raiz, el hijo pasa a ser la raiz, asi que el padre del hijo es 0
	if(pos==arbol[0]->izq){	
		hijoIzq->padre=0;
		arbol[0]->izq=posH;
	// Si no el abuelo pasa a ser el padre del hijo
	}else{
		hijoIzq->padre = act->padre;
		//Segun el lado del desbalance el nodo izquierdo o derecho del abuelo para a ser el nieto (posH)
		if(arbol[act->padre]->izq==pos)
			arbol[act->padre]->izq = posH;
		else
			arbol[act->padre]->der = posH;
	}
	act->padre = posH;
}

/*
void ArbolAVL::rotarDobIzq(int pos, bool sencilla){
}
void ArbolAVL::rotarDobDer(int pos bool sencilla){
}
*/
#endif
