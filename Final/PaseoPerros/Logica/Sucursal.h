#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "ClasesExtra/direc.h"

#include <string>

class Sucursal{
	public:
		Sucursal(){}
		~Sucursal(){
			delete localidad;
			delete nomGerente;
			delete nomSucursal;
		}
		char *getNombre();
		char *getGerente();
		char *getLocalidad();
		int getArea(){return area;}
		direc getDir(){return dir;}
		
		void setNombre(char *);
		void setGerente(char *);
		void setLocalidad(char *);
		void setArea(int);
		void setDir(direc);
		
	private:
		int area;//El area de covertura de la sucursal
		direc dir;
		char nomSucursal[25];
		char nomGerente[25];
		char localidad[11];	
};

char *Sucursal::getGerente(){
    /*for(int i = 0; i < count; ++i)
        buf[i] = nomGerente[i];*/
    return nomGerente;
}

char *Sucursal::getLocalidad(){
	return localidad;
}

char *Sucursal::getNombre(){
    return nomSucursal;
}

void Sucursal::setNombre(char *nombre){
	for(int i = 0; i < 25; ++i)
		nomSucursal[i] = nombre[i];
}

void Sucursal::setGerente(char *gerente){
	for(int i = 0; i < 25; ++i)
		nomGerente[i] = gerente[i];
}

void Sucursal::setLocalidad(char *local){
	for(int i = 0; i < 11; ++i)
		localidad[i] = local[i];
}

void Sucursal::setArea(int a){
	area = a;
}

void Sucursal::setDir(direc d){
	dir = d;
}

#endif
