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
	if(this!=&tavl && tavl.raiz!=NULL){
		copiar(tavl);
	}
	else{
		raiz=NULL;
	}
}

TAVLCalendario::~TAVLCalendario(){
	if(raiz!=NULL){
		delete raiz;
		raiz = NULL;
	}
}

TAVLCalendario &
TAVLCalendario::operator=(const TAVLCalendario &tavl){
	if(this!=&tavl && tavl.raiz!=NULL){
		(*this).~TAVLCalendario();
		(*this).copiar(tavl);
	}

	return (*this);
}

bool
TAVLCalendario::operator==(const TAVLCalendario &tavl) const {
	TAVLCalendario tv(tavl);
	/*
	if(Inorden()==tv.Inorden()){
		return true;
	}
	*/
	return false;
}

bool 
TAVLCalendario::operator!=(const TAVLCalendario &tavl) const {
	return !(*this==tavl);
}

bool 
TAVLCalendario::EsVacio() const {
	return (raiz==NULL);
}

bool
TAVLCalendario::Insertar(TCalendario &c){
	bool inserted=false;

	if(raiz==NULL){
		raiz = new TNodoAVL();
		raiz->item = c;
		inserted=true;
	}
	else if(c>raiz->item){
		inserted = raiz->de.Insertar(c);
	}
	else if(c<raiz->item){
		inserted = raiz->iz.Insertar(c);
	}

	return inserted;
}

bool 
TAVLCalendario::Borrar(const TCalendario &){
	return false;
}

bool 
TAVLCalendario::Buscar(TCalendario &c) const {
	bool found=false;

	if(raiz==NULL){
		found=false;
	}
	else if(c>raiz->item){
		found = raiz->de.Buscar(c);
	}
	else if(c<raiz->item){
		found = raiz->iz.Buscar(c);
	}
	else{
		found=true;
	}

	return found;
}

TCalendario 
TAVLCalendario::Raiz() const{
	if(!EsVacio()){
		return raiz->item;
	}
	else{
		TCalendario aux;
		return aux;
	}
}

int 
TAVLCalendario::Altura() const {
	if(EsVacio()){
		return 0;
	}

	return max(raiz->de.Nodos(), raiz->iz.Nodos())+1;
	
}

int 
TAVLCalendario::Nodos() const {
	if(EsVacio()){
		return 0;
	}

	return raiz->de.Nodos() + raiz->iz.Nodos() + 1;
}

int 
TAVLCalendario::NodosHoja() const {
	if(EsVacio()){
		if(raiz->de.EsVacio() && raiz->iz.EsVacio()){
			return 1;
		}
		else{
			return raiz->iz.NodosHoja()+ raiz->de.NodosHoja();
		}
	}
	else{
		return 0;
	}
}

TVectorCalendario 
TAVLCalendario::Inorden() const {
	TVectorCalendario vc(Nodos());
	int pos=1;
	InordenAux(vc, pos);

	return vc;
}

TVectorCalendario 
TAVLCalendario::Preorden() const {
	TVectorCalendario vc(Nodos());
	int pos=1;
	PreordenAux(vc, pos);

	return vc;
}

TVectorCalendario 
TAVLCalendario::Postorden() const {
	TVectorCalendario vc(Nodos());
	int pos=1;
	PostordenAux(vc, pos);

	return vc;
}

ostream & operator<<(ostream &os, const TAVLCalendario &tavl){
	os<<tavl.Inorden();
	return os;
}


// Métodos auxiliares


void 
TAVLCalendario::InordenAux(TVectorCalendario &vc, int &pos) const{
	if(raiz!=NULL){
		raiz->iz.InordenAux(vc, pos);
		vc[pos]=Raiz();
		pos++;
		raiz->de.InordenAux(vc,pos);
	}
}

void 
TAVLCalendario::PreordenAux(TVectorCalendario &vc, int &pos) const{
	if (raiz!=NULL){
		vc[pos]=Raiz();
		pos++;
		raiz->iz.PreordenAux(vc,pos);
		raiz->de.PreordenAux(vc,pos);
	}
}

void 
TAVLCalendario::PostordenAux(TVectorCalendario &vc, int &pos) const{
	if (raiz!=NULL){
		raiz->iz.PostordenAux(vc,pos);
		raiz->de.PostordenAux(vc,pos);
		vc[pos]=Raiz();
		pos++;
	}
}


void
TAVLCalendario::copiar(const TAVLCalendario &tavl){
	if(tavl.raiz!=NULL){
		TNodoAVL *tn = new TNodoAVL();
		tn->item = tavl.raiz->item;
		raiz = tn;

		(raiz->iz).copiar(tavl.raiz->iz);
		(raiz->de).copiar(tavl.raiz->de);
	}
	else{
		raiz=NULL;
	}
}