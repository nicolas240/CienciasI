#include <iostream>
using namespace std;

int main(){
	char *tor[]={"Rafael","Leonardo","Miguel","Donatelo","Splinter"};
	char **b[5]={tor+3,tor+2,tor+4,tor,tor+1};
	char ***Apfin= b+1;
	cout<<*(tor+2)+4<<endl;
	cout<<*(*Apfin-1)+5<<endl;
	++*Apfin;
	cout<<**(b+1)+5<<endl;
	cout<<*++*--Apfin+3<<endl;
	cout<<*--Apfin[4]+4<<endl;
	return 0;
}
