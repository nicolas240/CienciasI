#ifndef PASEADOR_H
#define PASEADOR_H

#include <string>
#include "Sucursal.h"
#include "ClasesExtra/fch.h"
#include "ClasesExtra/direc.h"
#include "ClasesExtra/horario.h"

class Paseador{
	public:
		Paseador(){
			pasDisp=2;
			edad=0;
		}
		~Paseador(){}
		
		fch getFnac(){return fNac;}
		horario horadiponible(){return horDisp;}
		direc getDir(){return dir;}
		
		char *getEmail(){return email;}
		char *getApll(){return apll;}
		char *getNom(){return nom;}   
		char *getCiudadN(){return ciuNac;}
		char *getPaisN(){return paisNac;}
		char *barr(){return barrio;}
		char getTid(){return tId;}
		char getSexo(){return sexo;}
		
				
		int getId(){return nId;}
		int getCel(){return cel;}
		int getTelf(){return telFj;}
		int getEdad(){return edad;}
		int getPaseos(){return pasDisp;}
		
		void setFnac(fch fn){
			fNac=fn;
			edad=fNac.calEdad();
		}
		void setHdis(horario h){horDisp=h;}
		void setDir(direc d){dir=d;}
		
		
		void setEmail(char *);
		void setApll(char *);
		void setNom(char *);
		void setCiudadN(char *);
		void setPaisN(char *);
		void setBarrio(char *);
		void setSexo(char s){sexo=s;}
		void setTid(char t){tId=t;}
						
		void setId(int i){nId=i;}
		void setCel(int c){cel=c;}
		void setTelf(int t){telFj=t;}
		void setPaseos(char a){
			if(a=='-')
				pasDisp--;
			else
				pasDisp++;
		}
		
	private:
		fch fNac;
		direc dir;
		horario horDisp;
		int pasDisp;//Paseos disponibles
		int nId;
		int edad;
		int cel;
		int telFj;
		char tId;
		char sexo;
		char nom[14];
		char apll[14];
		char email[30];
		char barrio[25];
		char ciuNac[15];
		char paisNac[15];
};

void Paseador::setApll(char *apellido){
	for(int i = 0; i < 14; ++i)
		apll[i] = apellido[i];
}

void Paseador::setBarrio(char *barr){
	for(int i = 0; i < 25; ++i)
		barrio[i] = barr[i];
}

void Paseador::setCiudadN(char *ciudad){
	for(int i = 0; i < 15; ++i)
		ciuNac[i] = ciudad[i];
}

void Paseador::setEmail(char *correo){
	for(int i = 0; i < 30; ++i)
		email[i] = correo[i];
}

void Paseador::setNom(char *nombre){
	for(int i = 0; i < 14; ++i)
		nom[i] = nombre[i];
}

void Paseador::setPaisN(char *pais){
	for(int i = 0; i < 15; ++i)
		paisNac[i] = pais[i];
}
#endif
