#ifndef CLIENTE_H
#define CLIENTE_H

#include "Perro.h"
#include <string>
class Cliente{
	public:
		Cliente(){}
		~Cliente(){}
		
		Perro *perros;		
		
		Perro *getPerros(){return perros;}
		
		char *getNom();
		char *getApll();
		char *getLoc();
		
		char getSexo(){return sexo;}
		
		int getNId(){return nId;}
		int getNPrr(){nPerr;}
		
		
		void setNom(char *);
		void setApll(char *);
		void setLocalidad(char *);
		
		void setSexo(char s){sexo=s;}
		
		void setNid(int id){nId=id;}
		void setnPrr(int nP);	
	private:
		char nomb[14];
		char apll[14];
		char localidad[11];
		
		int nId;
		int nPerr;
		char sexo;
};

void Cliente::setNom(char *nombre){
	for(int i = 0; i < 14; ++i)
		nomb[i] = nombre[i];
}

void Cliente::setApll(char *apellido){
	for(int i = 0; i < 25; ++i)
		apll[i] = apellido[i];
}

void Cliente::setLocalidad(char *local){
	for(int i = 0; i < 11; ++i)
		localidad[i] = local[i];
}
void Cliente::setnPrr(int nP){
	nPerr=nP;
	perros= new Perro[nPerr];
}

#endif
