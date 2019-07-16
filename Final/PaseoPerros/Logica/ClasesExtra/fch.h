#ifndef FCH_H
#define FCH_H

class fch{
	public:
		fch(int a, int m,int d){anio=a; mes=m; dia=d;}
		fch(){}
		~fch(){}
		bool menor(fch);
		int calTmp();
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

int fch::calTmp(){
	return 2019-anio;
}

#endif
