#ifndef PILA_H     
#define PILA_H    

template <class T>
struct nodopl{T dato; nodopl *sig;};

template <class T>
class pila{
	private:
		nodopl <T> *cab;
	public:
	 	pila(){
		 	cab= new nodopl<T>;
	    	cab->dato=' ';
	    	cab->sig=NULL;}
	    void Push(T v);
	    T Pop();
	    bool PilaVacia();
	    ~pila();
};
     
template <class T>     
void pila<T>::Push(T v){
    nodopl <T> *t = new nodopl <T>;
    t->dato=v; 
    t->sig=cab->sig;
    cab->sig= t;
}

template <class T>
T pila<T>::Pop(){
    T x;
    nodopl <T> *t= cab->sig;
    cab->sig= t->sig; 
    x=t->dato;
    delete t;
    return x;
}

template <class T>     
bool pila<T>::PilaVacia(){return cab->sig== NULL;}

template <class T>
pila<T>::~pila(){
    nodopl <T> *t=cab;
    while (t!=NULL){
        cab=t;
        t=t->sig;
        delete cab;
    }
}

#endif
