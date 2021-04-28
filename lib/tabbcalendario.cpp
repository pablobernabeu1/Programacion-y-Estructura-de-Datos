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
	if(tabb.raiz!=NULL && this!=&tabb){
		copiar(tabb);
	}
	else{
		raiz=NULL;
	}
}


TABBCalendario::~TABBCalendario(){
	if(raiz!=NULL){
		delete raiz;
		raiz=NULL;
	}
}

TABBCalendario& 
TABBCalendario::operator=(const TABBCalendario &tabb){
	if(this!=&tabb && tabb.raiz!=NULL){
		(*this).~TABBCalendario();
		copiar(tabb);
	}
	return *this;
}

bool
TABBCalendario::operator==(const TABBCalendario &tabb){
	TABBCalendario tb(tabb);
	
	if(Inorden()==tb.Inorden()){
		return true;
	}
	
	return false;
}

bool
TABBCalendario::EsVacio() const {
	return (raiz==NULL);
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
TABBCalendario::Buscar(TCalendario &c) const {

	bool found=false;

	if(raiz==NULL){
		found = false;
	}
	else if(c<raiz->item){
		found = raiz->iz.Buscar(c);
	}
	else if(c>raiz->item){
		found = raiz->de.Buscar(c);
	}
	else found = true;

	return found;
}

TCalendario 
TABBCalendario::Raiz() const {
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
TABBCalendario::Nodos() const {
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
TABBCalendario::Inorden() const {
	TVectorCalendario vc(Nodos());
	int pos=1;
	InordenAux(vc, pos);

	return vc;
}

TVectorCalendario 
TABBCalendario::Preorden() const {
	TVectorCalendario vc(Nodos());
	int pos=1;
	PreordenAux(vc, pos);

	return vc;
}

TVectorCalendario 
TABBCalendario::Postorden() const {
	TVectorCalendario vc(Nodos());
	int pos=1;
	PostordenAux(vc, pos);

	return vc;
}

TVectorCalendario 
TABBCalendario::Niveles(){
	TVectorCalendario vc(Nodos());
	TABBCalendario temp(*this);
	TABBCalendario* aux;
	queue<TABBCalendario*> cola;

	int i=1;
	if(temp.EsVacio()){
		cola.push(&temp);
		vc[i]=aux->raiz->item;
		i++;
		cola.pop();
		if(!aux->raiz->iz.EsVacio()){
			cola.push(&(aux->raiz->iz));
		}
		if(!aux->raiz->de.EsVacio()){
			cola.push(&(aux->raiz->de));
		}
	}


	return vc;
}

ostream & operator<<(ostream &os, const TABBCalendario &tabb){
	os<<tabb.Inorden();

	return os;
}

TABBCalendario 
TABBCalendario::operator+(const TABBCalendario &tabb){
	TABBCalendario tabbAux(*this);
	TVectorCalendario vc = tabb.Inorden();

	for(int i=1; i<=vc.Tamano(); i++){
		tabbAux.Insertar(vc[i]);
	}

	return tabbAux;
}

TABBCalendario 
TABBCalendario::operator-(const TABBCalendario &tabb){
	TABBCalendario tabbAux(*this);
	TVectorCalendario vc = tabb.Inorden();

	for(int i=1; i<=vc.Tamano(); i++){
		if(!tabb.Buscar(vc[i])){
			tabbAux.Insertar(vc[i]);
		}
	}

	return tabbAux;
}

// Métodos auxiliares

void 
TABBCalendario::InordenAux(const TVectorCalendario &vc, int &p) const {
	if(raiz!=NULL){
		vc[p]=Raiz();
		raiz->iz.InordenAux(vc, p);
		p++;
		raiz->de.InordenAux(vc, p);
	}
}

void 
TABBCalendario::PreordenAux(const TVectorCalendario &vc, int &p) const {
	if(raiz!=NULL){
		vc[p]=Raiz();
		p++;
		raiz->iz.InordenAux(vc, p);
		raiz->de.InordenAux(vc, p);
	}
}

void 
TABBCalendario::PostordenAux(const TVectorCalendario &vc, int &p) const {
	if(raiz!=NULL){
		vc[p]=Raiz();
		raiz->iz.InordenAux(vc, p);
		raiz->de.InordenAux(vc, p);
		p++;
	}
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