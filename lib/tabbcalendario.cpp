#include "tabbcalendario.h"

TNodoABB::TNodoABB():item(), iz(), de(){
}

TNodoABB::TNodoABB(const TNodoABB &tn):item(tn.item), iz(tn.iz), de(tn.de){
}

TNodoABB::~TNodoABB(){
}

TNodoABB&
TNodoABB::operator=(const TNodoABB &tn){
	if(this!=&tn){
		(*this).~TNodoABB();
		item = tn.item;
		iz = tn.iz;
		de = tn.de;
	}

	return *this;
}

TABBCalendario::TABBCalendario(){
	raiz=NULL;
}

TABBCalendario::TABBCalendario(const TABBCalendario &tabb){
	raiz=NULL;
	copiar(tabb);
}



void 
TABBCalendario::copiar(const TABBCalendario &tabb){
	TNodoABB* tn = new TNodoABB();
	if(tabb.raiz!=NULL){
		tn->item=tabb.raiz->item;
		raiz=tn;
		raiz->de.copiar(tabb.raiz->de);
		raiz->iz.copiar(tabb.raiz->iz);
	}
}

TABBCalendario::~TABBCalendario(){
	if(raiz!=NULL){
		delete raiz;
		raiz=NULL;
	}
	else{
		raiz=NULL;
	}
}

TABBCalendario& 
TABBCalendario::operator=(const TABBCalendario &tabb){
	if(this!=&tabb){
		(*this).~TABBCalendario();
		copiar(tabb);
	}
	return *this;
}

bool
TABBCalendario::operator==(const TABBCalendario &tabb){
	TABBCalendario tb(tabb);
	/*
	if(Inorden()==tb.Inorden()){
		return true;
	}
	*/
	return false;
}

bool
TABBCalendario::EsVacio(){
	if(raiz!=NULL){
		return false;
	}
	return true;
}

bool 
TABBCalendario::Insertar(TCalendario &c){
	if(raiz==NULL){
		raiz = new TNodoABB();
		raiz->item=c;
		return true;
	}
	else if(c<raiz->item){
		return raiz->iz.Insertar(c);
	}
	else if(c>raiz->item){
		return raiz->de.Insertar(c);
	}

	return false;
}

bool
TABBCalendario::Borrar(TCalendario &c){
	return false;
}

bool 
TABBCalendario::Buscar(TCalendario &c){
	if(raiz==NULL){
		return false;
	}
	else if(c<raiz->item){
		return raiz->iz.Buscar(c);
	}
	else if(c>raiz->item){
		return raiz->de.Buscar(c);
	}
	else return true;

	return false;
}

TCalendario 
TABBCalendario::Raiz(){
	TCalendario c;
	if(EsVacio()){
		c=raiz->item;
	}
	return c;
}