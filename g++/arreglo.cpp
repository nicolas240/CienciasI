#include <iostream>
#include <ctime>

using namespace std;

int main(){
	int *a;
	int n,i,j;
	int total=0;
	unsigned t0,t1;
	cout<<"Ingrese el tamaño de la matriz"<<endl;
	cin>>n;
	t0=clock();
	for(i=0;i<n;i++){
		a= new int[n];
		for(j=0;j<n;j++){
			a[j]=j*i;
			//cout<<a[j]<<" ";		
		}
		//cout<<endl;
		total=sizeof(a[i])+total;
		//total=sizeof(a)+total;
		delete []a;
	}
	t1=clock();
	cout<<endl<<"Espacio utilizado por el programa:"<<endl;
	cout<<"total del arreglo "<<total<<endl;
	total= total+sizeof(i)+sizeof(j)+sizeof(n)+sizeof(*a);
	cout<<"total del algoritmo "<<total<<endl;
	cout<<endl<<"Tiempo de ejecucion: "<<(double(t1-t0)/CLOCKS_PER_SEC)*1000<<" milisegundos"<<endl;
	return 0;
}
