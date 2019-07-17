#ifndef CLIENTE_H
#define CLIENTE_H

#include "Perro.h"
#include <string>
class Cliente{
	public:
		Cliente(){}
		~Cliente(){}
		std::string getNom();
		std::string getApll();
		std::string getLoc();
		char getSexo();
		int getNId();
		int getPerr();
	
	private:
		Perro *perros;		
		
		std::string nomb;
		std::string apll;
		std::string localidad;
		
		int nId;
		int nPerr;
		char sexo;
};


#endif
