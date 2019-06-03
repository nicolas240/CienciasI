#ifndef LISTA_H
#define LISTA_H

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
void lista<T>::insertar_final(T D){
	int cont;
	nodo<T> *nuevo, *aux;
	nuevo = new nodo<T>;
	nuevo -> Dato = D;
	nuevo -> sig = NULL;
	aux = cabeza; 
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
	nuevo -> Dato = D;
	nuevo -> sig = cabeza;
	cabeza = nuevo;
	cabeza++;
}

template <class T>
void lista<T>::insertar_nodo(int pos, T D){
	int cont;
	if (pos > tam){
		insertar_final(D);
	}else if(pos == 1){
		insertar_inicio(D);
	}else{
		nodo<T> *nuevo, *aux;
		nuevo = new nodo<T>;
		nuevo -> Dato = D;
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

#endif
