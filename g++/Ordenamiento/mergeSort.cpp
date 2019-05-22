#include <iostream>
#include <string>

//algoritmo de ordenamiento mergeSort
using namespace std;

unsigned t0, t1;

void calTiempo();
void capturar(int *a, int n);
void imprimir(int *a, int n);
void mergeSort(int *a, int first, int last);
void mergeList(int *a, int start1, int end1, int start2, int end2);

int main(){
	
	/*cout<<"Ingrese cuantos datos va a ordenar"<<endl;
	cin>>n;
	imprimir(a,n);*/

	for(int i=10;i<=500;i+=10){
		int *a= NULL;

		a = new int[i];
		capturar(a,i);
		
		cout<<endl<<"prueba con "<<i<<" datos de entrada: ";
		t0=clock();
		mergeSort(a,0,i-1);
		t1=clock();
		
		cout<<"Ordenado: "<<endl;
		//imprimir(a,i);

		calTiempo();
		
		delete []a;
	}
}

void mergeSort(int *a, int first, int last){
	int middle;
	if(first<last){
		middle = (first + last)/2;
		mergeSort(a,first,middle);
		mergeSort(a,middle+1,last);
		mergeList(a,first,middle,middle+1,last);
	}
}

void mergeList(int *a, int start1, int end1, int start2, int end2){
	int inicio=0, *result=NULL, finalStart= start1, finalEnd= end2;
	result= new int[end2+1];
	while( start1 <= end1 && start2 <= end2 ){
		if (a[start1]< a[start2]){
			result[inicio]=a[start1];
			start1++;
		}else{
			result[inicio]=a[start2];
			start2++;
		}
		inicio++;
	}

	if(start1 <= end1){
		for(int i=start1;i<=end1;i++){
			result[inicio]=a[i];
			inicio++;
		}
	}

	inicio=0;
	for(int i=finalStart;i<=finalEnd;i++){
		a[i]=result[inicio];
		inicio++;
	}

	delete []result;
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
