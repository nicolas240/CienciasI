#include <iostream>
#include <string>

#include <time.h>
#include <math.h>

//algoritmo de ordenamiento intercambio de residuos
using namespace std;

unsigned t0, t1;

void calTiempo();
void capturar(int *a, int n);
void capturar2(int *a, int n);
void imprimir(int *a, int n);
void intercambio(int *a, int i, int j);
void cambioResiduos(int *a, int izq, int der, int b);
unsigned bits(int x,int k,int j);

int main(){
	int *a= NULL;
	int n = 0;
	
	cout<<"Ingrese cuantos datos va a ordenar"<<endl;
	cin>>n;

	a = new int[n];
	capturar(a,n);
	//capturar2(a,n);	
	imprimir(a,n);
	
	t0=clock();
	cambioResiduos(a,0,n-1,5);
	t1=clock();

	cout<<"Ordenado: "<<endl;
	imprimir(a,n);

	calTiempo();
	
	delete [] a;
}

void cambioResiduos(int *a,int izq,int der, int b){
	int i,j;
	if(der>izq && b>0){
		i=izq;
		j=der;
		while(j!=i){
			while(!bits(a[i],b,1)&& i<j)i++;
			while( bits(a[j],b,1)&& j>i)j--;
			intercambio(a,i,j);
		}
		if( !bits(a[i],b,1))j++;

		cambioResiduos(a,izq,j-1,b-1);
		cambioResiduos(a,j,der,b-1);
	}
}

unsigned bits(int x,int k,int j){
	return (  (x<<k)&~(~0<<j) );
}

void capturar(int *a, int n){
	srand( time(NULL) );
	for(int i=0;i<n;i++)
		a[i]=rand()%2+10*(rand()%2)+100*(rand()%2)+1000*(rand()%2)+10000*(rand()%2);
	cout<<endl;
}
void capturar2(int *a, int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<endl;
}

void imprimir(int *a, int n){
	for(int i=0;i<n;i++){
		cout<<" |";
		cout.fill ('0');
		cout.width (5);
		cout<<a[i];
		cout<<"| "<<endl;
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
