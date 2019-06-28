#include <iostream>
#include "monticulo.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Monticulo ejemplo;

	ejemplo.insertar(60);
	ejemplo.insertar(80);
	ejemplo.insertar(20);
	ejemplo.insertar(90);
	ejemplo.insertar(50);
	ejemplo.insertar(40);
	ejemplo.insertar(30);
	ejemplo.insertar(70);
	ejemplo.insertar(55);
	ejemplo.insertar(45);

	ejemplo.imprimir();

	ejemplo.atender();

	ejemplo.imprimir();
	ejemplo.atender();

	ejemplo.imprimir();

	return 0;
}
