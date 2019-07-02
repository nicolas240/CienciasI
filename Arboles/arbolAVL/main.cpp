#include <iostream>
#include "arbolAVL.h"

using namespace std;

int main(){

	ArbolAVL arbol(15);

	cout<<"Insertando nodos... "<<endl;
	arbol.insertarAVL(100);
	arbol.insertarAVL(50);
	arbol.insertarAVL(150);
	arbol.insertarAVL(30);
	arbol.insertarAVL(75);
	arbol.insertarAVL(125); 
	arbol.insertarAVL(170);
	arbol.insertarAVL(10);
	arbol.insertarAVL(60);
	arbol.insertarAVL(90); 
	arbol.insertarAVL(145);
	arbol.insertarAVL(160);  
	arbol.insertarAVL(180);
	
	cout<<"Insertados... "<<endl;

	arbol.insertarAVL(4);
	arbol.imprimir();
	  
	cout<<"Recorrido Inorden: "; 
	arbol.recorerInord();   
	cout<<endl;

	cout<<"Borrando 180... "<<endl;
	arbol.eliminar(180);
	
	cout<<"Recorrido Inorden: ";
	arbol.recorerInord();
	cout<<endl;

	cout<<"Borrando 125... "<<endl;
	arbol.eliminar(125);     
	
	cout<<"Recorrido Inorden: ";   
	arbol.recorerInord(); 
	cout<<endl; 
	
	cout<<"Recorrido Postorden: ";
	arbol.recorerPosord(); 
	cout<<endl;
	
	cout<<"Recorrido Preorden: ";
	arbol.recorerPre();
	cout<<endl;
	
	cout<<"Recorrido Niveles: ";
	arbol.recorerNiv();

	return 0;
	
}
