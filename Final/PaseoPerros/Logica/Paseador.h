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
		
		fch getFnac(){return fNac;}
		horario horadiponible(){return horDisp;}
		direc getDir(){return direc;}
		
		char *getEmail();
		char *getApll();
		char *getNom();
		char *getCiudadN();
		char *getPaisN();
		char *barr();
		char getSexo(){return sexo;}
				
		int getId(){return nId;}
		int getCel(){return cel;}
		int getTelf(){return telFj;}
		int getEdad(){return edad;}
		int getPaseos(){return pasDisp;}
		
		void setFnac(fch fn){fNac=fn;}
		void setHdis(horario h){horDisp=h;}
		void setDir(Dir d){direc=d;}
		
		
		void setEmail(char *);
		void setApll(char *);
		void setNom(char *);
		void setCiudadN(char *);
		void setPaisN(char *);
		void setBarrio(char *);
		void setSexo(char s){sexo=s;}
				
		void setId(int i){nid=i;}
		void setCel(int c){cel=c;}
		void setTelf(int t){telFj=t;}
		void setEdad(int e){edad=e;}
		void setPaseos(char a){
			if(a=='-')
				paseos--;
			else
				paseos++;8
		}
		
	private:
		fch fNac;
		direc dir;
		horario horDisp;
		char nom[14];
		char apll[14];
		char email[30];
		char ciuNac[15];
		char paisNac[15];
		char tId;
		char sexo;
		int pasDisp;//Paseos disponibles
		int nId;
		int edad;
		int cel;
		int telFj;
};

void Paseador::setApll(char *nombre){
	for(int i = 0; i < 14; ++i)
		nomSucursal[i] = nombre[i];
}

void Paseador::setBarrio(char *gerente){
	for(int i = 0; i < 25; ++i)
		nomGerente[i] = gerente[i];
}

void Paseador::setCiudadN(char *local){
	for(int i = 0; i < 15; ++i)
		localidad[i] = local[i];
}

void Paseador::setEmail(char *local){
	for(int i = 0; i < 30; ++i)
		localidad[i] = local[i];
}

void Paseador::setNom(char *local){
	for(int i = 0; i < 14; ++i)
		localidad[i] = local[i];
}

void Paseador::setPaisN(char *local){
	for(int i = 0; i < 15; ++i)
		localidad[i] = local[i];
}
#endif
