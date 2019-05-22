#include <iostream>

using namespace std;

int main(){
	int n,i,j;
	int **a;
	int total=0;

	cout<<"Ingrese n"<<endl;
	cin>>n;
	a= new int *[n];

	for(i=0;i<n;i++){
		a[i]=new int[n];
		for(j=0;j<n;j++){
			a[i][j]=i*j;
			total= total+sizeof(**(a+i));
			//total= total+sizeof(a[i][j]);	
			//total= total+sizeof(**a);
		}
		total= total+sizeof(*(a+i));//imprime el tamaño de lo apuntadores
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
		delete a[i];
	}
	cout<<"total del algoritmo "<<endl;
	cout<<"Imprime **a"<<sizeof(**a)<<endl;
	cout<<"Total de memoria utilizada"<<endl;
	total=total+sizeof(i)+sizeof(j)+sizeof(n)+sizeof(**a);
	cout<<total<<endl;
	
	delete []a; 
	return 0;
}
