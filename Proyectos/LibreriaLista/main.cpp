#include <iostream>
#include <clocale>
#include "lista.h"


using namespace std;
int main(){
	setlocale(LC_CTYPE,"Spanish");
	lista <int> x;
	lista <float> y;
	lista <char> z;
	
	cout << "Tamaño inicial: " << x.getTam() << endl;
	
	cout << "Insertando primer nodo..." << endl;
	x.insertar_nodo(1, 8);

	cout << "------------------------" << endl;
	cout << "Insertando segundo nodo..." << endl;
	x.insertar_nodo(1, 100);
	
	cout << "------------------------" << endl;
	cout << "Insertando tercer nodo..." << endl;
	x.insertar_nodo(3, 400);
	
	cout<<"¿Es vacia la lista?:"<<x.esVacia()<<endl;
	cout << "------------------------" << endl;
	cout << "Buscando valor pos = 1: ";
	cout << x.buscar(1) << endl;
	cout << "Buscando valor pos = 2: ";
	cout << x.buscar(2) << endl;
	cout << "Buscando valor pos = 3: ";
	cout << x.buscar(3) << endl;
	cout << "Tamaño al terminar: " << x.getTam() << endl;
	
	cout << "------------------------" << endl;
	cout << "Borrando dato 1..." << endl;
	x.borrar_nodo(1);
	cout << "Nuevo valor pos = 1: ";
	cout << x.buscar(1) << endl;
	cout << "Tamaño al terminar: " << x.getTam() << endl;
	
	cout << "------------------------" << endl;
	cout << "Cambiando dato 1..." << endl;	
	x.modificar(1,500);	
	cout << "Nuevo valor pos = 1: ";
	cout << x.buscar(1) << endl;
	cout << "Tamaño al terminar: " << x.getTam() << endl;
	
	cout << "------------------------" << endl;
	cout << "Borrando dato 1..." << endl;
	x.borrar_nodo(1);
	cout<<"¿Es vacia la lista?: "<< x.esVacia() <<endl;
	cout << "Buscando valor pos = 1: ";
	cout << x.buscar(1) << endl;
	cout << "Tamaño al terminar: " << x.getTam() << endl;

	cout << "------------------------" << endl;
	cout << "Borrando dato 1..." << endl;
	x.borrar_nodo(1);
	cout<<"¿Es vacia la lista?: "<< x.esVacia() <<endl;
	cout << "Buscando valor pos = 1: " << endl;
	cout << "Tamaño al terminar: " << x.getTam() << endl;
	return 0;
}
