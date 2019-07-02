#ifndef PASEADOR_H
#define PASEADOR_H

#include <string>
#include "Sucursal.h"
#include "ClasesExtra/fch.h"
#include "ClasesExtra/direc.h"
#include "ClasesExtra/horario.h"

class Paseador{
	public:
		Paseador(){}
		~Paseador(){}
		horario horadiponible();
		direc getDir();
		std::string getEmail();
		std::string getApll();
		std::string getNom();
		std::string getCiudadN();
		std::string getPaisN();
		std::string barr();
		void setPaseos();
		char getSexo();
		int getId();
		int getCel();
		int getTelf();
		int getEdad();
		int getPaseos();
		
	private:
		Sucursal sucuTrab;
		fch fNac;
		direc dir;
		horario horDisp;
		std::string nom;
		std::string apll;
		std::string email;
		std::string ciuNac;
		std::string paisNac;
		char tId;
		char sexo;
		int pasDisp;//Paseos disponibles
		int nId;
		int edad;
		int cel;
		int telFj;		
};

#endif
