#ifndef LISTA_H
#define LISTA_H

template <class T>
struct nodo{
	T dato;
	nodo <T> *sig;
	};

class lista{
	public:
		lista(){cab=NULL, tam=0}
		~lista(){}
	private:
		nodo<T> *cab;
		int tam;
		vacia();
		void insertarNodo(int posicion, T dato);
		void borrarNodo(int posicion);
		T buscar(int posicion);
		void Cambiar(int posicion, T dato);
		int getTam();
};

#endif

//--------------------------

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
	
	public:
	lista(){
		cabeza = NULL;
		int tam = 0;
	}
	
};
	
	void insertar_nodo(int pos, T D);
	void insertar_final(T D);
	void insertar_inicio(T D);
	void borrar_nodo(int pos);
	T buscar(int pos);
	void modificar(int pos, T D);
	int getTam();
	
	template <class T>
	void lista<T>::insetar_nodo(int pos, T D){
		int cont;
		if (pos > tam){
			insertar_final(T D);
		}else if( pos == 1){
			insertar_inicio(T D);
		}else{
			nodo<T> *nuevo, *aux;
			nuevo = new nodo<T>;
			nuevo -> Dato = D;
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
	void lista::insertar_final(T D){
		nodo<T> *nuevo, *aux;
		nuevo = new nodo<T>;
		nuevo -> Dato = D
		nuevo -> sig = NULL;
		aux = cab; 
		while(cont < tam && aux!=NULL){
			aux = aux -> sig;
			cont++;				
		}
		aux -> sig = nuevo;
		tam++;
	}
	
	template <class T>
	void lista::public void insertar_inicio(T D){
		nodo<T> *nuevo;
		nuevo = new nodo<T>;
		nuevo -> Dato = D;
		nuevo -> sig = cab;
		cab = nuevo;
		cab++;
	}
#endif
