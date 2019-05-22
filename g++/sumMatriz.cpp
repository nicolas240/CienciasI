#include <iostream>
#include <ctime>

using namespace std;

unsigned t0,t1;

void sumar(int **a,int **b,int **c,int n);
void calTiempo();
void capturar(int **a,int n);
void imprimir(int **a,int n);
void liberarMemoria(int **a, int n);

int main(){
	int **a, **b, **c;
	int n;
	
	cout<<"Ingrese el tamaño de las matrices que se van a sumar"<<endl;
	cin>>n;
	
	a= new int *[n];
	b= new int *[n];
	c= new int *[n];
	
	capturar(a,n);
	imprimir(a,n);

	capturar(b,n);
	imprimir(b,n);

	t0=clock();
	sumar(a,b,c,n);
	t1=clock();

	imprimir(c,n);

	liberarMemoria(a,n);
	liberarMemoria(b,n);
	liberarMemoria(c,n);
	
	calTiempo();

	return 0;
}

void calTiempo(){
	cout<<endl<<"Tiempo de ejecucion: "<<(double(t1-t0)/CLOCKS_PER_SEC)*1000<<" milisegundos"<<endl;
}

void sumar(int **a, int **b, int **c, int n){
	for(int i=0;i<n;i++){
		c[i]= new int[n];
		for(int j=0;j<n;j++)
			c[i][j]=a[i][j]+b[i][j];
	}
}

void capturar(int **a, int n){
	for(int i=0;i<n;i++){
		a[i]=new int[n];
		for(int j=0;j<n;j++)
			a[i][j]=i+j;
	}
}

void imprimir(int **a, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<" |"<<a[i][j]<<"|" ;
		cout<<endl;		
	}
	cout<<endl;
}

void liberarMemoria(int **a, int n){
	for(int i=0;i<n;i++){
		delete a[i];
	}
	delete []a;
}
