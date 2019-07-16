#ifndef FCH_H
#define FCH_H

class fch{
	public:
		fch(int a, int m,int d){anio=a; mes=m; dia=d;}
		fch(){}
		~fch(){}
		bool menor(fch);
		int calEdad();
		int anio;
		int mes;
		int dia;
};

bool fch::menor(fch com){
	if(com.anio> this->anio&& com.mes> this->mes)
		return true;
	else
		return false;
}

int fch::calEdad(){
	int edad=2019-anio;
	if(dia==17 and mes==7)
		edad++;
	return edad;
}

#endif
