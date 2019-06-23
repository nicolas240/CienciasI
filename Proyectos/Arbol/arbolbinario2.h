#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "pila.h"

using namespace std;

template <class T>
struct nodo{
	T dato;
	nodo <T> *izq, *der;
};

template <class T>
class arbolbinario{
	private:
		nodo <T> control;
		int tam;
		int max;
		nodo <T> **arbol = NULL;
		pila <T> nodosImp;
	public:
		arbolbinario(int tam){
			max=tam;
			//Asigancion de tamaño y llenado basico del arreglo que representa al arbol
			arbol = new nodo <T> *[tam+1];
			for(int i=0;i<=tam;i++){
				arbol[i]=new nodo <T>;
				if(i==tam)
					arbol[i]->der=NULL;
				else
					arbol[i]->der=arbol[i+1];
			}
			arbol[0]->izq=NULL;
			
			arbol[1]->dato=1;
			arbol[2]->dato=2;
			arbol[3]->dato=3;
			arbol[4]->dato=4;
		}
		~arbolbinario(){
			for(int i=0;i<=max;i++){
				delete arbol[i];
			}
			delete []arbol;
		}
		void recorerInord();
		void recorerPreord();
		void recorerPosOrd();
		void recorerXNvls();
		void insertar(T dato);
		void imprimir();//BORRARR
		void llenar();
		int hijos(nodo <T> *padre, char pos);
		nodo<T> *buscar(T dato,char t);//char para buscar Hijo o Padre
		void eliminar(T dato);
};

//NodosImp(nodos a imprimir), el cual es la pila que se utiliza para imprimir 
template <class T>//i_R_d
void arbolbinario<T>::recorerInord(){
	nodo <T> *padre=NULL;
	nodo <T> *aux=NULL;
	if(max>1){
		padre=arbol[0]->izq;
		aux=NULL;
		nodosImp.Push(1);
		/*while(!nodosImp.PilaVacia()){
			nodosImp.Push(padre->dato);
			if(padre->izq!=NULL){
				for(int i=1;i<=hijos(padre,'I');i++){
					padre=padre->izq;
					cout<<padre->dato<<" ";
				}
				aux=padre->der;
				while(aux==NULL){
					padre=buscar(padre->dato,'P');
					aux=padre->der;
				}
				padre=aux;
			}
			else{
				cout<<padre->dato<<" ";
				if(padre->der!=NULL){
					padre=padre->der;
				}else{
					cout<<nodosImp.Pop()<<" "<<endl;
					padre=buscar(padre->dato,'P');
				}
			}
		}
*/		do{
			if(padre->izq!=NULL){
				for(int i=1;i<=hijos(padre,'I');i++){
					padre=padre->izq;
					nodosImp.Push(padre->dato);
				}
				cout<<nodosImp.Pop()<<" ";
				aux=padre->der;
				while(aux==NULL){
					padre=buscar(padre->dato,'P');
					aux=padre->der;
					cout<<nodosImp.Pop()<<" ";
				}
				padre=aux;
			}
			else{
				cout<<padre->dato<<" ";
				if(padre->der!=NULL){
					padre=padre->der;
				}else{
					cout<<nodosImp.Pop()<<" "<<endl;
					padre=buscar(padre->dato,'P');
				}
			}
		}while(!nodosImp.PilaVacia());
	}else if(max==0){
		cout<<"Arbol vacio"<<endl;
	}else{
		cout<<arbol[0]->izq->dato<<" "<<endl;
	}
	cout<<endl;
}

template <class T>//R_i_d
void arbolbinario<T>::recorerPreord(){
	nodo <T> *padre=NULL;
	nodo <T> *aux=NULL;
	if(tam>1){
		padre=arbol[0]->izq;
		aux=NULL;
		do{
			cout<<padre->dato<<" ";
			if(padre->izq!=NULL){
				for(int i=1;i<=hijos(padre,'I');i++){
					padre=padre->izq;
					cout<<padre->dato<<" ";
				}
				aux=padre->der;
				while(aux==NULL){
					padre=buscar(padre->dato,'P');
					aux=padre->der;
				}
				cout<<padre->dato<<" ";
				padre=aux;
			}
			else{
				cout<<padre->dato<<" ";
				if(padre->der!=NULL){
					padre=padre->der;
				}else{
					cout<<nodosImp.Pop()<<" "<<endl;
					padre=buscar(padre->dato,'P');
				}
			}
		}while(!nodosImp.PilaVacia());
	}else if(max==0){
		cout<<"Arbol vacio"<<endl;
	}else{
		cout<<arbol[0]->izq->dato<<" "<<endl;
	}
}

