#include <iostream>
#include <string>

//algoritmo de ordenamiento Shell
using namespace std;

unsigned t0, t1;

void calTiempo();
void capturar(int *a, int n);
void imprimir(int *a, int n);
void intercambio(int *a, int i, int j);
void ordenRapido(int *a, int izq, int der);

int main(){
	int *a= NULL;
	int n = 0;
	
	cout<<"Ingrese cuantos datos va a ordenar"<<endl;
	cin>>n;

	a = new int[n];
	capturar(a,n);
	imprimir(a,n);
	
	t0=clock();
	ordenRapido(a,0,n-1);
	t1=clock();

	cout<<"Ordenado: "<<endl;
	imprimir(a,n);

	calTiempo();
	
	delete [] a;
}

void ordenRapido(int *a,int izq,int der){
	int i,j,v;
	if(der>izq){
		v=a[der];
		i=izq-1;
		j=der;
		for(;;){
			while(a[++i]<v);
			while(a[--j]>v);
			if(i>=j)
				break;
			intercambio(a,i,j);
		}
		intercambio(a,i,der);
		ordenRapido(a,izq,i-1);
		ordenRapido(a,i+1,der);
	}
}

void capturar(int *a, int n){
	for(int i=0;i<n;i++)
		a[i]=n-i;
	cout<<endl;
}

void imprimir(int *a, int n){
	for(int i=0;i<n;i++){
		cout<<" |"<<a[i]<<"| ";
	}
	cout<<endl;
}

void intercambio(int *a, int i, int j){
	int aux=a[i];
	a[i]=a[j];
	a[j]=aux;
}

void calTiempo(){
  cout<<"Tiempo de ejecucion: "<<(double(t1-t0)/CLOCKS_PER_SEC)*1000000<<" microsegundos"<<endl;
}
