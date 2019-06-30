#ifndef MODELOS_H
#define MODELO_H

#include "../Logica/Sucursal.h"
#include <iostream>
using namespace std;

class Modelo{
	public:
		Modelo(){}
		~Modelo(){}
		void iniciar();
	private:
		int x;
};

void Modelo::iniciar(){
		cout<<"actualizando base de datos"<<endl;
}

#endif
