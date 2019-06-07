#include <iostream>
#include "lista.h"

struct ingrediente{
	string nombre, medida;
	int cantidad;
	
};

template <class T>
struct postre
{
	lista <T> ingredientes;
	string procedimiento, tipo;
	int tiempo;
};


int main(int argc, char** argv) {
	lista <postre<ingrediente> > miPostre;
	lista <ingrediente> ingredientes;
	ingrediente nodo{"huevo", "unidades", 1};
	
	ingredientes.insertar_nodo(1, nodo);
	miPostre.insertar_nodo(1,ingredientes);
	
	miPostre.buscar(1);
	
	miPostre.insertar_nodo(1,ingredientes);
	
	cout<<"ejecuta"<<endl;	
	
	return 0;
}
