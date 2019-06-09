#include <iostream>
#include "lista.h"

using namespace std;

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
	lista <postre <ingrediente> > Postres;
	lista <ingrediente> ingredientes;
	
	ingrediente nodoIngrediente{"huevo", "unidades", 1};
	nodoIngrediente=ingrediente{"huevo","unidades",4};
	ingredientes.insertar_nodo(1, ingrediente{"huevo","unidades",4});
	ingredientes.insertar_nodo(2, ingrediente{"azucar","taza",1/2});
	/*nodoIngrediente=ingrediente{"arina","taza",1/2};
	ingredientes.insertar_nodo(3, nodoIngrediente);
	nodoIngrediente=ingrediente{"polvo de hornear","cucharada",1/2};
	ingredientes.insertar_nodo(4, nodoIngrediente);*/
	
	postre <ingrediente> nodoPostre{ingredientes,"Precaliente el horno a 375 grados F. Engrase con mantequilla una bandeja para hornear. Cubra la bandeja para hornear con papel pergamino y unte mantequilla en el papel de pergamino. Ponga a un lado y poner una toalla de cocina limpia en una superficie de trabajo.","dulce",12};
	postre <ingrediente> nodoPostre2{ingredientes,"Picie de trabajo.","dulce",12};
	Postres.insertar_nodo(1,nodoPostre);
	Postres.insertar_nodo(1,nodoPostre2);
	
	cout<<"Brazo de reina:"<<endl;
	cout<<Postres.buscar(1).ingredientes.buscar(1).nombre<<endl;
	
	cout<<"ejecuta"<<endl;	
	
	return 0;
}
