#include "tavlcalendario.h"


// Métodos para TNodoAVL


TNodoAVL::TNodoAVL(): iz(), de(), item(){
	fe=0;
}

TNodoAVL::TNodoAVL(const TNodoAVL &tn): iz(tn.iz), de(tn.de), item(tn.item){
	fe = tn.fe;
} 

TNodoAVL::~TNodoAVL(){
	fe=0;
}

TNodoAVL & 
TNodoAVL::operator=(const TNodoAVL &tn){
	if(this!=&tn){
		(*this).~TNodoAVL();
		de = tn.de;
		iz = tn.iz;
		item = tn.item;
	}

	return *this;
}


// Métodos para TAVLCalendario


TAVLCalendario::TAVLCalendario(){
	raiz=NULL;
}

TAVLCalendario::TAVLCalendario(const TAVLCalendario &tavl){
	if(this!=tavl && tavl.raiz!=NULL){
		copiar(tavl);
	}
	else{
		raiz=NULL;
	}
}