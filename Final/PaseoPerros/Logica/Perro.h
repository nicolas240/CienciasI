#ifndef PERRO_H
#define PERRO_H

#include "ClasesExtra/fch.h"
#include <string>

class Perro{
	public:
		Perro(){}
		~Perro(){}
		
		fch getFN(){return fNac;}
		
		char *getNom(){return nom;}
		char *getRaza(){return raza;}
		
		char getTam(){return tam;}
		char getConc(){return tConc;}
		int getEdad(){return edad;}
		
		void setTam(char t){tam=t;}
		void setTcon(char c){tConc=c;}
		void setNom(char *);
		void setRaza(char *);
		void setFN(fch fn){
			fNac=fn;
			edad=fNac.calEdad();
		}
	private:
		fch fNac;
		char nom[14];
		char raza[12];
		// direcResum;
		char tam;//p,m y g
		char tConc;//Adultos, cachorros y razas
		int edad;
};

void Perro::setNom(char *nombre){
	for(int i = 0; i < 14; ++i)
		nom[i] = nombre[i];
}
void Perro::setRaza(char *r){
	for(int i = 0; i < 12; ++i)
		raza[i] = r[i];
}
#endif
