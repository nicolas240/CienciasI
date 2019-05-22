#include <iostream>
#include <string>
#include <ctime>
//algoritmo de ordenamiento por inserccion
using namespace std;

unsigned t0, t1;
double calTiempo();
int posicion;
void capturar(int *a, int n);
int busquedaBinaria(int *a, int item, int n);

int main(){
	int *a= NULL;
	int n = 0;
	int item = 0;
	
	cout<<"Ingrese cuantos datos va a buscar"<<endl;
	cin>>n;
	a = new int[n];
	capturar(a,n);
	
	cout<<"Ingrese el valor a buscar"<<endl;
	cin>>item;
	cout<<"Posicion de "<<item<<": ";
	t0= clock();
	posicion=busquedaBinaria(a,item,n);
	cout<<posicion<<endl;
	cout<<"t0: "<<t0<<endl;
	t1= clock();
	cout<<"t1: "<<t0<<endl;
	cout<<"\n tiempo de ejecucion:"<<calTiempo()*1000<<"milisegundos"<<endl;
	cout<<"tiempoTotal: "<<calTiempo()<<endl;
}

void capturar(int *a, int n){
	cout<<"| ";
	for(int i=0;i<n;i++){
		a[i] = i+1;
		cout<<a[i]<<" | ";
	}
	cout<<endl;
}

int busquedaBinaria(int *a, int item, int n)
{
  int mayor = n-1;
  int menor = 0;
  int centro;  
  while (menor <= mayor){
      centro = (mayor + menor)/2;
      cout<<"Centro:"<<centro<<endl;
      if (a[centro] == item){
      	return centro;
	  }else{
	  	if (item < a[centro]){
	  		mayor=centro-1;
		}else{
			menor=centro+1;
		}
	  }
    }
  return -1;
}

double calTiempo(){
  return (double(t1-t0)/CLOCKS_PER_SEC);
}
