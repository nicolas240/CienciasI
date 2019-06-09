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
	nodo *sigNombre;
	nodo *sigCarrera;
	nodo *sigHobby;
	nodo *sigEdad;
	nodo *sig;
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
		//Metodos de la multilista
		void insertar_nodo(int pos, string nombre, string carrera, string hobby, int edad);
		void insertar_final(string nombre, string carrera, string hobby, int edad);
		void insertar_inicio(string nombre, string carrera, string hobby, int edad);
		void borrar_nodo(int pos);
		void borrarDeCab(nodo *borrar);
		void modificar(int pos, string nombre, string carrera, string hobby, int edad);
		void colocarCabecera(nodo *cabeza);
		int buscarCarrera(string carrera);
		int buscarHobby(string hobby);
		int getTam();
		bool esVacia();
		nodo *buscar(string nombre);
		void imprimir();
		void imprimirCabecera();
		void imprimirCadenaOrden(int posicion);
		void imprimirPosicion(nodo *aux);
		/*void compararNombre( *cabeza);
		void compararEdad(nodo *);*/
};

void listaPrincipal::insertar_nodo(int pos, string nombre, string carrera, string hobby, int edad){
	int cont;
	if (pos > tam && pos != 1){
		//cout << "Insert.. a " << nombre << " con ins_final"<<endl;
		insertar_final(nombre, carrera, hobby, edad);
	}else if(pos == 1 && tam < 1){
		//cout << "Insert.. a " << nombre << " con ins_inicio"<<endl;
		insertar_inicio(nombre, carrera, hobby, edad);
	}else{
		//cout << "Insert.. a " << nombre << " con ins_medio"<<endl;
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
	colocarCabecera(nuevo);
	tam++;
}
//Pending
nodo* listaPrincipal::buscar(string nombre){
	int cont;
	nodo *aux = NULL;
	aux = cab;
	cont = 1;
	while(cont <= tam && (aux->nombre.compare(nombre)!=0)){
		aux = aux -> sig;
		cont++;
	}
	return aux;
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
			aux2 = aux->sig;
			borrarDeCab(aux2);
			delete aux;
		}else{
			aux2 = aux -> sig;
			aux -> sig = aux2 -> sig;
			borrarDeCab(aux2);
		}
		tam--;
	}else{
		//Confirma que como solo hay un nodo, se ingrese posicion 1 para borrarlo, de lo contrario no se borra nada
		if(pos == 1){
			cab = NULL;
			borrarDeCab(aux2);
			tam--;
		}

	}
}

void listaPrincipal::borrarDeCab(nodo *borrar){
	cout<<"Borrando a: "<<endl;
	imprimirPosicion(borrar);
	cout<<endl;
	nodo *aux = NULL;
	nodo *aux2 = NULL;
	//Si el nodo a borrar encabeza alguna de las lista de cabeza
	for(int i=0;i<=9;i++){
		if(!listaCabecera[i]->nombre.compare(borrar->nombre)){
			aux = listaCabecera[i];
			if(i==0)
				aux = aux -> sigNombre;
			if(i>0 && i<=4)
				aux = aux -> sigCarrera;
			if(i>4 && i<=8)
				aux = aux -> sigHobby;
			if(i==9)
				aux = aux -> sigEdad;
			listaCabecera[i] = aux;
		//Si el nodo a borrar no encabeza alguna lista
		}else{
			aux = listaCabecera[i];
			//Este if permite que se mire en lista de carrera y hobby a la que pertenece el nodo a borrar
			if(i == 0 or i == 9 or carac[i].compare(borrar->carrera)==0 or carac[i].compare(borrar->hobby)==0){
				do{
					if(i==0){
						aux2 = aux;
						aux = aux -> sigNombre;
					}
					if(i>0 && i<=4){
						aux2 = aux;
						aux = aux -> sigCarrera;
					}
					if(i>4 && i<=8){
						aux2 = aux;
						aux = aux -> sigHobby;
					}
					if(i==9){
						aux2 = aux;
						aux = aux -> sigEdad;
					}
						
				}while(aux->nombre.compare(borrar->nombre)!=0);	 //La funcion ".compare" arroja 0 si las cadenas comparadas son iguales
				if(i==0)
					aux2->sigNombre = aux->sigNombre;
				if(i>0 && i<=4)
					aux2->sigCarrera = aux->sigCarrera;
				if(i>4 && i<=8)
					aux2->sigHobby = aux->sigHobby;
				if(i==9)
					aux2->sigEdad = aux->sigEdad;
			}	
		}
	}
	aux = borrar;
	delete aux;		
}


