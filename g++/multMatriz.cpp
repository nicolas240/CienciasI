#include <iostream>
#include <ctime>

using namespace std;

unsigned t0,t1;

void sumar(int **a,int **b,int **c,int n,int m);
void calTiempo();
void capturar(int **a,int n,int m);
void imprimir(int **a,int n,int m);
void liberarMemoria(int **a, int n, int m);

int main(){
	int **a, **b, **c;
	int n,m;
	
	cout<<"Ingrese el numero de filas de la matriz"<<endl;
	cin>>n;
	cout<<"Ingrese el numero de columnas de la matriz"<<endl;
	cin>>m;
	
	a= new int *[n];
	b= new int *[m];
	c= new int *[n];
	
	capturar(a,n,m);
	//imprimir(a,n,m);

	capturar(b,m,n);
	//imprimir(b,m,n);

	t0=clock();
	sumar(a,b,c,n,m);
	t1=clock();

	//imprimir(c,n,n);

	liberarMemoria(a,n,m);
	liberarMemoria(b,m,n);
	liberarMemoria(c,n,n);

	calTiempo();

	return 0;
}

void calTiempo(){
	cout<<endl<<"Tiempo de ejecucion: "<<(double(t1-t0)/CLOCKS_PER_SEC)*1000<<" milisegundos"<<endl;
}

void sumar(int **a, int **b, int **c, int n, int m){
	for(int i=0;i<n;i++){
		c[i]= new int[n];
		for(int j=0;j<n;j++){
			c[i][j]=0;
			for(int k=0;k<m;k++)
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
		}
	}
}

void capturar(int **a, int n, int m){
	for(int i=0;i<n;i++){
		a[i]=new int[m];
		for(int j=0;j<m;j++)
			a[i][j]=i+j;
	}
}

void imprimir(int **a, int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<" |"<<a[i][j]<<"|" ;
		cout<<endl;		
	}
	cout<<endl;
}

void liberarMemoria(int **a, int n, int m){
	for(int i=0;i<n;i++){
		delete a[i];
	}
	delete []a;
}
