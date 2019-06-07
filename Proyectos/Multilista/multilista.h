#ifndef MULTILISTA_H
#define MULTILISTA_H
#include <string>
#include <iostream>
using namespace std;

//Nodo de la lista de datos
struct nodo{
	string nombre;
	string carrera;
	string hobby;
	int edad;
	nodo *sigNombre = NULL;
	nodo *sigCarrera = NULL;
	nodo *sigHobby = NULL;
	nodo *sigEdad = NULL;
	nodo *sig = NULL;
};

// Listad de datos
class listaPrincipal{
	private:
		nodo **listaCabecera;
		string carac[10]= {"Nombre","Electronica","Industrial","Sistemas","Catastral","Danza","Natacion","Basquet","Beisball","Edad"};;
		nodo *cab;
		int tam;

	public:
		listaPrincipal(){
			cab = NULL;
			tam = 0;
			listaCabecera = new nodo *[10];
			for(int i=0;i<=9;i++)
				listaCabecera[i]=NULL;
		}
		~listaPrincipal(){
			int cont=1;
			nodo *recorre, *aux=cab;
			while(cont < tam && aux!=NULL){
				recorre=aux;
				aux = aux -> sig;
				delete recorre;
				cont++;
			}
			delete []listaCabecera;
		}
		void insertar_nodo(int pos, string nombre, string carrera, string hobby, int edad);
		void insertar_final(string nombre, string carrera, string hobby, int edad);
		void insertar_inicio(string nombre, string carrera, string hobby, int edad);
		void borrar_nodo(int pos);
		void modificar(int pos, string nombre, string carrera, string hobby, int edad);
		int getTam();
		bool esVacia();
		bool buscar(int pos);
		void imprimir();
		void imprimirCabecera();
		void colocarCabecera(nodo *cabeza);
		int buscarCarrera(string carrera);
		int buscarHobby(string hobby);
		/*void compararNombre( *cabeza);
		void compararEdad(nodo *);*/
};

void listaPrincipal::insertar_nodo(int pos, string nombre, string carrera, string hobby, int edad){
	int cont;
	if (pos > tam && pos != 1){
		insertar_final(nombre, carrera, hobby, edad);
	}else if(pos == 1 && tam < 1){
		insertar_inicio(nombre, carrera, hobby, edad);
	}else{
		nodo *nuevo, *aux, *aux2;
		nuevo = new nodo;
		nuevo -> nombre = nombre;
		nuevo -> carrera = carrera;
		nuevo -> hobby = hobby;
		nuevo -> edad = edad;
		nuevo -> sigNombre = NULL;
		nuevo -> sigCarrera = NULL;
		nuevo -> sigHobby = NULL;
		nuevo -> sigEdad = NULL;
		aux = cab;
		cont = 1;
		while(cont < pos-1 && aux!=NULL){
			aux = aux -> sig;
			cont++;
		}
		nuevo -> sig = aux -> sig;
		aux -> sig = nuevo;
		tam++;
		colocarCabecera(nuevo);
	}
}

void listaPrincipal::insertar_final(string nombre, string carrera, string hobby, int edad){
	int cont;
	nodo *nuevo, *aux;
	nuevo = new nodo;
	nuevo -> nombre = nombre;
	nuevo -> carrera = carrera;
	nuevo -> hobby = hobby;
	nuevo -> edad = edad;
	nuevo -> sigNombre = NULL;
	nuevo -> sigCarrera = NULL;
	nuevo -> sigHobby = NULL;
	nuevo -> sigEdad = NULL;
	aux = cab;
	cont = 1;
	while(cont < tam && aux!=NULL){
		aux = aux -> sig;
		cont++;
	}
	aux -> sig = nuevo;
	colocarCabecera(nuevo);
	tam++;
}

void listaPrincipal::insertar_inicio(string nombre, string carrera, string hobby, int edad){
	nodo *nuevo;
	nuevo = new nodo;
	nuevo -> nombre = nombre;
	nuevo -> carrera = carrera;
	nuevo -> hobby = hobby;
	nuevo -> edad = edad;
	nuevo -> sigNombre = NULL;
	nuevo -> sigCarrera = NULL;
	nuevo -> sigHobby = NULL;
	nuevo -> sigEdad = NULL;
	nuevo -> sig = cab;
	cab = nuevo;
	tam++;
	colocarCabecera(nuevo);
}
//Pending
bool listaPrincipal::buscar(int pos){
	int cont;
	nodo *aux = NULL;
	aux = cab;
	cont = 1;
	while(cont <= pos-1 && aux!=NULL){
		aux = aux -> sig;
		cont++;
	}
	return true;
}

