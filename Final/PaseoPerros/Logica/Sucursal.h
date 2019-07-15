#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "ClasesExtra/direc.h"
#include "lista.h"
#include "Cliente.h"
#include "Paseador.h"
#include <string>

class Sucursal{
	public:
		Sucursal(){
			localida= new char[11];
			nomGerente= new char[25];
			nomSucursal=new char[25];
		}
		~Sucursal(){
			delete localidad;
			delete nomGerente;
		}
	
		char getNombre(){return *nomSucursal;}
		char getGerente(){return *nomGerente;}
		char getLocalidad(){return *localidad;}
		void setNombre(char *);
		void setGerente(char *);
		void setLocalidad(char *);
		
		int getArea(){return area;}
		direc getDir(){return dir;}
		void setArea(int);
		void setDir(direc);
		
	private:
		lista <Cliente> clientes;
		lista <Paseador> paseadores;
		
		char *nomSucursal;
		char *nomGerente;
		char *localidad;
		
		int area;//El area de covertura de la sucursal
		direc dir;
};


void Sucursal::setNombre(char nombre[]){
	//nomSucursal[] = "";
	for(int i = 0; i < 25;i++){
		nomSucursal[i] = nombre[i];
	}
}
void Sucursal::setGerente(char gerente[]){
	//nomGerente[] = "";
	for(int i = 0; i < 25;i++){
		nomGerente[i] = gerente[i];
	}
}
void Sucursal::setLocalidad(char local[]){
	//localidad[] = "";
	for(int i = 0; i < 25;i++){
		localidad[i] = local[i];
	}
	
}
void Sucursal::setArea(int a){
	area = a;
}
void Sucursal::setDir(direc d){
	dir = d;
}
/*
class Sucursal{
	public:
		Sucursal(){}
		~Sucursal(){}
		std::string getNombre(){return nomSucursal;}
		std::string getGerente(){return nomGerente;}
		std::string getLocalidad(){return localidad;}
		void setNombre(std::string);
		void setGerente(std::string);
		void setLocalidad(std::string);
		
		int getArea(){return area;}
		direc getDir(){return dir;}
		void setArea(int);
		void setDir(direc);
	private:
		lista <Cliente> clientes;
		lista <Paseador> paseadores;
		
		std::string nomSucursal;
		std::string nomGerente;
		std::string localidad;
		
		int area;//El area de covertura de la sucursal
		direc dir;
};

void Sucursal::setNombre(std::string nombre){
	nomSucursal = nombre;
}
void Sucursal::setGerente(std::string gerente){
	nomGerente = gerente;
}
void Sucursal::setLocalidad(std::string local){
	localidad = local;
}
void Sucursal::setArea(int a){
	area = a;
}
void Sucursal::setDir(direc d){
	dir = d;
}
*/
#endif
