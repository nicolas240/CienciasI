#include <iostream>
#include <fstream>
#include "lista.h"

using namespace std;

struct ingrediente{
	string nombre, medida;
	int cantidad;
	
};

template <class T>
struct postre
{
	lista <T> ingredientes;
	string procedimiento, tipo;
	int tiempo;
};


int main(int argc, char** argv) {
	char procedimiento[300];
	
	lista <postre <ingrediente> > Postres;
	lista <ingrediente> ingredientes1,ingredientes2, ingredientes3;
		
	ingredientes1.insertar_nodo(1,ingrediente{"huevo","unidades",4});
	ingredientes1.insertar_nodo(2,ingrediente{"azucar","taza",1/2});
	ingredientes1.insertar_nodo(3,ingrediente{"harina","taza",1/2});
	ingredientes1.insertar_nodo(4,ingrediente{"polvo de hornear","cucharada",1/2});

	ingredientes2.insertar_nodo(1,ingrediente{"Arros blanco","taza",1});
	ingredientes2.insertar_nodo(2,ingrediente{"canela","astillas",4});
	ingredientes2.insertar_nodo(3,ingrediente{"leche","tazas",4});
	ingredientes2.insertar_nodo(4,ingrediente{"mantequilla","cucharadas",2});
	ingredientes2.insertar_nodo(5,ingrediente{"azucar","tazas",1/2});		
	ingredientes2.insertar_nodo(6,ingrediente{"leche condensada","onzas",12});
		
	ingredientes3.insertar_nodo(1,ingrediente{"pan","tamaño(pulgadas)",9});
	ingredientes3.insertar_nodo(2,ingrediente{"harina de trigo","taza",1/2});
	ingredientes3.insertar_nodo(3,ingrediente{"mantequilla sin sal","barras",2});
	ingredientes3.insertar_nodo(4,ingrediente{"polvo de hornear","cucharada",1});
	ingredientes3.insertar_nodo(5,ingrediente{"azucar","taza",1});
	ingredientes3.insertar_nodo(6,ingrediente{"huevos","unidades",5});
	ingredientes3.insertar_nodo(7,ingrediente{"leche,ron o aguardinete","cucharada",1});
			
	ifstream fe1("BrazoDeReina.txt");
	fe1.getline(procedimiento,300);
	
	Postres.insertar_nodo(1,postre<ingrediente>{ingredientes1,procedimiento,"bizcocho con crema batida",72});
	
	ifstream fe2("ArrozConLeche.txt");
	fe2.getline(procedimiento,300);
	
	Postres.insertar_nodo(2,postre<ingrediente>{ingredientes2,procedimiento,"postre de arroz",165});

	ifstream fe3("Mantecada.txt");
	fe3.getline(procedimiento,300);
	
	Postres.insertar_nodo(2,postre<ingrediente>{ingredientes3,procedimiento,"postre de maiz y mantequilla",72});	
	
	cout<<"Brazo de reina:"<<endl;
	cout<<"Posedimiento:"<<endl;
	cout<<Postres.buscar(1).procedimiento<<endl<<endl;
	cout<<"Ingredientes: "<<endl;
	for(int i=1;i<=4;i++){
		ingrediente imprime = Postres.buscar(1).ingredientes.buscar(i);
		cout<<imprime.nombre<<" "<<imprime.medida<<" "<<imprime.cantidad<<endl;
	}
	cout<<"Arroz con leche:"<<endl;
	cout<<"Posedimiento:"<<endl;
	cout<<Postres.buscar(2).procedimiento<<endl<<endl;
	cout<<"Ingredientes: "<<endl;
	for(int i=1;i<=6;i++){
		ingrediente imprime = Postres.buscar(2).ingredientes.buscar(i);
		cout<<imprime.nombre<<" "<<imprime.medida<<" "<<imprime.cantidad<<endl;
	}
	
	cout<<"Mantecada:"<<endl;
	cout<<"Posedimiento:"<<endl;
	cout<<Postres.buscar(3).procedimiento<<endl<<endl;
	cout<<"Ingredientes: "<<endl;
	for(int i=1;i<=7;i++){
		ingrediente imprime = Postres.buscar(3).ingredientes.buscar(i);
		cout<<imprime.nombre<<" "<<imprime.medida<<" "<<imprime.cantidad<<endl;
	}
	return 0;
}
