#ifndef SISTEMA_H
#define SISTEMA_H

//Estructuras de datos
#include "lista.h"
//#include "Pila.h"
//#include "queue.h"

//Clases
#include "../Logica/Sucursal.h"
#include "../Logica/Cliente.h"
#include "../Logica/Paseador.h"

class Sistema{
	
	public:
		Sistema(){}
		~Sistema(){}
		
		//ingresar
		void ingSucursal(Sucursal s);
		void ingPaseador(Paseador p);
		//eliminar
		
		//consultas
		
		//simulaciones
		

	private:
		lista <Sucursal> sucursales;
		lista <Cliente> clientes;
		lista <Paseador> paseadores;		
};

void Sistema::ingSucursal(Sucursal s){
	sucursales.insertar_nodo(sucursales.getTam()+1,s);	
}

void Sistema::ingPaseador(Paseador p){
	paseadores.insertar_nodo(sucursales.getTam()+1,s);	
}
#endif
