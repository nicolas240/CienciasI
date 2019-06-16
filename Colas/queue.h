#ifndef QUEUE_H
#define QUEUE_H
using namespace std;

template <class T>
struct nodo{
	T dato;
	nodo <T> *sig, *ant;
};

template <class T>
class Queue{
	public:
    Queue(){tam=0; cab=NULL;fin=NULL;}
    ~Queue(){nodo <T> *t=cab;
			while (t!=fin){
			cab=t;  t=t->sig;  delete cab;}}
		void enqueue(T V, char pos);
		void imprimir(char pos);
		void imprimirCola(char pos);
		T dequeue(char pos);
		bool vacia();
		bool llena();
 	private:
		nodo <T> *cab, *fin;
		int tam;
 };
/*
template <class T>
void Queue<T>::enqueue(T info, char pos){
	cout<<"llega: "<<info<<", "<<pos<<endl;
	nodo <T> *nuevo =new nodo<T>;
	nuevo->dato=info;
	if(vacia()){
		cab=fin=nuevo;
		nuevo->sig=nuevo->ant=NULL;
		cab->sig=fin->ant=nuevo;
		tam++;
	}
	else if (pos=='D'){
			cout<<"entra a la derecha"<<endl;
			nuevo->sig=cab->sig;
			cab->sig=nuevo;
			nuevo->ant=NULL;
			nuevo->sig->ant=nuevo;
			tam++;
		}else{
			cout<<"entra a la izquierda"<<endl;
			nuevo->ant=fin->ant;
			fin->ant=nuevo;
			nuevo->sig=NULL;
			nuevo->ant->sig=nuevo;
			tam++;
		}
}*/

template <class T>
void Queue<T>::enqueue(T info, char pos){
	nodo <T> *nuevo = new nodo<T>;
	nuevo->dato= info;
	if(vacia()){
		cab=fin=nuevo;
		nuevo->sig=nuevo->ant=NULL;
		tam++;
	}
	else{
		if (pos=='D'){
			nuevo->ant=NULL;
			nuevo->sig=cab;
			cab->ant=nuevo;
			cab=nuevo;
			tam++;
		}else{
			nuevo->sig=NULL;
			nuevo->ant=fin;
			fin->sig=nuevo;
			fin=nuevo;
			tam++;
		}
	}
}

template <class T>
T Queue<T>::dequeue(char pos){
	nodo <T> *aux = NULL;
	if(tam==0){
		cout<<"Cola vacia"<<endl;
		return 0;
	}
	if(tam==1){
		if(cab->ant!=NULL){
			aux=cab->sig;
			delete cab;
		}else{
			aux=fin->ant;
			delete fin;
		}
		tam--;
		return aux->dato;
	}
	if(pos=='D'){
		aux = fin;
		fin = fin->ant;
	}else{
		aux = cab;
		cab = cab->sig;
	}
	tam--;
	return aux->dato;
}

template <class T>
bool Queue<T>::vacia(){
	if(tam==0)
		return true;
	return false;
}

template <class T>
void Queue<T>::imprimir(char pos){
	T men;
	nodo <T> *aux;
	if(tam==0){
		cout<<"Cola vacia."<<endl;
	}else{
		if(tam==1)
			cout<<cab->dato<<endl;
		else{
			if(pos=='I'){
				cout<<"Izquierda: "<<cab->sig->dato<<endl;
			}else{
				cout<<"Derecha: "<<fin->ant->dato<<endl;
			}
		}
	}
}

template <class T>
void Queue<T>::imprimirCola(char pos){
	nodo <T> *aux = NULL;
	int cont = 1;
	if(tam==0)
		cout<<"Cola Vacia."<<endl;
	else{
		if(pos=='I'){
			cout<<"Tam: "<<tam<<endl;
			aux = cab;
			while (cont<=tam){
				cout<<" | "<< aux->dato<<" | ";
				aux=aux->sig;
				cont++;
			}
			cout<<endl;
		}else{
			cout<<"Tam: "<<tam<<endl;
			aux = fin;
			while(cont<=tam){
				cout<<" | "<< aux->dato<<" | ";
				aux=aux->ant;
				cont++;
			}
			cout<<endl;
		}
	}
}
#endif
