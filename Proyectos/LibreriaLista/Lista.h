	
	template <class T>
	void lista::insertar_final(T D){
		nodo<T> *nuevo, *aux;
		nuevo = new nodo<T>;
		nuevo -> Dato = D
		nuevo -> sig = NULL;
		aux = cab; 
		while(cont < tam && aux!=NULL){
			aux = aux -> sig;
			cont++;				
		}
		aux -> sig = nuevo;
		tam++;
	}
	
	template <class T>
	void lista::public void insertar_inicio(T D){
		nodo<T> *nuevo;
		nuevo = new nodo<T>;
		nuevo -> Dato = D;
		nuevo -> sig = cab;
		cab = nuevo;
		cab++;
	}
