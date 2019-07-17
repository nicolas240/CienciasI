#ifndef PERRO_H
#define PERRO_H

#include "ClasesExtra/fch.h"
#include <string>

class Perro{
	public:
		Perro(){}
		~Perro(){}
		std::string getNom();
		std::string getRaza();
		char getTam();
		char getConc();
		int getEdad();
	private:
		fch fNac;
		std::string nom;
		std::string raza;
		std::string direcResum;
		char tam;
		char tConc;
		int edad;
};
#endif
