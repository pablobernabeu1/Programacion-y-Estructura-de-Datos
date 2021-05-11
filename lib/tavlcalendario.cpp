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
TAVLCalendario::operator==(const TAVLCalendario& avlc) const {
	TAVLCalendario aux(avlc);
	if(Inorden() == aux.Inorden()){
			return true;
	}
	else{
		return false;
	}
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
TAVLCalendario::Insertar(const TCalendario& c) {
	bool crece=false;
	bool creceiz=false;
	bool crecede=false;
	if(!Buscar(c)){
		if(EsVacio()){
			TNodoAVL* aux=new TNodoAVL;
			raiz=aux;
			raiz->item=c;
			crece = true;
		}
		else{
			if(Raiz()>c){
				creceiz= raiz->iz.Insertar(c);
				crece=creceiz;
			}
			else{
				if(Raiz()<c){
					crecede= raiz->de.Insertar(c);
					crece=crecede;
				}
			}

			if(crece){
				if((creceiz && raiz->fe==1)||(crecede && raiz->fe==-1)){
					raiz->fe=0;
					return false;
				}else if(creceiz && raiz->fe==0){
					raiz->fe=-1;
				}else if(crecede && raiz->fe==0){
					raiz->fe=1;
				}
				else if(creceiz && raiz->fe==-1){
					crece=(*this).EquilibrarIzquierda();
				}
				else if(crecede && raiz->fe==1){
					crece=EquilibrarDerecha();
				}
			}

		}
		return crece;
	}
	else{
		return false;;
	}
}

bool 
TAVLCalendario::Borrar(const TCalendario &){
	return false;
}

bool 
TAVLCalendario::Buscar(const TCalendario& c) {
	if(!EsVacio()){
			if(Raiz()==c){
				return true;
			}
			else{
				if(raiz->de.Buscar(c) || raiz->iz.Buscar(c)){
					return true;
				}
				else{
					return false;
				}
			}
		}
		else{
			return false;
		}

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

	return max(raiz->de.Altura(), raiz->iz.Altura())+1;
	
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
	if(!EsVacio()){
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
	if(!EsVacio()){
		raiz->iz.InordenAux(vc, pos);
		vc[pos]=Raiz();
		pos++;
		raiz->de.InordenAux(vc,pos);
	}
}

void 
TAVLCalendario::PreordenAux(TVectorCalendario &vc, int &pos) const{
	if (!EsVacio()){
		vc[pos]=Raiz();
		pos++;
		raiz->iz.PreordenAux(vc,pos);
		raiz->de.PreordenAux(vc,pos);
	}
}

void 
TAVLCalendario::PostordenAux(TVectorCalendario &vc, int &pos) const{
	if (!EsVacio()){
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

		raiz->iz.copiar(tavl.raiz->iz);
		raiz->de.copiar(tavl.raiz->de);
	}
	else{
		raiz=NULL;
	}
}

bool 
TAVLCalendario::EquilibrarIzquierda() {
	TAVLCalendario J, K;
	TAVLCalendario* aux=this;
	int facAux=0;
	if(raiz->iz.raiz->fe==-1 ){ //Rotación II
		Mover(J, raiz->iz);
		Mover(raiz->iz, J.raiz->de);
		Mover(J.raiz->de,aux);
		J.raiz->fe=J.raiz->de.Altura()-J.raiz->iz.Altura();
		J.raiz->de.raiz->fe=J.raiz->de.Altura()-J.raiz->iz.Altura();
		Mover(*this, J);
	}
	else{//Rotación ID
		Mover(J, raiz->iz);
		Mover(K, J.raiz->de);
		facAux=K.raiz->fe;
		Mover(raiz->iz, K.raiz->de);
		Mover(J.raiz->de, K.raiz->iz);
		Mover(K.raiz->iz, J);
		Mover(K.raiz->de, aux);
		K.raiz->fe=K.raiz->de.Altura()-K.raiz->iz.Altura();
		switch(facAux){
		case -1:
			K.raiz->iz.raiz->fe=0;
			K.raiz->de.raiz->fe=1;
			break;
		case 1:
			K.raiz->iz.raiz->fe=-1;
			K.raiz->de.raiz->fe=0;
			break;
		case 0:
			K.raiz->iz.raiz->fe=0;
			K.raiz->de.raiz->fe=0;
			break;
		}
		Mover(*this, K);
	}
	return false;
}

bool 
TAVLCalendario::EquilibrarDerecha() {
	TAVLCalendario J, K;
	TAVLCalendario* aux=this;
	int facAux=0;
	if(raiz->de.raiz->fe==1 || raiz->de.raiz->fe==0){ //Rotación DD
		Mover(J, raiz->de);
		Mover(raiz->de, J.raiz->iz);
		Mover(J.raiz->iz,aux);
		J.raiz->fe=J.raiz->de.Altura()-J.raiz->iz.Altura();
		J.raiz->iz.raiz->fe=J.raiz->iz.raiz->de.Altura()-J.raiz->iz.raiz->iz.Altura();
		Mover(*this, J);
	}
	else{//Rotación DI
		Mover(J, raiz->de);
		Mover(K, J.raiz->iz);
		facAux=K.raiz->fe;
		Mover(raiz->de, K.raiz->iz);
		Mover(J.raiz->iz, K.raiz->de);
		Mover(K.raiz->de, J);
		Mover(K.raiz->iz, aux);
		K.raiz->fe=K.raiz->de.Altura()-K.raiz->iz.Altura();
		switch(facAux){
		case 1:
			K.raiz->de.raiz->fe=1;
			K.raiz->iz.raiz->fe=0;
			break;
		case -1:
			K.raiz->de.raiz->fe=0;
			K.raiz->iz.raiz->fe=-1;
			break;
		case 0:
			K.raiz->de.raiz->fe=0;
			K.raiz->iz.raiz->fe=0;
			break;
		}
		Mover(*this, K);
	}
	return false;
}

void 
TAVLCalendario::reequilibrarFE() {
	int aux;
	if(raiz->iz.EsVacio()&& raiz->de.EsVacio()){
		raiz->fe=0;
	}
	else if(!raiz->iz.EsVacio()&& !raiz->de.EsVacio()){
		aux=raiz->de.Altura()-raiz->iz.Altura();
	}
	else if(!raiz->iz.EsVacio()){
		aux=0-raiz->iz.Altura();
	}
	else if(!raiz->de.EsVacio()){
		aux=raiz->de.Altura();
	}

	if(aux==0 || aux==-1 || aux==1){
		raiz->fe=aux;
	}
	else{
		if(aux==-2){
			EquilibrarIzquierda();
		}
		else if(aux==2){
			EquilibrarDerecha();
		}
	}

}

void 
TAVLCalendario::Mover(TAVLCalendario& avlci,TAVLCalendario& avlcd) {
	avlci.~TAVLCalendario();
	avlci.raiz=avlcd.raiz;
	avlcd.raiz=NULL;
}

void 
TAVLCalendario::Mover(TAVLCalendario& avlc, TAVLCalendario*& avlcp) {
	avlc.~TAVLCalendario();
	avlc.raiz=avlcp->raiz;
	avlcp->raiz=NULL;
}

void 
TAVLCalendario::Mover(TAVLCalendario*& avlcp, TAVLCalendario& avlc) {
	avlcp->raiz=avlc.raiz;
}

void 
TAVLCalendario::Mover(TAVLCalendario*& avlcpi, TAVLCalendario*& avlcpd) {
	avlcpi->raiz=avlcpd->raiz;
	avlcpd->raiz=NULL;
}