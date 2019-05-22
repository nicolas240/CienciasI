#include <iostream>
#include <time.h>
#include <sstream>

using namespace std;

int binAleatorio();

int main(){
	cout<<"hellow world!"<<endl;
	
	string s="10";
	stringstream geek(s);
	int x=0;
	geek>>x;
	cout<<"valor de x: "<<x/2<<endl;
	return 0;
}

int binAleatorio(){
	srand(time(NULL) );
	return rand()%2+10*(rand()%2)+100*(rand()%2);
}
