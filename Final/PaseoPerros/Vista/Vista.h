#ifndef VISTA_H
#define VISTA_H

#include <string>

#include "../Logica/Sucursal.h"
#include "../Logica/Paseador.h"
#include "../Logica/Cliente.h"


class Vista{
	
	public:
		Vista(){}
		~Vista(){}
		//vista menus
		int inicio();
		int administrativo();
		int cliente();
		
		int ingresar();
		//vista ingresar
		Sucursal sucursal();		
		Paseador paseador();
		//vista eliminar
		
		//vista consultas
		
		//vista simulaciones
		
		void localidad();
};

//Menu para el inicio del programa
int Vista::inicio(){
	int opc;
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //      SISTEMA GESTION PASEO PERROS        //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	do{
		cout<<"||                                          ||"<<endl;
		cout<<"||        [1] - Menu Administrativo         ||"<<endl;
		cout<<"||        [2] - Menu Cliente                ||"<<endl;
		cout<<"||------------------------------------------||"<<endl;
		cout<<"||        [0] - Salir                       ||"<<endl;
		cout<<"||                                          ||"<<endl;
		cout<<"//////////////////////////////////////////////"<<endl;
		cout<<"Selecione Opcion -> ";
		cin>>opc;
		//cin.ignore();
	}while(opc<0 || opc>2);	//Mientras la opcion sea incorrecta se ejecuta el menu
	return opc;
}

//Menu para ingresar datos como administrativo
int Vista::administrativo(){
	int opc;
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //      SISTEMA GESTION PASEO PERROS Adm     //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	do{
		cout<<"||                                          ||"<<endl;
		cout<<"||        [1] - Ingresar			           ||"<<endl;
		cout<<"||        [2] - Eliminar			           ||"<<endl;		
		cout<<"||        [3] - Consultar		           ||"<<endl;
		cout<<"||        [4] - Simular Dia                 ||"<<endl;
		cout<<"||------------------------------------------||"<<endl;
		cout<<"||        [0] - Salir                       ||"<<endl;
		cout<<"||                                          ||"<<endl;
		cout<<"//////////////////////////////////////////////"<<endl;
		cout<<"Selecione Opcion -> ";
		cin>>opc;
		cin.ignore();
	}while(opc<0 || opc>4);	//Mientras la opcion sea incorrecta se ejecuta el menu
	return opc;
}

//Menu para ingresar datos como administrativo
int Vista::cliente(){
	int opc;
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //      SISTEMA GESTION PASEO PERROS cliente//"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	do{
		cout<<"||                                          ||"<<endl;
		cout<<"||        [1] - Ingresar Cliente            ||"<<endl;
		cout<<"||        [2] - Simular Paseo(ya es cliente)||"<<endl;
		cout<<"||------------------------------------------||"<<endl;
		cout<<"||        [0] - Salir                       ||"<<endl;
		cout<<"||                                          ||"<<endl;
		cout<<"//////////////////////////////////////////////"<<endl;
		cout<<"Selecione Opcion -> ";
		cin>>opc;
		cin.ignore();
	}while(opc<0 || opc>4);	//Mientras la opcion sea incorrecta se ejecuta el menu
	return opc;
}

//Menu ingresar
int Vista::ingresar(){
	int opc;
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //      		Que desea ingresar			//"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	do{
		cout<<"||                                          ||"<<endl;
		cout<<"||        [1] - Ingresar Sucursal           ||"<<endl;
		cout<<"||        [2] - Ingresar Paseador		   ||"<<endl;
		cout<<"||------------------------------------------||"<<endl;
		cout<<"||        [0] - Salir                       ||"<<endl;
		cout<<"||                                          ||"<<endl;
		cout<<"//////////////////////////////////////////////"<<endl;
		cout<<"Selecione Opcion -> ";
		cin>>opc;
		cin.ignore();
	}while(opc<0 || opc>4);	//Mientras la opcion sea incorrecta se ejecuta el menu
	return opc;
}

//Menu para ingresar sucursal
Sucursal Vista::sucursal(){
	//Declaracion de Variables
	Sucursal s;
	direc direccion;
	//std::string texto;
	char texto[25];
	char *apun[]={"                        "};
	int entero;
	int opc;
	char *localidad[] = {"Suba       ", "Usaquen    ", "Chapinero ", "Kennedy    ", "Teusaquillo", "Usme       "};
	
	//Muestra de menu y peticiones
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //             INGRESAR SUCURSAL            //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	cout<<"||                                            "<<endl;
	cin.ignore();	//Ignora lo que este almacenado en el buffer esto para evita problemas con un registro siguiente
	cout<<"||  Ingrese Nombre Sucursal: ";
	cin.getline(texto,25);
	apun[0] = texto;
	//getline(cin, texto);//Para string
	s.setNombre(apun[0]);
	
	//cin.ignore();
	cout<<"||  Ingrese Nombre Gerente: ";
	cin.getline(texto,25);
	//getline(cin, texto);//Para string
	s.setGerente(apun[0]);
	
	do{
		//cin.ignore();
		cout<<"||  Selecione Localidad: "<<endl;
		cout<<"||  [1]-Suba"<<endl<<"||  [2]-Usaquen"<<endl<<"||  [3]-Chapinero"<<endl;
		cout<<"||  [4]-Kennedy"<<endl<<"||  [5]-Teusaquillo"<<endl<<"||  [6]-Usme"<<endl<<"||  ->";
		cin >> opc;
		if(opc<1 || opc>6){
			cout<<"||  Localidad invalida."<<endl;
		}
	}while(opc<1 || opc>6);

	s.setLocalidad(localidad[opc-1]);
	
	cout<<"||  Direccion "<<endl<<"||  Calle: ";
	cin >> entero;
	direccion.calle = entero;
	cout<<"||  Carrera: ";
	cin >> entero;
	direccion.carrera = entero;
	cout<<"||  No.: ";
	cin >> entero;
	direccion.numero = entero;
	s.setDir(direccion);
	
	cout<<"||  Ingrese Area de Cobertura: ";
	cin >> entero;
	s.setArea(entero);
	//modelo.getSistema().ingSucursal(s);
	//cout<<"Para enviar: "<<s.getGerente()<<endl
	return s;
}

