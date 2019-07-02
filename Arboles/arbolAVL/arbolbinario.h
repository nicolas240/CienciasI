#ifndef ARBOLARREGLO_H
#define ARBOLARREGLO_H

#include "arbolAVL.h"
#include "pila.h"
#include "cola.h"
#include <math.h>

using namespace std;

struct nodo{
	int clave;
	int der, izq, padre;
	int alturaIzq, alturaDer, FE;	//alturas y factor de Equilibrio
};

class ArbolArreglo {
	protected:
		int tam;
		int num;
		nodo **arbol;
		int posN;	//Posicion del nodo con que se esta trabajando

		void eliminarNoHijos(int, int);
		void eliminarUnHijos(int, int);
		void eliminarDosHijos(int, int);
		pila nodosImp;
		cola colaImp;
	public:
		ArbolArreglo(int);
		~ArbolArreglo();

		bool insertar(int);
		bool eliminar(int);
		void recorerInord();
		void recorerPosord();
		void recorerPre();
		void recorerNiv();
		int hijos(nodo *padre,char pos);
		bool buscar(int, int);
		bool buscarEliminar(int, int&, int&);
		bool vacio();
		bool lleno();

		// Funcion provisional para ver los datos
		void imprimir(){
			cout << "Pos\t| Clav \t| Izq \t| Der \t| Pad. \t| ADer \t| AIzq \t| FE \t|" << endl;
			for(int i=0; i<tam+1; i++){
				cout << "|"<< i << "\t| ";
				cout << arbol[i]->clave << " \t| ";
				cout << arbol[i]->izq << " \t| ";
				cout << arbol[i]->der << " \t| ";
				cout << arbol[i]->padre << " \t| ";
				cout << arbol[i]->alturaDer << " \t| ";
				cout << arbol[i]->alturaIzq << " \t| ";
				cout << arbol[i]->FE << " \t|"<< endl;
			}
			cout << endl;
		}
};

ArbolArreglo::ArbolArreglo(int max){
	tam = max;
	num = 0;
	arbol = new nodo*[tam+1];
	
	for(int i=0; i<tam+1; i++){
		arbol[i] = new nodo;
		arbol[i]->clave = 0;
		arbol[i]->izq = 0;
		arbol[i]->padre = 0;
		arbol[i]->FE = arbol[i]->alturaDer = arbol[i]->alturaIzq = 0;
		if(i != tam){
			arbol[i]->der = i+1;
		}else{
			arbol[i]->der = 0;
		}
	}
}

ArbolArreglo::~ArbolArreglo(){
	for(int i=0; i<tam+1; i++){
		delete arbol[i];
	}
	delete arbol;
}

bool ArbolArreglo::insertar(int v){
	int pos;
	pos = arbol[0]->der;
	posN = pos;

	if(!lleno()){
		arbol[pos]->clave = v; // valor a la nuevo pos
		arbol[0]->der = arbol[pos]->der; // se copia la posicion vacia al nodo 0
		arbol[pos]->der = 0; // se deja la derecha e izquierda igual a 0
		arbol[pos]->izq = 0;

		int aux_act = 0;
		int aux_sig = arbol[0]->izq;
		int lado = 1; // 1 izq, 0 der
		int padre;

		while(aux_sig != 0){
			aux_act = aux_sig;
			if(v < arbol[aux_sig]->clave){
				aux_sig = arbol[aux_sig]->izq;
				lado = 1;
			}else{
				aux_sig = arbol[aux_sig]->der;
				lado = 0;
			}
		}
		if(lado){
			arbol[aux_act]->izq = pos;
		}else{
			arbol[aux_act]->der = pos;
		}
		//Padre para los nodos exepto la raiz
		if(pos==arbol[0]->izq){
			arbol[pos]->padre=0;
		}else{
			arbol[pos]->padre=aux_act;
		}
		num++; //Lleva la cuenta de nodos insertados
		return true;
	}else{
		return false;
	}
}

