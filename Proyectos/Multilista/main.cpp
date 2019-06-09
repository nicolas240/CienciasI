#include <iostream>
#include <clocale>
#include "multilista.h"
#include <string>

using namespace std;
 
int main(int argc, char* argv[]) { 
 	setlocale(LC_CTYPE,"Spanish");
 	
	listaPrincipal listaDatos;
	
	cout << "Tamaño inicial: " << listaDatos.getTam() << endl;
 
	cout << "Insertando datos nodos..." << endl;
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
	
	cout << "Tamaño despues de insertar datos: " << listaDatos.getTam() << endl;
	cout <<endl; 
	  
	//listaDatos.imprimirCabecera();
	
	/*
	Ordenes posibles 
	Nombre = 0
	Electronica = 1
	Inustrial = 2
	Sistemas = 3
	Catastral = 4
	Danza = 5
	Natacion = 6 
	Basquet = 7 
	Beisbol = 8
	Edad = 9
	Lista original = 10
	*/
	listaDatos.imprimirCadenaOrden(10);
	listaDatos.imprimirCadenaOrden(0);
	listaDatos.imprimirCadenaOrden(1);
	listaDatos.imprimirCadenaOrden(2);
	listaDatos.imprimirCadenaOrden(3);
	listaDatos.imprimirCadenaOrden(4);
	listaDatos.imprimirCadenaOrden(5);
	listaDatos.imprimirCadenaOrden(6);
	listaDatos.imprimirCadenaOrden(7);
	listaDatos.imprimirCadenaOrden(8);
	listaDatos.imprimirCadenaOrden(9);
    
	listaDatos.imprimirCadenaOrden(10);
	//Borrar nodo
	listaDatos.borrar_nodo(10);
	cout<<"-----------Listas despues del nodo borrado -------------"<<endl;
	listaDatos.imprimirCadenaOrden(10);
	listaDatos.imprimirCadenaOrden(0);
	listaDatos.imprimirCadenaOrden(1);
	listaDatos.imprimirCadenaOrden(2);
	listaDatos.imprimirCadenaOrden(3);
	listaDatos.imprimirCadenaOrden(4);
	listaDatos.imprimirCadenaOrden(5);
	listaDatos.imprimirCadenaOrden(6);
	listaDatos.imprimirCadenaOrden(7);
	listaDatos.imprimirCadenaOrden(8);
	listaDatos.imprimirCadenaOrden(9);
	cout<<"Buscar posicion: "<<endl;
	listaDatos.imprimirPosicion(listaDatos.buscar("Andres"));
	return 0; 
}