void listaPrincipal::borrar_nodo(int pos){
	int cont;
	nodo *aux = NULL;
	nodo *aux2 = NULL;
	aux = cab;
	cont = 1;
	while(cont < pos -1 && aux!=NULL){
		aux = aux -> sig;
		cont++;
	}
	if(tam > 1){
		if(pos == 1){
			cab = aux -> sig;
			delete aux;
		}else{
			aux2 = aux -> sig;
			aux -> sig = aux2 -> sig;
			delete aux2;
		}
		tam--;
	}else{
		//Confirma que como solo hay un nodo, se ingrese posicion 1 para borrarlo, de lo contrario no se borra nada
		if(pos == 1){
			cab = NULL;
			tam--;
		}

	}
}

void listaPrincipal::modificar(int pos, string nombre, string carrera, string hobby, int edad){
	int cont=1;
	nodo *aux= cab;
	while(cont < pos -1 && aux!=NULL){
		aux = aux -> sig;
		cont++;
	}
	if(pos==1){
		cab -> nombre = nombre;
		cab -> carrera = carrera;
		cab -> hobby = hobby;
		cab -> edad = edad;
		cab -> sigNombre = NULL;
		cab -> sigCarrera = NULL;
		cab -> sigHobby = NULL;
		cab -> sigEdad = NULL;
	}else{
		aux->sig -> nombre = nombre;
		aux->sig -> carrera = carrera;
		aux->sig -> hobby = hobby;
		aux->sig -> edad = edad;
		aux->sig -> sigNombre = NULL;
		aux->sig -> sigCarrera = NULL;
		aux->sig -> sigHobby = NULL;
		aux->sig -> sigEdad = NULL;
	}
}

bool listaPrincipal::esVacia(){
	if(cab == NULL)
		return true;
	else
		return false;
}

int listaPrincipal::getTam(){
	return tam;
}

void listaPrincipal::imprimir(){
	nodo *aux = cab;
	int cont = 1;
	while(cont <= tam ){
		cout <<"Nom: " << aux -> nombre << " | Carr:" << aux -> carrera <<" | Hob: " << aux -> hobby <<" | Edad: " << aux -> edad;
		cout <<" | SigN: " << aux -> sigNombre <<" | SigCa: " << aux -> sigCarrera <<" | SigH: " << aux -> sigHobby <<" | SigE: " << aux -> sigEdad << endl;
		aux = aux -> sig;
		cont++;
	}
}

void listaPrincipal::imprimirCabecera(){
	for(int i=0;i<=tam-1;i++){
		cout << carac[i]<<": "<<listaCabecera[i]<<endl;
	}
}

void listaPrincipal::colocarCabecera(nodo *cabeza){
	nodo *aux1, *aux2;
	int posicion;
	bool verifica;
	
	// Nombre
	/*if(listaCabecera[0]==NULL){
		listaCabecera[0]=cabeza;
		cout<<"Entro a verificar el NULL"<<endl;
	}
	else{
		cout<<"Entro a mirar cuando no es NULL"<<endl;
		aux1=listaCabecera[0];
		aux2=NULL;
		int cont=0;
		while(aux1->nombre > cabeza->nombre){
			aux2 = aux1;
			aux1 = aux1->sigNombre;
			cout << aux2->nombre <<endl;
			cout << cabeza->nombre <<endl;
			cout<<"veces del while: "<<cont<<endl;
			cont++;
		}
		cout<<"salio while while "<<cont<<endl;
		aux2->sigNombre=cabeza;
		cabeza->sig=aux1;
		listaCabecera[0]=aux1;
		cout<<"Salio del while de recorrer la cabeza"<<endl;
	}*/	
	//Carreras
	posicion=buscarCarrera(cabeza->carrera);
	cout<<"Posicion de la carrera: "<<posicion<<" "<<carac[posicion]<<endl;
	if(listaCabecera[posicion]==NULL){
		listaCabecera[posicion]=cabeza;
	}else{
		aux1=listaCabecera[posicion];
		do{
			aux2=aux1;
			aux1=aux1->sigCarrera;
		}while(aux1!=NULL);
		aux1=cabeza;
		aux2->sigCarrera=aux1;
	}
	 
	//Hobby
	posicion=buscarHobby(cabeza->hobby);
	cout<<"Posicion del hobby: "<<posicion<<" "<<carac[posicion]<<endl;
	if(listaCabecera[posicion]==NULL){
		listaCabecera[posicion]=cabeza;
	}else{
		aux1=listaCabecera[posicion];
		do{
			aux2=aux1;
			aux1=aux1->sigHobby;
		}while(aux1!=NULL);
		aux1=cabeza;
		aux2->sigHobby=aux1;
	}	
	//Edad
	/*if(listaCabecera[9]==NULL){
		listaCabecera[9]=cabeza;
	}*/
}

int listaPrincipal::buscarCarrera(string carrera){
	for(int i=1;i<=4;i++){
		if(!carac[i].compare(carrera))
			return i;
	}
	return -1;//retorno de control
}
int listaPrincipal::buscarHobby(string hobby){
	for(int i=5;i<=8;i++){
		if(!carac[i].compare(hobby))
			return i;
	}
	return -1;//retorno de control	
}

#endif
