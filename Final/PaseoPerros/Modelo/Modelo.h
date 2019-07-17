#ifndef MODELOS_H
#define MODELO_H

#include <fstream>
#include <iostream>
#include <string>

//Logica
#include "../Logica/Sistema.h"

#include "../Vista/Vista.h"

using namespace std;

class Modelo{
	public:
		Modelo(){}
		~Modelo(){}
		
		//Control para los menus
		void iniciar();
		void iniciarAdm();
		void iniciarCli();
		//Control para ingresar
		void ingresar();
		
		//Control para eliminar
		void eliminar();
		
		//Control para consultar
		void verSucursal();
		
		//Control para simular
		
	private:
		Sistema miSistema;
		
		Vista vista;
		
		int x;
};

void Modelo::iniciar(){
	int opc;
	do{	
		system("cls");
		opc = vista.inicio(); 
		switch(opc){
			//Menu Adiminstrativo  
			case 1:  
				system("cls");
				iniciarAdm();
			break;
			//Menu Cliente
			case 2: 
				system("cls");
				iniciarCli();
			break;
			default:
				cout<<"Opcion incorrecta"<<endl;
			break;
		}
    }while(opc!=0);
	
	cout<<"GRACIAS POR UTILIZAR EL SISTEMA DE GESTION DE PASEO DE PERROS!!"<<endl;	
}

void Modelo::iniciarAdm(){
	int opc;
	do{	
		system("cls");  
		opc = vista.administrativo(); 
		switch(opc){
			//Ingresar  
			case 1:  
				system("cls");
				ingresar();
			break;
			//Eliminar
			case 2: 
				system("cls");
				eliminar();
			break;
			//Consultar
			case 3:
				system("cls"); 
				cout<<"Caso4"<<endl; 
				//();
			break;
			//Simular dia
			case 4:
				system("cls");
				cout<<"Caso5"<<endl;
				//mostrar();  
			break;
			default:
				cout<<"Opcion incorrecta"<<endl;
			break;
		}
    }while(opc!=0);
}

void Modelo::iniciarCli(){
	int opc;
	do{	
		system("cls");  
		opc = vista.VCliente(); 
		switch(opc){
			//Ingresar nuevo cliente  
			case 1:  
				system("cls");
				cout<<"Caso 1"<<endl;
				miSistema.ingcliente(vista.cliente());
			break;
			//Ingresar simula un paseo de un cliente
			case 2: 
				system("cls");
				cout<<"Caso 2"<<endl;
			break;
			default:
				cout<<"Opcion incorrecta"<<endl;
			break;
		}
    }while(opc!=0);
}

void Modelo::ingresar(){	
	int opc;
	do{	
		system("cls");  
		opc = vista.ingresar(); 
		switch(opc){
			//Ingresar nueva sucursal
			case 1:  
				system("cls");
				miSistema.ingSucursal(vista.sucursal());//Vista para ingresar la sucursal
			break;
			//Ingresar nuevo paseador 
			case 2:  
				system("cls");
				miSistema.ingSucursal(vista.sucursal());//Vista para ingresar la Paseador
			break;
			default:
				cout<<"Opcion incorrecta"<<endl;
			break;
		}
    }while(opc!=0);
}

void Modelo::eliminar(){	
	int opc;
	do{	
		system("cls");  
		opc = vista.ingresar(); 
		switch(opc){
			//Ingresar nueva sucursal
			case 1:  
				system("cls");
				miSistema.ingSucursal(vista.sucursal());//Vista para ingresar la sucursal
			break;
			//Ingresar nuevo paseador 
			case 2:  
				system("cls");
				miSistema.ingSucursal(vista.sucursal());//Vista para ingresar la Paseador
			break;
			default:
				cout<<"Opcion incorrecta"<<endl;
			break;
		}
    }while(opc!=0);
}

void Modelo::verSucursal(){
	
	/*Sucursal suc2;
	
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
	system("PAUSE");*/
}
#endif
