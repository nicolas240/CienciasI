#ifndef LISTA_H
#define LISTA_H

using namespace std;

template <class T>
struct nodo {
	T dato;
	nodo <T> *sig;
};

template <class T>
class lista{
	private:
		nodo <T> *cabeza;
		int tam;
	
	public:
		lista(){
			cabeza = NULL; 
			tam = 0;
		}
		void insertar_nodo(int pos, T D);
		void insertar_final(T D);
		void insertar_inicio(T D);
		void borrar_nodo(int pos);
		T buscar(int pos);
		void modificar(int pos, T D);
		int getTam();
};
		
template <class T>
void lista<T>::insertar_nodo(int pos, T D){
	int cont;
	if (pos > tam && pos != 1){
		insertar_final(D);
	}else if(pos == 1 && tam < 1){
		insertar_inicio(D);
	}else{
		nodo<T> *nuevo, *aux;
		nuevo = new nodo<T>;
		nuevo -> dato = D;
		aux = cabeza;
		cont = 1;
		while(cont < pos-1 && aux!=NULL){
			aux = aux -> sig;
			cont++;				
		}
		nuevo -> sig = aux -> sig;
		aux -> sig = nuevo;
		tam++;
	}
}

template <class T>
void lista<T>::insertar_final(T D){
	int cont;
	nodo<T> *nuevo, *aux;
	nuevo = new nodo<T>;
	nuevo -> dato = D;
	nuevo -> sig = NULL;
	aux = cabeza;
	cont = 1;
	while(cont < tam && aux!=NULL){
		aux = aux -> sig;
		cont++;				
	}
	aux -> sig = nuevo;
	tam++;
}

template <class T>
void lista<T>::insertar_inicio(T D){
	nodo<T> *nuevo;
	nuevo = new nodo<T>;
	nuevo -> dato = D;
	nuevo -> sig = cabeza;
	cabeza = nuevo;
	tam++;
}

template <class T>
T lista<T>::buscar(int pos){
	int cont;
	nodo<T> *aux = NULL;
	aux = cabeza;
	cont = 1;
	while(cont <= pos-1 && aux!=NULL){
		aux = aux -> sig;
		cont++;			
	}
	return aux -> dato;
}

template <class T>
int lista<T>::getTam(){
	return tam;
}

#endif
