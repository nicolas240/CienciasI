#include <iostream>
#include "arbolAVL.h"

using namespace std;

int main(){

	ArbolAVL arbol(24);
	
	cout<<"-----------INSERTADO---------------"<<endl;
     
	arbol.insertarAVL(90);
	arbol.insertarAVL(38);
	arbol.insertarAVL(40);
	arbol.insertarAVL(80);
	arbol.insertarAVL(73);
	arbol.insertarAVL(25);
	arbol.insertarAVL(30);
	arbol.insertarAVL(84);
	arbol.insertarAVL(100);
	arbol.insertarAVL(20);
	arbol.insertarAVL(88);
	arbol.insertarAVL(79);  
	arbol.insertarAVL(85);
	arbol.insertarAVL(170);
	arbol.insertarAVL(89);
	arbol.insertarAVL(110); 
	arbol.insertarAVL(87);
	arbol.insertarAVL(120);
	arbol.insertarAVL(95);
	arbol.insertarAVL(130);
	arbol.insertarAVL(140);
	arbol.insertarAVL(128); 
	arbol.insertarAVL(97);
	arbol.insertarAVL(99);
	
	cout<<endl<<"-- Arbol --"<<endl;
	arbol.imprimir();
	
	cout<<"-----------ELIMINAR---------------"<<endl;	
 	arbol.eliminarAVL(120);
 	arbol.eliminarAVL(88);
 	arbol.eliminarAVL(38);
 	
	cout<<endl<<"-- Arbol --"<<endl;	
	arbol.imprimir();
	
	cout<<"Recorrido Inorden: ";
	arbol.recorerInord();
	cout<<endl;
	
	return 0;
	
}