void ArbolArreglo::recorerInord(){
	int imp = 0;
	nodo *aux;
	int padre = arbol[0]->izq;
	aux=arbol[padre];
	do{
		while(aux->izq!=0){	//Mientras el pare tenga hijos a la izquierda
			nodosImp.Push(padre);
			padre=aux->izq;
			aux=arbol[padre];
		}
		if(imp<num-1){	//Si solo falta un nodo por imprimir ejecuta el else
			cout<<aux->clave<<" ";
			imp++;
			if(aux->der!=0){	//Si el padre tiene hijos a la derecha empieza a revisar ese sub arbol 
				padre=aux->der;
				aux=arbol[padre];
			}else{	//Si no hay hijos a al derecha atiende la pila he imprime
				aux=arbol[nodosImp.Pop()];
				cout<<aux->clave<<" ";
				imp++;
				//cout<<"|Si|";
				if(imp<num){
					while(aux->der==0){  //Si el nodo que estaba en la pila no tiene hijos a la derecha, lo imprime y toma otro de la pila
						aux=arbol[nodosImp.Pop()];
						cout<<aux->clave<<" ";
						imp++;
					}
					//cout<<"|"<<imp<<"y"<<num<<"|";
					padre=aux->der;
					aux=arbol[padre];
				}
			}		
		}else{
			cout<<aux->clave<<" ";
			imp++;
		}
		//cout<<"|"<<num<<"|";
	}while(!nodosImp.PilaVacia() || imp<num);
}

void ArbolArreglo::recorerPosord(){
	int imp = 0;
	int control[tam];
	for(int i=0;i<tam;i++)
		control[i]=0;
	bool pila = false;
	nodo *aux;
	int padre = arbol[0]->izq;
	aux=arbol[padre];
	do{
		
		while(aux->izq!=0 && pila == false){	//Mientras el pare tenga hijos a la izquierda
			nodosImp.Push(padre);
			control[padre]=1;
			padre=aux->izq;
			aux=arbol[padre];
			pila = false;
		}
		if(imp<num-1){		//Si queda mas de un nodo por recorrer
			if(aux->der!=0){
				if(control[padre]>1){ //Se lleva control de si el padre fue tomado de la pila (>1)
					cout<<aux->clave<<" ";
					imp++;
					padre=nodosImp.Pop();
					aux=arbol[padre];
					if(imp==num-1){
						cout<<aux->clave<<" ";
						imp++;
					}
				}else{	//Si es la primer 
					nodosImp.Push(padre);
					control[padre]=2;
					padre=aux->der;
					aux=arbol[padre];
					pila = false;
				}

			}else{		//Si el nodo no tiene hijos a la derecha
				cout<<aux->clave<<" ";
				imp++;
				padre=nodosImp.Pop();
				aux=arbol[padre];
				pila = true;
			}
			
		}
		//cout<<"|wh:"<<arbol[padre]->clave<<"| ";
	}while(!nodosImp.PilaVacia() || imp<num);
}

void ArbolArreglo::recorerNiv(){
	nodo *aux=arbol[arbol[0]->izq];
	int nivel=1,hermano=0,i;
	colaImp.ImprimirCola();
	do{
		if(nivel==1){
			cout<<aux->clave<<" ";
			if(aux->izq!=0){
				colaImp.InsCola(aux->izq);
			}
			if(aux->der!=0){
				colaImp.InsCola(aux->der);
			}
		}else{
			for(i=1;i<=(pow(2,nivel)/2);i++){//se usara una potencia de dos los cuales son los posibles hermanos en los niveles 
				hermano=colaImp.AtenderCola();
				if(hermano!=-1){
					cout<<arbol[hermano]->clave<<" ";
					aux=arbol[hermano];
					if(aux->izq!=0){
						colaImp.InsCola(aux->izq);
					}
					if(aux->der!=0){
						colaImp.InsCola(aux->der);
					}
				}
			}
		}
		nivel++;
	}while(!colaImp.ColaVacia());
}

void ArbolArreglo::recorerPre(){
	nodo *aux;
	int padre = arbol[0]->izq;
	bool lDer=false;
	aux=arbol[padre];
	do{
		while(aux->izq!=0){	//Mientras el pare tenga hijos a la izquierda
			cout<<aux->clave<<" ";
			if(aux->der!=0)
				nodosImp.Push(padre);
			padre=aux->izq;
			aux=arbol[padre];
		}
		cout<<aux->clave<<" ";
		if(aux->der!=0 and aux->izq==0) aux=arbol[aux->der];
		else if(!nodosImp.PilaVacia()){
			aux=arbol[nodosImp.Pop()];
			padre=aux->der;
			aux=arbol[padre];
		}
		if(nodosImp.PilaVacia() && !lDer){
			lDer=true;
			padre=arbol[arbol[0]->izq]->der;
			aux=arbol[padre];
			nodosImp.Push(padre);
		}
	}while(!nodosImp.PilaVacia());	
}

