#include <iostream>
#include "arbolAVL.h"

using namespace std;

int main(){

	ArbolAVL arbol(24);
     
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
	
	arbol.imprimir();
/*
	ArbolAVL arbol(16);
 
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
	
	arbol.insertarAVL(8);
	arbol.imprimir();
	
	arbol.insertarAVL(4);
	arbol.imprimir();
	
	arbol.insertarAVL(2); 
	arbol.imprimir();
 
	cout<<"Recorrido Inorden: "; 
	arbol.recorerInord();   
	cout<<endl;

	//cout<<"Borrando 180... "<<endl;
	//arbol.eliminar(180);
	
	cout<<"Recorrido Inorden: ";
	arbol.recorerInord();
	cout<<endl;

	//cout<<"Borrando 125... "<<endl;
	//arbol.eliminar(125);       
	
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
*/
	return 0;
	
}
