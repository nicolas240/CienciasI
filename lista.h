#ifndef LISTA_H
#define LISTA_H

template <class T>
struct nodo{
	T dato;
	nodo <T> *sig;
	}
}

public class lista{
	public:
		lista(){cab=NULL, tam=0}
		~lista(){}
	private:
		nodo <T> *cab;
		int tam;
		vacia();
		void insertarNodo(int posicion, T dato);
		void borrarNodo(int posicion);
		T buscar(int posicion);
		void Cambiar(int posicion, T dato);
		int getTam();
};

#endif




