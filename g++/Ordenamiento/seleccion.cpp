#include <iostream>
#include <string>
#include <ctime>
//algoritmo de ordenamiento por seleccion
using namespace std;

void intercambiar(int *a, int min, int j);
void capturar(int *a, int n);
void imprimir(int *a, int n);

int main(){
	int *a= NULL;
	int n, i, j, min;
	double  tTotal=0;
	unsigned t0,t1;

	cout<<"Ingrese cuantos datos va a ordenar"<<endl;
	cin>>n;

	a = new int[n];
	capturar(a,n);
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<n;j++){
			t0=clock();
			if(a[j]<a[min])
				min=j;
			intercambiar(a,min,i);
			t1=clock();
			tTotal=tTotal+(double(t1-t0)/CLOCKS_PER_SEC)*100000;
		}
		//to_string(a[i]);
	}
	cout<<"Arreglo ordenado: ";
	imprimir(a,n);
	cout<<endl;
	delete []a;
	a= NULL;
	cout<<endl<<"Tiempo de ejecucion: "<<tTotal<<" microsegundos"<<endl;
	return 0;
}

void intercambiar(int *a, int min, int j){
	int pivote = a[min];
	a[min]= a[j];
	a[j]= pivote;
	//cout<<"intercambiar: pivote:"<<pivote<<", a[min] "<<a[min]<<", a[j] "<<a[j]<<endl;
}
void capturar(int *a, int n){
	for(int i=0;i<n;i++){
		//cout<<i<<": ";
		a[i]=i;
	}
}
void imprimir(int *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