bool ArbolArreglo::buscarEliminar(int dato, int& padre, int& hijo){
	if(hijo == 0) hijo = arbol[0]->izq;

	if(arbol[hijo]->clave == dato){
		return true;
	}else{
		if(dato < arbol[hijo]->clave && arbol[hijo]->izq != 0){
			padre = hijo;
			hijo = arbol[hijo]->izq;
			return buscarEliminar(dato, padre, hijo);
		}else if(dato > arbol[hijo]->clave && arbol[hijo]->der != 0){
			padre = hijo;
			hijo = arbol[hijo]->der;
			return buscarEliminar(dato, padre, hijo);
		}
	}
	return false;
}

bool ArbolArreglo::eliminar(int clave){
	int padre = 0;
	int hijo = arbol[0]->izq;

	if(buscarEliminar(clave, padre, hijo)){
		if(arbol[hijo]->der == 0 && arbol[hijo]->izq == 0){
			eliminarNoHijos(padre, hijo);
			num--;
			return true;}
		if(arbol[hijo]->der != 0 && arbol[hijo]->izq != 0){
			eliminarDosHijos(padre, hijo);
			num--;
			return true;}
		if(arbol[hijo]->der != 0 || arbol[hijo]->izq != 0){
			eliminarUnHijos(padre, hijo);
			num--;
			return true;}
	}	
	return false;
}

void ArbolArreglo::eliminarNoHijos(int padre, int hijo){
	if(arbol[padre]->izq == hijo){
		arbol[padre]->izq = 0;
	}else{
		arbol[padre]->der = 0;
	}

	arbol[hijo]->der = arbol[0]->der;
	arbol[0]->der = hijo;

	arbol[hijo]->clave = 0;
}

void ArbolArreglo::eliminarUnHijos(int padre, int hijo){
	if(arbol[padre]->izq == hijo){
		if(arbol[hijo]->izq != 0){
			arbol[padre]->izq = arbol[hijo]->izq;
		}else{
			arbol[padre]->izq = arbol[hijo]->der;
		}		
	}else{
		if(arbol[hijo]->izq != 0){
			arbol[padre]->der = arbol[hijo]->izq;
		}else{
			arbol[padre]->der = arbol[hijo]->der;
		}
	}
	
	arbol[hijo]->der = arbol[0]->der;
	arbol[0]->der = hijo;

	arbol[hijo]->clave = 0;
}

void ArbolArreglo::eliminarDosHijos(int padre, int hijo){
	int padre_r = hijo;
	int hijo_r = arbol[hijo]->der; // derecha mas a la izquierda

	while(arbol[hijo_r]->izq != 0){
		padre_r = hijo_r;
		hijo_r = arbol[hijo_r]->izq;
	}

	// Criterio de hijos
	if(arbol[hijo_r]->der == 0 && arbol[hijo_r]->izq == 0){
		if(arbol[padre_r]->izq == hijo_r){
			arbol[padre_r]->izq = 0;
		}else{
			arbol[padre_r]->der = 0;
		}
	}
	if(arbol[hijo_r]->der != 0){
		if(arbol[padre_r]->izq == hijo_r){
			arbol[padre_r]->izq = arbol[hijo_r]->der;
		}else{
			arbol[padre_r]->der = arbol[hijo_r]->der;
		}
	}

	// Padre conecta con reemplazo
	if(arbol[padre]->izq == hijo){
		arbol[padre]->izq = hijo_r;
	}else{
		arbol[padre]->der = hijo_r;
	}

	// Nodo reemplazo copiar hijos del borrado
	arbol[hijo_r]->izq = arbol[hijo]->izq;
	arbol[hijo_r]->der = arbol[hijo]->der;

	// nodo borrado a la lista de libres
	arbol[hijo]->der = arbol[0]->der;
	arbol[0]->der = hijo;

	arbol[hijo]->clave = 0;

}

bool ArbolArreglo::buscar(int dato, int pos=0){
	if(pos == 0) pos = arbol[0]->izq;

	if(arbol[pos]->clave == dato){
		return true;
	}else{
		if(dato < arbol[pos]->clave && arbol[pos]->izq != 0){
			return buscar(dato, arbol[pos]->izq);
		}else if(dato > arbol[pos]->clave && arbol[pos]->der != 0){
			return buscar(dato, arbol[pos]->der);
		}
	}

	return false;
}

bool ArbolArreglo::vacio(){
	return arbol[0]->izq == 0;
}

bool ArbolArreglo::lleno(){
	return arbol[0]->der == 0;
}

#endif
