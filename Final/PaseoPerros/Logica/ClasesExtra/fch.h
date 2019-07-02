#ifndef FCH_H
#define FCH_H

class fch{
	public:
		fch(int a, int m){anio=a; mes=m;}
		fch(){}
		~fch(){}
		bool menor(fch);
		int calTmp();
		int anio;
		int mes;
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
