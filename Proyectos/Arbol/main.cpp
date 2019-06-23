#include <iostream>
#include "arbolbinario.h"

using namespace std;

int main(){

	ArbolArreglo arbol(13);

	arbol.insertar(100);
	arbol.insertar(50);
	arbol.insertar(150);
	arbol.insertar(30);
	arbol.insertar(75);
	arbol.insertar(125);
	arbol.insertar(170);
	arbol.insertar(10);
	arbol.insertar(60);
	arbol.insertar(90); 
	arbol.insertar(145);
	arbol.insertar(160);
	arbol.insertar(180);
	   
	arbol.imprimir();
	cout<<"Recorrido inorden: ";
	arbol.recorerInord();
	cout<<endl;

	cout<<"Recorrido por niveles: ";
	arbol.recorerNiv();
	cout<<endl;
	
	cout<<"Borrando 180... "<<endl;
	arbol.eliminar(180);
	
	cout<<"Recorrido por niveles: ";
	arbol.recorerNiv();
	cout<<endl;
	
	cout<<"Borrando 125... "<<endl;
	arbol.eliminar(125);

	cout<<"Recorrido por niveles: ";
	arbol.recorerNiv();
	cout<<endl; 
	cout<<endl;
	return 0;
}
