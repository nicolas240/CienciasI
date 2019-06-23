#ifndef PILA_H     
#define PILA_H    

struct nodopl{int dato; nodopl *sig;};

class pila{
	private:
		nodopl *cab;
	public:
	 	pila(){
		 	cab= new nodopl;
	    	cab->dato=0;
	    	cab->sig=NULL;}
	    void Push(int v);
	    int Pop();
	    bool PilaVacia();
	    ~pila();
};
     
void pila::Push(int v){
    nodopl *t = new nodopl;
    t->dato=v; 
    t->sig=cab->sig;
    cab->sig= t;
}

int pila::Pop(){
	if(!PilaVacia()){
	    int x;
	    nodopl *t= cab->sig;
	    cab->sig= t->sig; 
	    x=t->dato;
	    delete t;
	    return x;
	}
	else
	 return -1;
    
}

bool pila::PilaVacia(){return cab->sig== NULL;}

pila::~pila(){
    nodopl *t=cab;
    while (t!=NULL){
        cab=t;
        t=t->sig;
        delete cab;
    }
}

#endif
