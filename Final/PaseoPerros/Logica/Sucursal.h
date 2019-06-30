#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "ClasesExtra/direc.h"
#include <string>

class Sucursal{
	public:
		Sucursal(){}
		~Sucursal(){}
		string getNombre(){return nomSucursal;}
		string getGerente(){return nomGerente;}
		string getLocalidad(){return localidad;}
		int getArea(){return area;}
		direc getDir(){return dir;}
	private:
		string nomSucursal;
		string nomGerente;
		string localidad;
		
		int area;//El area de covertura de la sucursal
		direc dir;	
};


#endif
