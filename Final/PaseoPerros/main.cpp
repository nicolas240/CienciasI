#include <iostream>
#include "Modelo/Modelo.h"

#include <string>
using namespace std;

int main(int argc, char** argv) {
	Modelo paseos;//Se crea el modelo
	char opcion='u';
	string s;
	
	cout<<"Bienvenid@!"<<endl<<endl;
	while(opcion!='S' and opcion!='N'){
		cout<<"¿desea iniciar la aplicacion?"<<endl;
		cout<<"S para iniciar, N para salir"<<endl;
		cout<<"->";
		cin>>opcion;
		switch(opcion){
			case 'S': paseos.iniciar(); break;//Se inicia el modelo
			case 'N': cout<<"Saliendo.."<<endl<<endl; break;
			default: cout<<"Opcion incorrecta"<<endl<<endl; break;
		}
	}
	cout<<"Gracias"<<endl;
	return 0;
}
