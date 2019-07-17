#ifndef VISTA_H
#define VISTA_H

#include <string>
#include <fstream>

#include "../Logica/Sucursal.h"
#include "../Logica/ClasesExtra/fch.h"
#include "../Logica/ClasesExtra/direc.h"


class Vista{
	
	public:
		Vista(){}
		~Vista(){}
		char principal();
		Sucursal sucursal();
		void localidad();
		
	private:
};



char Vista::principal(){
	char opc;
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //      SISTEMA GESTION PASEO PERROS        //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	do{
		cout<<"||                                          ||"<<endl;
		cout<<"||        [1] - Ingresar Sucursal           ||"<<endl;
		cout<<"||        [2] - Ingresar Paseador           ||"<<endl;
		cout<<"||        [3] - Ingresar Cliente            ||"<<endl;
		cout<<"||        [4] - Realizar Consulta           ||"<<endl;
		cout<<"||        [5] - Simular Dia                 ||"<<endl;
		cout<<"||------------------------------------------||"<<endl;
		cout<<"||        [0] - Salir                       ||"<<endl;
		cout<<"||                                          ||"<<endl;
		cout<<"//////////////////////////////////////////////"<<endl;
		cout<<"Selecione Opcion -> ";
		cin.get(opc);
	}while(opc<'0' || opc>'5');	//Mientras la opcion sea incorrecta se ejecuta el menu
	return opc;
}

//Menu para ingresar sucursal
Sucursal Vista::sucursal(){
	
	
	//Declaracion de Variables
	Sucursal s;
	fch fecha;
	direc direccion;
	//std::string texto;
	char texto[25];
	char *apun[]={"                        "};
	int entero=0;
	int opc;
	char *localidad[] = {"Suba       ", "Usaquen    ", "Chapinero ", "Kennedy    ", "Teusaquillo", "Usme       "};
	
	
	//Muestra de menu y peticiones
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //             INGRESAR SUCURSAL            //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	cout<<"||  	                                         "<<endl;
	cin.ignore();	//Ignora lo que este almacenado en el buffer esto para evita problemas con un registro siguiente
	cout<<"||  Ingrese Nit: ";
	cin >> entero;
	s.setNit(entero);
	
	
	cin.ignore();
	cin.clear();
	cout<<"||  Ingrese Nombre Sucursal: ";
	cin.getline(texto,25);
	apun[0] = texto;
	s.setNombre(apun[0]);
	//getline(cin, texto);//Para string
	
	cin.clear();
	cout<<"||  Ingrese Nombre Gerente: ";
	cin.getline(texto,25);
	s.setGerente(apun[0]);
	//getline(cin, texto);//Para string
	
	do{
		cout<<"||  Selecione Localidad: "<<endl;
		cout<<"||  [1]-Suba"<<endl<<"||  [2]-Usaquen"<<endl<<"||  [3]-Chapinero"<<endl;
		cout<<"||  [4]-Kennedy"<<endl<<"||  [5]-Teusaquillo"<<endl<<"||  [6]-Usme"<<endl<<"||  ->";
		cin >> opc;
		if(opc<1 || opc>6){
			cout<<"||  Localidad invalida."<<endl;
		}
	}while(opc<1 || opc>6);

	s.setLocalidad(localidad[opc-1]);
	
	cin.ignore();
	cin.clear();
	cout<<"||  Direccion "<<endl<<"||  Calle: ";
	cin >> entero;
	direccion.calle = entero;
	
	cin.ignore();
	cin.clear();
	cout<<"||  Carrera: ";
	cin >> entero;
	direccion.carrera = entero;
	
	cin.ignore();
	cin.clear();
	cout<<"||  No.: ";
	cin >> entero;
	direccion.numero = entero;
	
	s.setDir(direccion);
	
	cin.ignore();
	cin.clear();
	cout<<"||  Ingrese Area de Cobertura: ";
	cin >> entero;
	s.setArea(entero);
	
	return s;
}


#endif
