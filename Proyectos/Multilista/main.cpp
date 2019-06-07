#include <iostream>
#include <clocale>
#include "multilista.h"
#include <string>

using namespace std;
 
int main(int argc, char* argv[]) { 
 	setlocale(LC_CTYPE,"Spanish");
 	
	listaPrincipal listaDatos;
	
	cout << "Tamaño inicial: " << listaDatos.getTam() << endl;
	
	cout << "Insertando primer nodos..." << endl;
	listaDatos.insertar_nodo(1,"Raquel","Electronica","Danza",23);
	listaDatos.insertar_nodo(2,"Jaime","Industrial","Natacion",16);	
	listaDatos.insertar_nodo(3,"Arturo","Electronica","Basquet",18);
	listaDatos.insertar_nodo(4,"Andres","Catastral","Danza",19);
	listaDatos.insertar_nodo(5,"Adriana","Sistemas","Basquet",24);
	listaDatos.insertar_nodo(6,"Juanny","Industrial","Natacion",20);
	listaDatos.insertar_nodo(7,"Marypaz","Sistemas","Danza",19);
	listaDatos.insertar_nodo(8,"Italia","Catastral","Beisball",17);
	listaDatos.insertar_nodo(9,"Maria","Sistemas","Basquet",21);
	listaDatos.insertar_nodo(10,"Pilar","Sistemas","Beisball",22);
	listaDatos.imprimir();
	
	cout << "Tamaño despues de insertar datos: " << listaDatos.getTam() << endl;
	
	listaDatos.imprimirCabecera();
	listaDatos.imprimir();
	//Comparar dos string
	//string p = "Maria";
	//string p2 ="Maria";
	//cout << (2 == 1) <<endl;
	//cout << !p2.compare(p)<< endl;
	//Fin de compara
    return 0;
}
