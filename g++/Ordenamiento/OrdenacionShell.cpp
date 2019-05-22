#include <iostream>
#include <string>

//algoritmo de ordenamiento Shell
using namespace std;

unsigned t0, t1;

double calTiempo();
void capturar(int *a, int n);
void imprimir(int *a, int n);
void ordenShell(int *a, int n);

int main(){
	int *a= NULL;
	int n = 0;
	int item = 0;
	
	cout<<"Ingrese cuantos datos va a ordenar"<<endl;
	cin>>n;
	a = new int[n];
	capturar(a,n);
	imprimir(a,n);
	
	ordenShell(a, n);

	cout<<"Ordenado: "<<endl;
	imprimir(a,n);
	cout<<endl<<"Tiempo de ejecucion: "<<calTiempo() * 100000<<" microsegundos"<<endl;
	
}

void ordenShell(int *a, int n){
	int i, j, h;
	int aux;
	
	for(h=1; h<=n/9; h=3*h+1);
	t0=clock();
	for(; h>0; h/=3)
		for(i=(h-1)+1; i<n; i+=1){
			aux=a[i];
			j=i;
			while(j>h-1 && a[j-h]>aux){
				a[j]=a[j-h];
				j-=h;
				//imprimir(a,n);
			}
			a[j]=aux;
			//imprimir(a,n);
		}
	t1=clock();

	//cout<<"h: "<<h;
}

void capturar(int *a, int n){
	int aux=0;
	for(int i=1;i<=n;i++){
		a[aux] = i;
		aux++;
	}
	cout<<endl;
}

void imprimir(int *a, int n){
	cout<<"| ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" | ";
	}
	cout<<endl;
}

double calTiempo(){
  return (double(t1-t0)/CLOCKS_PER_SEC);
}

