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
		int vCliente();
		
		int ingresar();
		
		int modificar();
		int solNit();
		
		int eliminar();
		int consultar();
		
		//vista ingresar
		Sucursal sucursal();		
		Paseador paseador();
		Cliente cliente();
		direc ingDir();
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
	cout<<" //      SISTEMA GESTION PASEO PERROS Adm    //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	do{
		cout<<"||                                          ||"<<endl;
		cout<<"||        [1] - Ingresar	                   ||"<<endl;
		cout<<"||        [2] - Modificar                   ||"<<endl;
		cout<<"||        [3] - Eliminar                    ||"<<endl;		
		cout<<"||        [4] - Consultar                   ||"<<endl;
		cout<<"||        [5] - Simular Dia                 ||"<<endl;
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
int Vista::modificar(){
	int opc;
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //            MODIFICAR SUCURSAL             //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	do{
		cout<<"||                                          ||"<<endl;
		cout<<"||        [1] - Modificar Sucursal          ||"<<endl;
		cout<<"||        [2] - Modificar Paseador          ||"<<endl;
		cout<<"||        [3] - Modificar Cliente           ||"<<endl;		
		cout<<"||------------------------------------------||"<<endl;
		cout<<"||        [0] - Salir                       ||"<<endl;
		cout<<"||                                          ||"<<endl;
		cout<<"//////////////////////////////////////////////"<<endl;
		cout<<"Selecione Opcion -> ";
		cin>>opc;
		cin.ignore();
	}while(opc<0 || opc>3);	//Mientras la opcion sea incorrecta se ejecuta el menu
	return opc;
}

int Vista::solNit(){
	int nit;
	cout<<endl<<"||  Ingrese NIT de la empresa a modificar: ";
	cin >> nit;
	return nit;
}

