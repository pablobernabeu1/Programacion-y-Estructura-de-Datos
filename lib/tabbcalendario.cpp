#include "tabbcalendario.h"


// Métodos para TNodoABB


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



// Métodos para TABBCalendario



TABBCalendario::TABBCalendario(){
	raiz=NULL;
}

TABBCalendario::TABBCalendario(const TABBCalendario &tabb){
	raiz=NULL;
	copiar(tabb);
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

int 
TABBCalendario::Altura(){
	
	if(!EsVacio()){
		return max(raiz->iz.Altura(), raiz->de.Altura()) + 1;
	}

	return 0;
}

int 
TABBCalendario::Nodos(){
	if(!EsVacio()){
		return (raiz->de.Nodos() + raiz->iz.Nodos()) + 1; 
	}

	return 0;
}

int 
TABBCalendario::NodosHoja(){
	if(EsVacio()){
		return 0;
	}
	else{
		if(raiz->de.EsVacio() && raiz->iz.EsVacio()){
			return 1;
		}
		else{
			return raiz->iz.NodosHoja() + raiz->de.NodosHoja();
		}
	}
}

TVectorCalendario 
TABBCalendario::Inorden(){
	TVectorCalendario vc(Nodos());
	int pos=1;
	//InordenAux(vc, pos);

	return vc;
}

TVectorCalendario 
TABBCalendario::Preorden(){
	TVectorCalendario vc(Nodos());
	int pos=1;
	//PreordenAux(vc, pos);

	return vc;
}

TVectorCalendario 
TABBCalendario::Postorden(){
	TVectorCalendario vc(Nodos());
	int pos=1;
	//PostordenAux(vc, pos);

	return vc;
}

TVectorCalendario 
TABBCalendario::Niveles(){
	TVectorCalendario vc(Nodos());
	TABBCalendario temp(*this);
	TABBCalendario* aux;
	queue<TABBCalendario*> cola;


	return vc;
}



// Métodos auxiliares

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