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
		void iniciar();
		
		//Sucursal
		void ingresarSuc();
		void verSucursal();
		void modificarSucursal();
		int buscarSucursal(int);
		bool cambiadoSucursal(int);
		
		void eliminarSucursal();
		bool eliminadoSucursal(int);
		
		
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
				//verSucursal();
			break;
			//Ingresar paseador
			case '2': 
				system("cls");
				modificarSucursal();
				
			break;
			//Ingresar cliente
			case '3':
				system("cls");
				cout<<"Caso3"<<endl;
				verSucursal();
				system("PAUSE"); 
			break;
			//Realizar consulta
			case '4':
				system("cls"); 
				cout<<"Caso4"<<endl; 
				eliminarSucursal();
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

	//Abrir fichero para ingresar datos
	ofstream archivo("BD//Sucursales.txt",ios::app);
	
	archivo.write((char *)&suc,sizeof(suc));
	
	archivo.close();
	
	verSucursal();
	
	system("PAUSE");

}

void Modelo::modificarSucursal(){
	
	int nit;
	int ubicacion;
	
	system("cls");
	verSucursal();
	cin.ignore();
	cout<<"Ingrese el nit de la empresa: "<<endl;
	cin >> nit;
	
	if(ubicacion = buscarSucursal(nit)){
		if(cambiadoSucursal(ubicacion))
			cout<<"La sucursal ha sido modificado."<<endl;
	}else{
		cout<<"No se ha podido borrar."<<endl;
	}
	
	system("PAUSE");
}


int Modelo::buscarSucursal(int nitBuscado){
	
	Sucursal suc;
	int contador = 0;
	
	ifstream archivo("BD//Sucursales.txt");
	archivo.read((char*)&suc, sizeof(suc));
	
	while(archivo && !archivo.eof()){
		contador++;
		if(nitBuscado == suc.getNit()){
			cout<<"Sucursal "<<suc.getNombre()<<" encontrada."<<endl;
			cout<<"Presione una tecla para continuar."<<endl;
			return contador;
		}
		archivo.read((char*)&suc, sizeof(suc));
	}
	archivo.close();
	return 0;

	
}

bool Modelo::cambiadoSucursal(int ubicacion){
	
	Sucursal suc;
	int contador = 0;
	try{
		//Archivo de lectura y temporal para modificar	
		ifstream archivoLectura("BD//Sucursales.txt");
		ofstream archivoEscritura("BD//SucursalesTemp.txt");
	
		archivoLectura.read((char*)&suc, sizeof(suc));
		//Lee hasta que el archivo este vacio
		while(archivoLectura && !archivoLectura.eof()){
			contador++;
			if(contador == ubicacion){
				suc = menu.sucursal();
			}
			archivoEscritura.write((char *)&suc,sizeof(suc));
			cout<<"Contador "<<contador<<endl;
			archivoLectura.read((char*)&suc, sizeof(suc));
		}
		//Cierrra los archivos y renombra el modificado por el orgiginal
		archivoLectura.close();
		archivoEscritura.close();
		remove("BD//Sucursales.txt");
		rename("BD//SucursalesTemp.txt", "BD//Sucursales.txt");
	}catch(exception e){
		cout<<"Ha ocurrido un error"<<e.what();
	}
}


void Modelo::eliminarSucursal(){
	
	int nit;
	int ubicacion;
	
	system("cls");
	verSucursal();
	cin.ignore();
	cout<<"Ingrese el nit de la empresa: "<<endl;
	cin >> nit;
	
	if(ubicacion = buscarSucursal(nit)){
		if(eliminadoSucursal(ubicacion))
			cout<<"La sucursal ha sido eliminada."<<endl;
	}else{
		cout<<"No se ha podido eliminar."<<endl;
	}
	
	system("PAUSE");
	
}

bool Modelo::eliminadoSucursal(int ubicacion){
	
	Sucursal suc;
	int contador = 0;
	try{
		//Archivo de lectura y temporal para modificar	
		ifstream archivoLectura("BD//Sucursales.txt");
		ofstream archivoEscritura("BD//SucursalesTemp.txt");
	
		archivoLectura.read((char*)&suc, sizeof(suc));
		//Lee hasta que el archivo este vacio
		while(archivoLectura && !archivoLectura.eof()){
			contador++;
			if(contador == ubicacion){
				//No lo escribe
			}else{
				archivoEscritura.write((char *)&suc,sizeof(suc));
			}
			//cout<<"Contador "<<contador<<endl;
			archivoLectura.read((char*)&suc, sizeof(suc));
		}
		//Cierrra los archivos y renombra el modificado por el orgiginal
		archivoLectura.close();
		archivoEscritura.close();
		remove("BD//Sucursales.txt");
		rename("BD//SucursalesTemp.txt", "BD//Sucursales.txt");
	}catch(exception e){
		cout<<"Ha ocurrido un error"<<e.what();
	}
}


void Modelo::verSucursal(){
	
	Sucursal suc2;
	
	ifstream archivo("BD//Sucursales.txt");
	
	system("cls");
	
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //                SUCURSALES                //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	archivo.read((char *)&suc2, sizeof(suc2));
	while(archivo && !archivo.eof()){
		cout<<"||  NIT:"<<suc2.getNit()<<" | ";
		cout<<"Nom:"<<suc2.getNombre()<<" | ";
		cout<<"Ger:"<<suc2.getGerente()<<" | ";
		cout<<"Loc:"<<suc2.getLocalidad()<<" | ";
		cout<<"Calle: "<<suc2.getDir().calle<<" | ";
		cout<<"Carr:"<<suc2.getDir().carrera<<" | ";
		cout<<"No.:"<<suc2.getDir().numero<<" | ";
		cout<<"Area: "<<suc2.getArea()<<endl;
		archivo.read((char *)&suc2, sizeof(suc2));
	}
	cout<<endl;
	system("PAUSE");
}
#endif