template <class T>//i_d_R
void arbolbinario<T>::recorerPosOrd(){
	nodo <T> *padre=NULL;
	nodo <T> *aux=NULL;
	if(tam>1){
		padre=arbol[0]->izq;
		aux=NULL;
		do{
			if(padre->izq!=NULL){
				for(int i=1;i<=hijos(padre,'I');i++){
					padre=padre->izq;
					nodosImp.Push(padre->dato);
				}
				cout<<nodosImp.Pop()<<" ";
				aux=padre->der;
				while(aux==NULL){
					padre=buscar(padre->dato,'P');
					aux=padre->der;
				}
				padre=aux;
			}
			else{
				cout<<padre->dato<<" ";
				if(padre->der!=NULL){
					nodosImp.(padre->der);
					padre=padre->der;
				}else{
					cout<<padre->dato<<" ";
					padre=buscar(padre->dato,'P');
					cout<<nodosImp.Pop(padre->dato)<<" "<<endl;
				}
			}
		}while(!nodosImp.PilaVacia());
	}else if(max==0){
		cout<<"Arbol vacio"<<endl;
	}else{
		cout<<arbol[0]->izq->dato<<" "<<endl;
	}
}

template <class T>//por niveles
void arbolbinario<T>::recorerXNvls(){
	/*nodo <T> *padre=NULL;
	nodo <T> *aux=NULL;
	if(tam>1){
		int nivel=0;
		
		padre=arbol[0]->izq;
		aux=NULL;
		do{
			if(padre->izq!=NULL){
				for(int i=hijos(padre,'I');i>0;i++){
					padre=padre->izq;
					nodosImp.Push(padre->dato);
				}
				cout<<nodosImp.Pop()<<" ";
				aux=padre->der;
				while(aux==NULL){
					padre=buscar(padre->dato,'P');
					aux=padre->der;
				}
				padre=aux;
			}
			else{
				cout<<padre->dato<<" ";
				if(padre->der!=NULL){
					nodosImp.(padre->der);
					padre=padre->der;
				}else{
					cout<<padre->dato<<" ";
					padre=buscar(padre->dato,'P');
					cout<<nodosImp.Pop(padre->dato)<<" "<<endl;
				}
			}
		}while(!nodosImp.PilaVacia());
	}else if(max==0){
		cout<<"Arbol vacio"<<endl;
	}else{
		cout<<arbol[0]->izq->dato<<" "<<endl;
	}
}*/

template <class T>
nodo <T> *arbolbinario<T>::buscar(T dato,char t){
	nodo <T> *padre=arbol[0]->izq;
	nodo <T> *aux=arbol[0];
	while(dato!=padre->dato){
		aux=padre;//toma el padre de la variable padre
		if(padre->dato<dato){
			padre=padre->der;
		}else
			padre=padre->izq;
	}
	if(t=='H')
		return padre;
	else
		return aux;
}

template <class T>
int arbolbinario<T>::hijos(nodo <T> *padre,char pos){
	nodo <T> *aux;
	int hijos=0;
	if(pos=='I'){
		aux=padre->izq;
		while(aux!=NULL){
			hijos++;
			aux=aux->izq;
		}
	}else{
		aux=padre->der;
		while(aux!=NULL){
			hijos++;
			aux=aux->der;
		}		
	}
	return hijos;
}

template <class T>
void arbolbinario<T>::insertar(T dato){
	nodo<T> *aux;
	if(arbol[0]->izq==NULL){				//Si el arbol vacio
		arbol[0]->izq=arbol[0]->der;
		arbol[0]->der=arbol[0]->izq->der;
		arbol[0]->izq->dato=dato;
		arbol[0]->izq->izq=NULL;
		arbol[0]->izq->der=NULL;
		tam++;
	}else{
		bool insert = false;
		aux=arbol[0]->izq;		//Se asigna a aux la raiz del arbol.
		while(insert == false){
			//Por izquierda (menor)
			if(aux->dato<dato && aux->izq != NULL){
				aux=aux->izq;
			}
			if(aux->dato<dato && aux->izq == NULL){
				arbol[0]->der->dato=dato;
				//FALTA condicion para cuando solo queda una posicion por insertar arbol[0]->der = NULL;
				aux->izq = arbol[0]->der;   //Se asigna al padre por izq la direccion del nuevo hijo.
				arbol[0]->der=arbol[0]->der->der;
				aux->izq = NULL;
				aux->der = NULL;
				insert = true;
			}
			//Por derecha (mayor)
			if(aux->dato>dato && aux->der != NULL){
				aux=aux->der;
			}
			if(aux->dato>dato && aux->der == NULL){
				arbol[0]->der->dato=dato;
				//FALTA condicion para cuando solo queda una posicion por insertar arbol[0]->der = NULL;
				aux->der = arbol[0]->der;   //Se asigna al padre por der la direccion del nuevo hijo.
				arbol[0]->der=arbol[0]->der->der;
				aux->izq = NULL;
				aux->der = NULL;
				insert = true;
			}
		}
		tam++;
	}
	cout<<"Fin insertar.."<<endl;
}

template <class T>
void arbolbinario<T>::imprimir(){
	for(int i=1;i<=4;i++){
		cout<<arbol[i]->dato<<" ";
	}
}

#endif
