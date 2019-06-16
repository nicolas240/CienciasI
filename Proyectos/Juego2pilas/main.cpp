#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <locale>
#include "cola.h"
#include "pila.h"

using namespace std;

int main(int argc, char *argv[])
{
    //ios_base::sync_with_stdio(false);
    //wcout.imbue(locale("es_US.UTF-8"));

	cola Cola; 
	pila Pila[2]; 
	int i,j, tam, grupo=0, orden[2];
	char x; 
  
	do{
    	cout<<"Escriba un mùltiplo de 2: ";
   		cin>> tam;}
	while (tam%2!=0);
 	i=1;
	x=0;
	cout<<x;
	while(i<=tam && i<255)
	{	if((x==0)||(x==13)||(x==32)||(x>6&&x<11))
	        x++;
	    else{
			Cola.InsCola(x);
	        i++; x++;
	    }
	}
	cout<<"mire cuidadosamente los sìmbolos y elija uno\n";
	
	for(j=1; j<tam/2; j++)
	{
		cout<<"  Gr1  "<<"Gr2  "<<endl;
	  	while (!Cola.ColaVacia())
	   	{
	   		for (i=0; i<2; i++)
	      	{
				x=Cola.AtenderCola();
	       		cout<<setw(3)<< x;
	       		Pila[i].Push(x);
	       	}
	    	cout<<"\n"; 
	    }
	 
	   	cout<< "elija el grupo en el que quedò el sìmbolo elegido (1, 2): ";
	  	cin>> grupo;
	  	switch(grupo){
	    	case 1 : {orden[0]=1; orden[1]=0; break;}
	        case 2 : {orden[0]=0; orden[1]=1; break;}
			default: {cout<<"Grupo invalido"<<endl;	break;}       
	    }
	 	 for (i=0; i<2; i++)
	    {
			while (!Pila[orden[i]].PilaVacia())
	        {Cola.InsCola(Pila[orden[i]].Pop());}
	    }
	}
	j=tam/2+1;
	
	for (i=1; i<=j; i++)
	{x=Cola.AtenderCola();}
	cout<<"La figura elegida es: "<< x<<endl; 
	system("PAUSE");
	return EXIT_SUCCESS;
}
