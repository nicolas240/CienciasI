#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>

using namespace std;

//Estructuras de datos
#include "lista.h"
//#include "Pila.h"
#include "queue.h"

//Clases
#include "../Logica/Sucursal.h"
#include "../Logica/Cliente.h"
#include "../Logica/Paseador.h"
#include "../Vista/Vista.h"

class Sistema{
	
	public:
		Sistema(){}
		~Sistema(){}
		
		Vista menu;
		
		//Ingresar
		void ingSucursal(Sucursal s);
		void ingPaseador(Paseador p);
		void ingCliente(Cliente c);
		
		//Modificar
		void modSucursal(int nit);
		bool cambiadoSucursal(int ubicacion);
		
		int busSucursal(int nit);
		
		//Persistencia
		void arSucursal(Sucursal s);
		void arPaseador(Paseador p);
		void arCliente(Cliente c);
		void verCliente();

		
		void verSucursal();
		void verPaseador();
		
		void buscarSucursal(direc d);
		//void ingcliente(cliente c);
		//eliminar
		/*
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
	verSucursal();
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
	verPaseador();
}

//Cargar cliente a lista y llmar a guardar al archivo
void Sistema::ingCliente(Cliente c){
	clientes.insertar_nodo(clientes.getTam()+1,c);
	arCliente(c);
	verCliente();
}

//Cargar cliente a lista y llmar a guardar al archivo
void Sistema::modSucursal(int nit){
	
	verSucursal();
	busSucursal(nit);
	
	int ubicacion;

 	if(ubicacion = busSucursal(nit)){	
		if(cambiadoSucursal(ubicacion))	
			cout<<"La sucursal ha sido modificada."<<endl;	
	}else{	
		cout<<"No se ha podido modificar la sucursal."<<endl;	
	}	

 	system("PAUSE");
	
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


//Ver paseadores
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
}

//Ver paseadores
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
}

//Ver clientes
void Sistema::verCliente(){
	
	Cliente cli;
	
	ifstream archivo("BD//Cliente.txt");
	
	system("cls");
	
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //                CLIENTE                   //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	archivo.read((char *)&cli, sizeof(cli));
	while(archivo && !archivo.eof()){
		//cout<<"||  Nom:"<<cli.getNom()<<" | ";
		//cout<<"Ape:"<<cli.getApll()<<" | ";
		cout<<"No ID:"<<cli.getNId()<<" | ";
		cout<<"Sexo:"<<cli.getSexo()<<" | ";
		//cout<<"Locali.:"<<cli.getLoc()<<" | ";
		cout<<"No Perros"<<cli.getNPrr()<<" | ";
		for(int i=0; i<cli.getNPrr();i++){
			cout<<"Pe"<<i<<" Nom:"<<cli.perros[i].getNom();
			cout<<" Raza:"<<cli.perros[i].getRaza();
			cout<<" Nom:"<<cli.perros[i].getEdad()<<" | ";	
		}
	}
}

//Buscar direccion
void Sistema::buscarSucursal(direc d){
	Queue <Sucursal> cola;
	for(int i=1; i<=sucursales.getTam();i++){
		if(sucursales.buscar(i).getDir().estaArea(d))
			cola.enqueue(sucursales.buscar(i),'D');
	}
	
}

//Buscar un nit especificado
int Sistema::busSucursal(int nitBuscado){
	
	Sucursal suc;
	int contador = 0;
	
	ifstream archivo("BD//Sucursales.txt");
	archivo.read((char*)&suc, sizeof(suc));
	while(archivo && !archivo.eof()){
		contador++;
		if(nitBuscado == suc.getNit()){
			cout<<"Sucursal "<<suc.getNombre()<<"encontrada."<<endl;
			cout<<"Presione una tecla para continuar."<<endl;
			return contador;
		}
		archivo.read((char*)&suc, sizeof(suc));
	}
	archivo.close();
	return 0;
	
}

//Modificar sucursal
bool Sistema::cambiadoSucursal(int ubicacion){	
	
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
	
#endif


