#include <iostream>

//algoritmo de ordenamiento por seleccion

#if __WINDOWS__
#include <windows.h>
#include <stdio.h>
LARGE_INTEGER t_ini, t_fin;
#endif //__Windows__

#ifdef __linux__
#include <ctime>
unsigned t0,t1; 
#endif 

using namespace std;

void intercambiar(int *a, int min, int j);
void capturar(int *a, int n);
void imprimir(int *a, int n);
double calTiempo();
void tiempo1();
void tiempo2();

int main(){
	int *a= NULL;
	int n, i, j, min;
	double  tTotal=0, tiempo;

	cout<<"Ingrese cuantos datos va a ordenar"<<endl;
	cin>>n;

	a = new int[n];
	capturar(a,n);
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<n;j++){
			tiempo1();
			if(a[j]<a[min])
				min=j;
			intercambiar(a,min,j);
			tiempo2();
			tiempo=calTiempo();
			tTotal=tTotal+tiempo*100000;
		}
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
		cout<<i<<": ";
		cin>>a[i];
	}
}
void imprimir(int *a, int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
double calTL(){
	#if _WINDOWS
		LARGE_INTEGER freq;
 		QueryPerformanceFrequency(&freq);
		return (double)(&t_fin->QuadPart - &t_ini->QuadPart) / (double)freq.QuadPart;
	#else
		return (double(t1-t0)/CLOCKS_PER_SEC);
	#endif
}
void tiempo1(){
	#if _WINDOWS
		QueryPerformanceCounter(&t_ini);
	#else
		t0= clock();
	#endif
}
void tiempo2(){
	#if _WINDOWS
		QueryPerformanceCounter(&t_fin);		
	#else 
		t1= clock();
	#endif
}
