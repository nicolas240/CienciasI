#ifndef MODELOS_H
#define MODELO_H

#include <fstream>
#include <iostream>
#include <string>

#include "../Logica/Sucursal.h"
#include "../Vista/Vista.h"

using namespace std;

class Modelo{
	public:
		Modelo(){}
		~Modelo(){}
		void ingresarSuc();
		void iniciar();
		void verSucursal();
	private:
		Vista menu;
		int x;
};

void Modelo::iniciar(){
	char opc;
	do{	
		system("cls");  
		opc = menu.principal(); 
		switch(opc){
			//Ingresar sucursal  
			case '1':  
				system("cls");
				ingresarSuc();  
			break;
			//Ingresar paseador
			case '2': 
				system("cls");
				verSucursal();
			break;
			//Ingresar cliente
			case '3':
				system("cls");
				cout<<"Caso3"<<endl;
				//mostrar(); 
			break;
			//Realizar consulta
			case '4':
				system("cls"); 
				cout<<"Caso4"<<endl; 
				//mostrar();
			break;
			//Simular dia
			case '5':
				system("cls");
				cout<<"Caso5"<<endl;
				//mostrar();  
			break;
			default:
				cout<<"Opcion incorrecta"<<endl;
			break;
		}
    }while(opc!='0');
	
	cout<<"GRACIAS POR UTILIZAR EL SISTEMA DE GESTION DE PASEO DE PERROS!!"<<endl;	
}

void Modelo::ingresarSuc(){
	

	Sucursal suc;
	
	//Llamar a la funcion que permite ingresa la sucursal y el objeto de tipo sucursal lleno
	suc = menu.sucursal();
	//char *impr;
	
	//suc.getGerente(impr,25);
	/*cout<<"Nom:"<<suc.getNombre()<<endl;
	cout<<"Ger:"<<suc.getGerente()<<endl;
	cout<<"Loc:"<<suc.getLocalidad()<<endl;
	cout<<"Area: "<<suc.getArea()<<endl;*/
	
	
	//Abrir fichero para ingresar datos
	ofstream archivo("Sucursales.txt",ios::app);
	
	archivo.write((char *)&suc,sizeof(suc));
	
	archivo.close();
	
	verSucursal();
	
	system("PAUSE");

}


void Modelo::verSucursal(){
	
	Sucursal suc2;
	
	ifstream archivo("Sucursales.txt");
	
	system("cls");
	
	archivo.read((char *)&suc2, sizeof(suc2));
	while(archivo && !archivo.eof()){
		cout<<"---------"<<endl;
		cout<<"Nom:"<<suc2.getNombre()<<endl;
		cout<<"Ger:"<<suc2.getGerente()<<endl;
		cout<<"Loc:"<<suc2.getLocalidad()<<endl;
		cout<<"Calle: "<<suc2.getDir().calle<<endl;
		cout<<"Carr:"<<suc2.getDir().carrera<<endl;
		cout<<"No.:"<<suc2.getDir().numero<<endl;
		cout<<"Area: "<<suc2.getArea()<<endl;
		archivo.read((char *)&suc2, sizeof(suc2));
	}
	//cout<<"Salto"<<endl;
	system("PAUSE");
}
#endif