void listaPrincipal::modificar(int pos, string nombre, string carrera, string hobby, int edad){
	int cont=1;
	nodo *aux= cab;
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
		colocarCabecera(nuevo);
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

//Metodo que pone los apuntadores para tener un orden
void listaPrincipal::colocarCabecera(nodo *cabeza){
	nodo *aux1, *aux2;
	int posicion;
	bool verifica;
	
	// Nombre
	if(listaCabecera[0]==NULL){
		listaCabecera[0]=cabeza;
		listaCabecera[0]->sigCarrera==NULL;
	}else if(cabeza->nombre < listaCabecera[0]->nombre){
		cabeza->sigNombre = listaCabecera[0];
		listaCabecera[0]=cabeza;
		
	}else{
		//Si en la lista hay un elemento y el que ingresa tiene un nombre mayor, se agrega al final y el apuntador de la cabeza apunta ahora a este que llega
		if(listaCabecera[0]->sigNombre==NULL){
			listaCabecera[0]->sigNombre = cabeza;
		}else{
			aux1=listaCabecera[0];
			aux2=NULL;
			int cont=0;
			while(cabeza->nombre > aux1->nombre){
				aux2 = aux1;
				aux1 = aux2->sigNombre;
				cont++;
			}
			cabeza->sigNombre=aux1;
			aux2->sigNombre=cabeza;	
		}
	}
	
	//Carreras
	posicion=buscarCarrera(cabeza->carrera);
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
	if(listaCabecera[posicion]==NULL){
		listaCabecera[posicion]=cabeza;
	}else{
		aux1=listaCabecera[posicion];
		do{
			aux2=aux1;
			aux1=aux1->sigHobby;
		}while(aux1!=NULL);
		aux1=cabeza;
		aux2->sigHobby=cabeza;
	}

	//Edad
	if(listaCabecera[9]==NULL){
		listaCabecera[9]=cabeza;
		listaCabecera[9]->sigEdad==NULL;
	}else if(cabeza->edad > listaCabecera[9]->edad){
		cabeza->sigEdad = listaCabecera[9];
		listaCabecera[9]=cabeza;
		
	}else{
		//Si en la lista hay un elemento y el que ingresa tiene una edad menor, se agrega al final y el apuntador de la cabeza apunta ahora a este que llega
		if(listaCabecera[9]->sigEdad==NULL){
			listaCabecera[9]->sigEdad = cabeza;
		}else{
			aux1=listaCabecera[9];
			aux2=NULL;
			int cont=0;
			while(cabeza->edad < aux1->edad){
				aux2 = aux1;
				aux1 = aux2->sigEdad;
				cont++;
			}
			cabeza->sigEdad=aux1;
			aux2->sigEdad=cabeza;	
		}

	}
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

//Metodos para implrimir
void listaPrincipal::imprimirCabecera(){
	for(int i=0;i<=tam-1;i++){
		cout << carac[i]<<": "<<listaCabecera[i]<<endl;
	}
}

void listaPrincipal::imprimirCadenaOrden(int posicion){
		nodo *aux;
	if(posicion!=10){
		aux = listaCabecera[posicion];
		cout<<"Cadena ordenada por: "<<carac[posicion]<<endl;
	}else{
		aux = cab;
		cout<<"Lista original: "<<endl;
	}
	int cont=1;
	while(aux!=NULL){
		imprimirPosicion(aux);
		if(posicion==0)
			aux = aux -> sigNombre;
		if(posicion>0 && posicion<=4)
			aux=aux -> sigCarrera;
		if(posicion>4 && posicion<=8)
			aux=aux -> sigHobby;
		if(posicion==9)
			aux=aux -> sigEdad;
		//Imprime la lista original ordenada segun se inserto
		if(posicion==10)
			aux=aux -> sig;
		cont++;
	}
	cout<<endl;
}

void listaPrincipal::imprimirPosicion(nodo *aux){
	cout <<"Nom: " << aux -> nombre << " | Carr: " << aux -> carrera <<" | Hob: " << aux -> hobby <<" | Edad: " << aux -> edad;
	//cout <<" | SigN: " << aux -> sigNombre <<" | SigCa: " << aux -> sigCarrera <<" | SigH: " << aux -> sigHobby <<" | SigE: " << aux -> sigEdad << endl;
	cout<<endl;
}

#endif
