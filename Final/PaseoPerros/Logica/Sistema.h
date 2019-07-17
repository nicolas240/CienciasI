#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>

using namespace std;

//Estructuras de datos
#include "lista.h"
//#include "Pila.h"
//#include "queue.h"

//Clases
#include "../Logica/Sucursal.h"
#include "../Logica/Cliente.h"
#include "../Logica/Paseador.h"

class Sistema{
	
	public:
		Sistema(){}
		~Sistema(){}
		
		//Ingresar
		void ingSucursal(Sucursal s);
		void ingPaseador(Paseador p);
		void ingCliente(Cliente c);
		//Persistencia
		void arSucursal(Sucursal s);
		void arPaseador(Paseador p);

		
		void verSucursal();
		void verPaseador();
		

		//void ingcliente(cliente c);
		//eliminar
		/*
		void borSucursal(int nit);
		void ingPaseador(int nid);
		*/
		//consultas
		
		//simulaciones
		

	private:
		lista <Sucursal> sucursales;
		lista <Cliente> clientes;
		lista <Paseador> paseadores;		
};

//Cargar sucursal a lista y llamar guardar al archivo
void Sistema::ingSucursal(Sucursal s){
	sucursales.insertar_nodo(sucursales.getTam()+1,s);
	//Agregar al archivo
	arSucursal(s);
}

//Cargar paseador a lista y llamar guardar al archivo
void Sistema::ingPaseador(Paseador p){
	verPaseador();
	if(p.getEdad()>18){
		paseadores.insertar_nodo(sucursales.getTam()+1,p);
		//Agregar al archivo
		arPaseador(p);
	}else{
		cout<<"Error, paseador menor de edad"<<endl;
	}
}

//Cargar cliente a lista y llmar a guardar al archivo
void Sistema::ingCliente(Cliente c){
	clientes.insertar_nodo(clientes.getTam()+1,c);
	arCliente(c):
}

//Guardar en archivo sucuarsal
void Sistema::arSucursal(Sucursal suc){

	//Abrir fichero para ingresar datos
	ofstream archivo("BD//Sucursales.txt",ios::app);
	
	archivo.write((char *)&suc,sizeof(suc));
	
	archivo.close();
	
	verSucursal();
	
	system("PAUSE");

}

//Guadar en archivo paseador
void Sistema::arPaseador(Paseador pac){

	//Abrir fichero para ingresar datos
	ofstream archivo("BD//Paseadores.txt",ios::app);
	
	archivo.write((char *)&pac,sizeof(pac));
	
	archivo.close();
	
	verPaseador();
	
	system("PAUSE");

}

//Guadar en archivo Cliente
void Sistema::arCliente(Cliente cli){

	//Abrir fichero para ingresar datos
	ofstream archivo("BD//Cliente.txt",ios::app);
	
	archivo.write((char *)&cli,sizeof(cli));
	
	archivo.close();
	
	verCliente();
	
	system("PAUSE");

}


//
void Sistema::verSucursal(){
	
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

void Sistema::verPaseador(){
	
	Paseador pac;
	
	ifstream archivo("BD//Paseadores.txt");
	
	system("cls");
	
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //                PASEADORES                //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	archivo.read((char *)&pac, sizeof(pac));
	while(archivo && !archivo.eof()){
		cout<<"||  Nom:"<<pac.getNom()<<" | ";
		cout<<"Ape:"<<pac.getApll()<<" | ";
		cout<<"Ciu:"<<pac.getCiudadN()<<" | ";
		cout<<"Pais:"<<pac.getPaisN()<<" | ";
		cout<<"Barr:"<<pac.barr()<<" | ";
		cout<<"Doc:"<<pac.getTid()<<" | ";
		cout<<"Sexo:"<<pac.getSexo()<<" | ";
		cout<<"Doc:"<<pac.getTid()<<" | ";
		cout<<"No.:"<<pac.getId()<<" | ";
		cout<<"Cel.:"<<pac.getCel()<<" | ";
		cout<<"Tel.:"<<pac.getTelf()<<" | ";
		cout<<"Edad:"<<pac.getEdad()<<" | ";
		cout<<"Paseos:"<<pac.getPaseos()<<endl;
		archivo.read((char *)&pac, sizeof(pac));
	}
	cout<<endl;
	system("PAUSE");
	
}

void Sistema::verPaseador(){
	
	Paseador pac;
	
	ifstream archivo("BD//Paseadores.txt");
	
	system("cls");
	
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //                PASEADORES                //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	archivo.read((char *)&pac, sizeof(pac));
	while(archivo && !archivo.eof()){
		cout<<"||  Nom:"<<pac.getNom()<<" | ";
		cout<<"Ape:"<<pac.getApll()<<" | ";
		cout<<"Ciu:"<<pac.getCiudadN()<<" | ";
		cout<<"Pais:"<<pac.getPaisN()<<" | ";
		cout<<"Barr:"<<pac.barr()<<" | ";
		cout<<"Doc:"<<pac.getTid()<<" | ";
		cout<<"Sexo:"<<pac.getSexo()<<" | ";
		cout<<"Doc:"<<pac.getTid()<<" | ";
		cout<<"No.:"<<pac.getId()<<" | ";
		cout<<"Cel.:"<<pac.getCel()<<" | ";
		cout<<"Tel.:"<<pac.getTelf()<<" | ";
		cout<<"Edad:"<<pac.getEdad()<<" | ";
		cout<<"Paseos:"<<pac.getPaseos()<<endl;
		archivo.read((char *)&pac, sizeof(pac));
	}
	cout<<endl;
	system("PAUSE");
	
}

#endif


