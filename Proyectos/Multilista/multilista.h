#ifndef MULTILISTA_H
#define MULTILISTA_H
#include <string>

struct nodo{
	string nombre;
	string carrera;
	string hobby;
	int edad;
	nodo string *sigNombre;
	nodo string *sigCarrera;
	nodo string *sigHobby;
	nodo int *edad;
};

class listaPrincipal{
	private:
		nodo int *cab;
		int tam;

	public:
		lista(){
			cabeza = NULL;
			tam = 0;
		}
		~lista(){
			int cont=1;
			nodo<T> *recorre, *aux=cabeza;
			while(cont < tam && aux!=NULL){
				recorre=aux;
				aux = aux -> sig;
				delete recorre;
				cont++;
			}
		}
		void insertar_nodo(int pos, string nombre, string carrera, string hobby, int edad);
		void insertar_final(T dato);
		void insertar_inicio(T dato);
		void borrar_nodo(int pos);
		void modificar(int pos, T dato);
		int getTam();
		bool esVacia();
		T buscar(int pos);
};

void lista<T>::insertar_nodo(int pos, string nombre, string carrera, string hobby, int edad);
	int cont;
	nodo
	if (pos > tam && pos != 1){
		insertar_final(D);
	}else if(pos == 1 && tam < 1){
		insertar_inicio(D);
	}else{
		nodo *nuevo, *aux;
		nuevo = new nodo;
		nuevo -> nombre = nombre;
		nuevo -> carrera = carrera;
		nuevo -> hobby = hobby;
		nuevo -> edad = edad;
		aux = cab;
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
void lista<T>::borrar_nodo(int pos){
	int cont;
	nodo<T> *aux = NULL;
	nodo<T> *aux2 = NULL;
	aux = cabeza;
	cont = 1;
	while(cont < pos -1 && aux!=NULL){
		aux = aux -> sig;
		cont++;
	}
	if(tam > 1){
		if(pos == 1){
			cabeza = aux -> sig;
			delete aux;
		}else{
			aux2 = aux -> sig;
			aux -> sig = aux2 -> sig;
			delete aux2;
		}
		tam--;
	}else{
		//Confirma que como solo hay un nodo, se ingrese posicion 1 para borrarlo, de lo contrario no se borra nada
		if(pos == 1){
			cabeza = NULL;
			tam--;
		}

	}
}

template <class T>
void lista<T>::modificar(int pos, T D){
	int cont=1;
	nodo<T> *aux= cabeza;
	while(cont < pos -1 && aux!=NULL){
		aux = aux -> sig;
		cont++;
	}
	if(pos==1)
		cabeza->dato=D;
	else
		aux->sig->dato=D;
}

template <class T>
bool lista<T>::esVacia(){
	if(cabeza == NULL)
		return true;
	else
		return false;
}

template <class T>
int lista<T>::getTam(){
	return tam;
}

#endif
