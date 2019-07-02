#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "ClasesExtra/direc.h"
#include "lista.h"
#include "Cliente.h"
#include "Paseador.h"
#include <string>

class Sucursal{
	public:
		Sucursal(){}
		~Sucursal(){}
		std::string getNombre(){return nomSucursal;}
		std::string getGerente(){return nomGerente;}
		std::string getLocalidad(){return localidad;}
		int getArea(){return area;}
		direc getDir(){return dir;}
	private:
		lista <Cliente> clientes;
		lista <Paseador> paseadores;
		
		std::string nomSucursal;
		std::string nomGerente;
		std::string localidad;
		
		int area;//El area de covertura de la sucursal
		direc dir;	
};


#endif