//Menu para ingresar paseador
Paseador Vista::paseador(){
		char sexo;
		int pasDisp;//Paseos disponibles
		int nId;
		int edad;
		int cel;
		int telFj;	
	//Declaracion de Variables
	Paseador p;
	fch nac;
	direc direccion;
	horario horD;
	//std::string texto;
	char texto[25];
	char *apun[]={"                        "};
	int entero;
	int opc;
	char *localidad[] = {"Suba       ", "Usaquen    ", "Chapinero ", "Kennedy    ", "Teusaquillo", "Usme       "};
	
	
	//Muestra de menu y peticiones
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //             INGRESAR PASEADOR            //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	cout<<"||                                            "<<endl;
	cin.ignore();	//Ignora lo que este almacenado en el buffer esto para evita problemas con un registro siguiente
	
	cout<<"||  nombre: ";
	cin.getline(texto,14);
	apun[0] = texto;
	p.setNom(apun[0]);
	
	cout<<"||  apellido: ";
	cin.getline(texto,14);
	apun[0] = texto;
	p.setApll(apun[0]);
	
	cout<<"||  Ingrese la fecha de nacimiento: ";

	cout<<"||  anio: ";
	cin>>entero;
	nac.anio=entero;

	cout<<"||  mes: ";
	cin>>entero;
	nac.mes=entero;
	
	cout<<"||  dia: ";
	cin>>entero;
	nac.dia=entero;
	
	p.setFnac(nac);
	
	cout<<"||  Ingrese el horario en el que esta disponible ";
	
	cout<<"||  Horario del dia lunes:"<<endl<<"||  hora inicio: ";
	cin>>horD.semana[0].horaIn;
	cout<<"||  hora fin: ";
	cin>>horD.semana[0].horaFn;

	cout<<"||  Horario del dia martes:"<<endl<<"||  hora inicio: ";
	cin>>horD.semana[1].horaIn;
	cout<<"||  hora fin: ";
	cin>>horD.semana[1].horaFn;

	cout<<"||  Horario del dia miercoles:"<<endl<<"||  hora inicio: ";
	cin>>horD.semana[2].horaIn;
	cout<<"||  hora fin: ";
	cin>>horD.semana[2].horaFn;

	cout<<"||  Horario del dia jueves:"<<endl<<"||  hora inicio: ";
	cin>>horD.semana[3].horaIn;
	cout<<"||  hora fin: ";
	cin>>horD.semana[3].horaFn;

	cout<<"||  Horario del dia viernes:"<<endl<<"||  hora inicio: ";
	cin>>horD.semana[4].horaIn;
	cout<<"||  hora fin: ";
	cin>>horD.semana[4].horaFn;

	cout<<"||  Horario del dia sabado:"<<endl<<"||  hora inicio: ";
	cin>>horD.semana[5].horaIn;
	cout<<"||  hora fin: ";
	cin>>horD.semana[5].horaFn;

	cout<<"||  Horario del dia domingo:"<<endl<<"||  hora inicio: ";
	cin>>horD.semana[6].horaIn;
	cout<<"||  hora fin: ";
	cin>>horD.semana[6].horaFn;
	
	p.setHdis(horD);
	
	cout<<"||  email: ";
	cin.getline(texto,30);
	apun[0] = texto;
	p.setEmail(texto);

	cout<<"||  ciudad de nacimiento: ";
	cin.getline(texto,15);
	apun[0] = texto;
	p.setCiudadN(texto);

	cout<<"||  pais de nacimiento: ";
	cin.getline(texto,15);
	apun[0] = texto;
	p.setPaisN(texto);
	
	cout<<"||  tipo de identificacion: ";
	cin.getline(texto,14);
	p.setPaisN(texto[0]);	

	cout<<"||  Ingrese Nombre Gerente: ";
	cin.getline(texto,25);
	//getline(cin, texto);//Para string
	s.setGerente(apun[0]);
	
	do{
		//cin.ignore();
		cout<<"||  Selecione Localidad: "<<endl;
		cout<<"||  [1]-Suba"<<endl<<"||  [2]-Usaquen"<<endl<<"||  [3]-Chapinero"<<endl;
		cout<<"||  [4]-Kennedy"<<endl<<"||  [5]-Teusaquillo"<<endl<<"||  [6]-Usme"<<endl<<"||  ->";
		cin >> opc;
		if(opc<1 || opc>6){
			cout<<"||  Localidad invalida."<<endl;
		}
	}while(opc<1 || opc>6);

	s.setLocalidad(localidad[opc-1]);
	
	cout<<"||  Direccion "<<endl<<"||  Calle: ";
	cin >> entero;
	direccion.calle = entero;
	cout<<"||  Carrera: ";
	cin >> entero;
	direccion.carrera = entero;
	cout<<"||  No.: ";
	cin >> entero;
	direccion.numero = entero;
	p.setDir(direccion);
	
	cout<<"||  Ingrese Area de Cobertura: ";
	cin >> entero;
	s.setArea(entero);
	//modelo.getSistema().ingSucursal(s);
	//cout<<"Para enviar: "<<s.getGerente()<<endl
	return s;
}
#endif
