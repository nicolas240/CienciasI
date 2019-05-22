#include <iostream>
#include <string>
#include <ctime>
//algoritmo de ordenamiento por inserccion
using namespace std;

void capturar(int *a, int n);
void imprimir(int *a, int n);

int main(){
	int *a= NULL;
	int n, i, j, v;
	double  tTotal=0;
	unsigned t0,t1;

	cout<<"Ingrese cuantos datos va a ordenar"<<endl;
	cin>>n;

	a = new int[n];
	capturar(a,n);
	//cout<<"Arreglo desordenado: ";
	//imprimir(a,n);	
	cout<<endl;
	for(i=1;i<n;i++){
		j=i;
		v=a[j];
		t0=clock();
		while(a[j-1]>v && j>0){
			a[j]=a[j-1];
			j--;
		}
		a[j]=v;
		t1=clock();
		tTotal=tTotal+(double(t1-t0)/CLOCKS_PER_SEC)*100000;
	}
	cout<<"Arreglo ordenado: ";
	imprimir(a,n);
	cout<<endl;
	delete []a;
	a= NULL;
	cout<<endl<<"Tiempo de ejecucion: "<<tTotal<<" microsegundos"<<endl;
	return 0;
}

void capturar(int *a, int n){
	for(int i=0;i<n;i++){
		//cout<<i<<": ";
		a[i]=n-i;
	}
}
void imprimir(int *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