//Menu para ingresar datos como administrativo
int Vista::vCliente(){
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
	cout<<" //              Que desea ingresar          //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	
	do{
		cout<<"||                                          ||"<<endl;
		cout<<"||        [1] - Ingresar Sucursal           ||"<<endl;
		cout<<"||        [2] - Ingresar Paseador           ||"<<endl;
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
int Vista::consultar(){
	int opc;
	system("cls");
		cout<<"  ///////////////////////////////////////////////////////"<<endl;
		cout<<" //                   Que desea consultar             //"<<endl;
		cout<<"///////////////////////////////////////////////////////"<<endl;

 	do{
		cout<<"||                                                     ||"<<endl;
		cout<<"||        [1] - Encontrar Sucursal                     ||"<<endl;
		cout<<"||        [2] - Paseadores disponibles                 ||"<<endl;
		cout<<"||        [3] - Paseadores disponibles para un cliente ||"<<endl;
		cout<<"||        [4] - Razas de perros en una localidad       ||"<<endl;
		cout<<"||        [5] - Perros paseados por un paseador        ||"<<endl;
		cout<<"||        [6] - Resumen de un perro                    ||"<<endl;
		cout<<"||        [7] - Perros de un tamanio en una localidad  ||"<<endl;
		cout<<"||        [8] - Perros de una edad                     ||"<<endl;
		cout<<"||-----------------------------------------------------||"<<endl;
		cout<<"||        [0] - Salir                                  ||"<<endl;
		cout<<"||                                                     ||"<<endl;
		cout<<"/////////////////////////////////////////////////////////"<<endl;
		cout<<"Selecione Opcion -> ";
		cin>>opc;
		cin.ignore();
	}while(opc<0 || opc>4);	//Mientras la opcion sea incorrecta se ejecuta el menu
	return opc;
}

 //Menu para ingresar direccion
direc Vista::ingDir(){
	direc direccion;
	int entero;
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //  Ingrese una direccion para determinar   //"<<endl;
	cout<<" //   una sucursal que puede hacerse cargo	//"<<endl;
	cout<<" //   de los perros del area.                //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;

 	cout<<"||  Direccion "<<endl<<"||  Calle: ";
	cin >> entero;
	direccion.calle = entero;
	cout<<"||  Carrera: ";
	cin >> entero;
	direccion.carrera = entero;
	cout<<"||  No.: ";
	cin >> entero;
	direccion.numero = entero;
	return direccion;
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
	
	
	//cin.ignore();	//Ignora lo que este almacenado en el buffer esto para evita problemas con un registro siguiente
	cout<<"||  Ingrese Nit: ";
	cin >> entero;
	s.setNit(entero);
	
	cin.ignore();
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
	
	//Declaracion de Variables
	Paseador p;
	fch nac;
	direc direccion;
	horario horD;
	//std::string texto;
	char texto[25];
	char *apun[]={"                        "};
	int entero;
	char var;
	
	//Muestra de menu y peticiones
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //             INGRESAR PASEADOR            //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	cout<<"||                                            "<<endl;
	//cin.ignore();	//Ignora lo que este almacenado en el buffer esto para evita problemas con un registro siguiente
	
	cout<<"||  nombre: ";
	cin.getline(texto,14);
	apun[0] = texto;
	p.setNom(apun[0]);
	
	cout<<"||  apellido: ";
	cin.getline(texto,14);
	apun[0] = texto;
	p.setApll(apun[0]);
	
	cout<<"||  Ingrese la fecha de nacimiento: "<<endl;

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
	
	cout<<"||  Ingrese el horario en el que esta disponible "<<endl;
	
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
	cout<<endl;
	cin.ignore();
	cout<<"||  email: ";
	cin.getline(texto,30);
	apun[0] = texto;
	p.setEmail(texto);

	cout<<"||  barrio de residencia: ";
	cin.getline(texto,15);
	apun[0] = texto;
	p.setBarrio(texto);

	cout<<"||  ciudad de nacimiento: ";
	cin.getline(texto,15);
	apun[0] = texto;
	p.setCiudadN(texto);

	cout<<"||  pais de nacimiento: ";
	cin.getline(texto,15);
	apun[0] = texto;
	p.setPaisN(texto);
	
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
	
	do{
		cout<<"||  Selecione su tipo de identificacion: "<<endl;
		cout<<"||  [c]-Cedula de ciudadania colombiana"<<endl<<"||  [e]-cedula extranjera"<<endl<<"||  ->";
		cin >> var;
		if(var != 'c' && var != 'e'){
			cout<<"||  opcion invalida."<<endl;
		}
	}while(!(var == 'c' || var == 'e'));
	p.setTid(var);
	
	cout<<"|| numero de identificacion: ";
	cin>>entero;
	p.setId(entero);

	cout<<"||  sexo: ";
	do{
		cout<<"||  [m]-masculino"<<endl<<"||  [f]-femenino"<<endl<<"||  ->";
		cin >> var;
		if(var!='m' && var!='f'){
			cout<<"||  opcion invalida."<<endl;
		}
	}while(!(var=='m' || var=='f'));
	p.setSexo(var);
	
	cout<<"|| numero de celular: ";
	cin>>entero;
	p.setCel(entero);
	
	cout<<"|| numero de telefeno: ";
	cin>>entero;
	p.setTelf(entero);
	
	return p;
}

//Menu para ingresar cliente
Cliente Vista::cliente(){
	
	//Declaracion de Variables
	Cliente c;
	fch nac;
	int opc;
	char *localidad[] = {"Suba       ", "Usaquen    ", "Chapinero ", "Kennedy    ", "Teusaquillo", "Usme       "};
	//std::string texto;
	char texto[25];
	char *apun[]={"                        "};
	int entero;
	char var;
	
	//Muestra de menu y peticiones
	system("cls");
	cout<<"  //////////////////////////////////////////////"<<endl;
	cout<<" //             INGRESAR CLIENTE             //"<<endl;
	cout<<"//////////////////////////////////////////////"<<endl;
	cout<<"||                                            "<<endl;
	//cin.ignore();	//Ignora lo que este almacenado en el buffer esto para evita problemas con un registro siguiente
	
	cout<<"||  nombre: ";
	cin.getline(texto,14);
	apun[0] = texto;
	c.setNom(apun[0]);
	
	cout<<"||  apellido: ";
	cin.getline(texto,14);
	apun[0] = texto;
	c.setApll(apun[0]);
	
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

	c.setLocalidad(localidad[opc-1]);

	cout<<"|| numero de identificacion: ";
	cin>>entero;
	c.setNid(entero);

	cout<<"|| numero de perros: ";
	cin>>entero;
	cout<<"entero: "<<entero<<endl;
	c.setnPrr(entero);
	cin.ignore();
	
	cout<<"||  sexo: ";
	do{
		cout<<"||  [m]-masculino"<<endl<<"||  [f]-femenino"<<endl<<"||  ->";
		cin >> var;
		if(var!='m' && var!='f'){
			cout<<"||  opcion invalida."<<endl;
		}
	}while(!(var=='m' || var=='f'));
	c.setSexo(var);	
	cout<<endl;
	
	
	cout<<"hasta (c.getNPrr()-1) :"<<(c.getNPrr()-1)<<endl;
	for(int i=0;i<=(c.getNPrr()-1);i++){
		
		cout<<"||  Ingrese la fecha de nacimiento del canino "<<i+1<<" : ";
		
		cout<<"||  anio: ";
		cin>>entero;
		nac.anio=entero;
		
		cout<<"||  mes: ";
		cin>>entero;
		nac.mes=entero;
		
		cout<<"||  dia: ";
		cin>>entero;
		nac.dia=entero;
		
		c.perros[i].setFN(nac);
		
		cin.ignore();
		cout<<"||  nombre: ";
		cin.getline(texto,14);
		apun[0]=NULL;
		apun[0] = texto;
		c.perros[i].setNom(apun[0]);
		
		cout<<"||  raza: ";
		cin.getline(texto,12);
		apun[0] = texto;
		c.perros[i].setRaza(apun[0]);

		cout<<"||  tamanio: ";
		do{
			cout<<"||  [p]-pequenio"<<endl<<"||  [m]-mediano"<<endl;
			cout<<"||  [g]-grande"<<endl<<"||  ->";
			cin >> var;
			if(var!='p' && var!='m' && var!='g'){
				cout<<"||  opcion invalida."<<endl;
			}
		}while(!(var=='p' || var=='m' || var=='g'));
		c.perros[i].setTam(var);

		cout<<"||  tipo de concentrado: ";
		do{
			cout<<"||  [a]-adultos"<<endl<<"||  [c]-cachorros"<<endl;
			cout<<"||  [r]-razas"<<endl<<"||  ->";
			cin >> var;
			if(var!='a' && var!='c' && var!='r'){
				cout<<"||  opcion invalida."<<endl;
			}
		}while( !(var=='a' || var=='c' || var=='r') );
		c.perros[i].setTcon(var);		
	}
	cout<<"Perro"<<endl;
	system("PAUSE");
	return c;
}

#endif
