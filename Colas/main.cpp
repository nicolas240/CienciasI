#include <iostream>
#include "queue.h"

using namespace std;

int main(){
	Queue <int> P;

	P.enqueue(3,'I');
	P.enqueue(8,'D');
	P.enqueue(10,'I');
	P.dequeue('D');
	P.enqueue(12,'D');
	P.dequeue('I');

	P.imprimirCola('I');


	cout<< '\n';
	return 0;
}
