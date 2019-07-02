#include <cstdlib>
#include <iostream>

#ifndef COLA_H     
#define COLA_H 

struct nodocl{int dato; nodocl *sig;};

using namespace std;

class cola{nodocl *cab,*fin;
	public: cola(){cab=fin=NULL;}
	void InsCola(int i);
	int AtenderCola();
	void ImprimirCola();
	bool ColaVacia();
	~cola();
 };

void cola::InsCola(int i){
	nodocl *nuevo;
	nuevo= new nodocl;
	nuevo->dato=i;
	nuevo->sig= NULL;
	if (cab==NULL){cab=nuevo;}
	else {fin->sig = nuevo;}
	fin=nuevo;
}



int cola::AtenderCola(){  	
	if(!ColaVacia()){
		int x;
	    nodocl *aux = cab; 
	    cab=aux->sig;
	    x=aux->dato;
	    delete aux;
	    return x;
	}
	else 
		return -1;
}

void cola::ImprimirCola(){
	nodocl *aux;
	aux=cab;
	while(aux!=NULL){
		cout<<aux->dato<<" ";
		aux=aux->sig;}    
}

bool cola::ColaVacia(){
	return (cab==NULL);
}

cola::~cola(){
	nodocl *aux;
	while(cab!=NULL){
		aux= cab;
		cab=aux->sig;
		delete aux;
	}
	delete cab;
	}
#endif
