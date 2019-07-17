#ifndef DIREC_H
#define DIREC_H

class direc{//Se simula una bogota con 440 calles y 440 carreras
	public:
		direc(){
			area=0;
			cobCal=15;
			cobCarr=15;
		}
		direc(int cC,int cK){
			area=0;
			cobCal=cC;
			cobCarr=cK;
		}
		~direc(){}
		bool estaArea(direc d){
			if(d.calle>= calRes(calle,0) && d.calle<=calle+cobCal)
				if(d.carrera>=calRes(carrera,1) && d.carrera<= carrera+cobCarr)
					return true;
			return false;
		}
		int calle;
		int carrera;
		int numero;
	private:
		int calRes(int s, int c);
		int area;
		int cobCal;
		int cobCarr;
};

int direc::calRes(int s, int c){//c es calle =0, carera=1
	int result;
	if(c==0){
		if( (s-cobCal)<=0)
			return 0;
		else
			return (s-cobCal);
	}else{
		if( (s-cobCarr)<=0)
			return 0;
		else
			return (s-cobCarr);			
	}
}
#endif
