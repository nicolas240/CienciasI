#ifndef HORARIO_H
#define HORARIO_H

#include <string>

struct dia{
	//std::string nombre;
	int horaIn;
	int horaFn;
};

class horario{
	public:
		horario(){}
		~horario(){}
		bool disponible();
		dia semana[7];
};

#endif
