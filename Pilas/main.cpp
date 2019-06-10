#include <iostream>
#include "pila.h"

using namespace std;

int main(){
	
	char c; Pila guardar(50);
	while(cin.get(c)){ 
		while(c>='0' && c<='9'){
			cout.put(c); cin.get(c); //put imprime un solo caracter
		}
		if (c==')') cout.put(guardar.sacar());
		if (c=='+') guardar.meter(c);
		if (c=='*') guardar.meter(c);
		if (c!='(') cout << ' ';
	}

	cout<< '\n';
/*	
	char c; Pila acc(50); int x;
	
	while(cin.get(c))
	{x=0;
	 while (c==' ') cin.get(c); 
	 while(c>= '0' && c<='9')
	    {x=10*x + (c-'0'); cin.get(c);}
	 if (c == '+') x= acc.sacar() + acc.sacar();
	 if (c== '*') x= acc.sacar() * acc.sacar();
	acc.meter(x);
	}
	cout << acc.sacar()<< '\n';

*/
	return 0;

}
