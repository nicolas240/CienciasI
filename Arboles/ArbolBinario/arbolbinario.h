#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
using namespace std;

template <class T>
struct nodo{
	T dato;
	nodo<T> *izq, *der;
};

template <class T>
class arbolbinario{
	private:
		nodo<T> control;
		int tam;
		int max;
		nodo<T> **arbol = NULL;
		
	public:
		arbolbinario(int tam){
			max = tam;
			//Asigancion de tamaï¿½o y llenado basico del arreglo que representa al arbol
			arbol = new nodo<T>*[tam+1];
			//cout<<"Aqui"<<endl;
			for(int i=0;i<=tam;i++){
				arbol[i] = new nodo<T>;
				arbol[i]->der=arbol[i+1];
			}
			arbol[tam]->der=NULL;
			arbol[0]->izq=NULL;
			//cout<<"Aqui"<<endl;
		}
		~arbolbinario(){
			delete arbol;
		}
		
		void insertar(T dato);
		T buscar(T dato);
		void eliminar(T dato);
};


template <class T>
void arbolbinario<T>::insertar(T dato){
	nodo<T> *aux;
	if(arbol[0]->izq==NULL){				//Si el arbol vacio
		arbol[0]->izq=arbol[0]->der;
		arbol[0]->der=arbol[0]->izq->der;
		arbol[0]->izq->dato=dato;
		arbol[0]->izq->izq=NULL;
		arbol[0]->izq->der=NULL;
		tam++;
	}else{
		bool insert = false;
		aux=arbol[0]->izq;		//Se asigna a aux la raiz del arbol.
		while(insert == false){
			//Por izquierda (menor)
			if(aux->dato<dato && aux->izq != NULL){
				aux=aux->izq;
			}
			if(aux->dato<dato && aux->izq == NULL){
				arbol[0]->der->dato=dato;
				//FALTA condicion para cuando solo queda una posicion por insertar arbol[0]->der = NULL;
				aux->izq = arbol[0]->der;   //Se asigna al padre por izq la direccion del nuevo hijo.
				arbol[0]->der=arbol[0]->der->der;
				aux->izq = NULL;
				aux->der = NULL;
				insert = true;
			}
			//Por derecha (mayor)
			if(aux->dato>dato && aux->der != NULL){
				aux=aux->der;
			}
			if(aux->dato>dato && aux->der == NULL){
				arbol[0]->der->dato=dato;
				//FALTA condicion para cuando solo queda una posicion por insertar arbol[0]->der = NULL;
				aux->der = arbol[0]->der;   //Se asigna al padre por der la direccion del nuevo hijo.
				arbol[0]->der=arbol[0]->der->der;
				aux->izq = NULL;
				aux->der = NULL;
				insert = true;
			}
		}
		tam++;
	}
	
	cout<<
	cout<<"Fin insertar.."<<endl;
}

#endif
