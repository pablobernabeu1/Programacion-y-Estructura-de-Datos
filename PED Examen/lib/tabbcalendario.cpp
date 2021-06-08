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
TABBCalendario::Insertar(TCalendario &c) {
	bool aux = false;

	if (raiz==NULL){
		raiz = new TNodoABB();
		raiz->item=c;
		aux = true;
	} else if (c < raiz->item){
		aux = raiz->iz.Insertar(c);

	} else if (c > raiz->item){
		aux = raiz->de.Insertar(c);

	} 
	return aux;
}

bool
TABBCalendario::Borrar(TCalendario &c){
	TCalendario mayorIz;
	TNodoABB *aux;
	bool deleted=false;

	if(!raiz){
		deleted = false;
	}
	else{
		if(raiz->item == c){
			deleted = true;

			if(raiz->iz.EsVacio() && raiz->de.EsVacio()){
				delete raiz;
				raiz=NULL;
			}
			else{
				if(!raiz->iz.EsVacio() && !raiz->de.EsVacio()){
					mayorIz = raiz->iz.BuscarMayor();
					raiz->item = mayorIz;
					raiz->iz.Borrar(mayorIz);
				}
				else{
					aux = raiz;

					if(raiz->iz.EsVacio()){
						raiz = raiz->de.raiz;
						aux->de.raiz = NULL;
					}
					else{
						raiz = raiz->iz.raiz;
						aux->iz.raiz = NULL;
					}

					delete aux;
				}
			}
		}
		else{
			if(c>raiz->item){
				deleted = raiz->de.Borrar(c);
			}
			else{		
				deleted = raiz->iz.Borrar(c);
			}
		}
	}

	return deleted;

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
	if(!EsVacio()){
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
TABBCalendario::Nodos() const{
	int n = 0;

	if (raiz!=NULL){
		if (raiz->iz.raiz==NULL && raiz->de.raiz==NULL){
			n = 1;
		} 
		else{
			n = 1+raiz->iz.Nodos() + raiz->de.Nodos();
		}
	}
	return n;
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
TABBCalendario::operator+(TABBCalendario &tabb){
	TABBCalendario tabbAux(*this);
	TVectorCalendario vc = tabb.Inorden();

	for(int i=1; i<=vc.Tamano(); i++){
		tabbAux.Insertar(vc[i]);
	}

	return tabbAux;
}

TABBCalendario 
TABBCalendario::operator-(TABBCalendario &tabb){
	TABBCalendario arbol;
	TVectorCalendario vector = Inorden();

	for (int i=1;i<=vector.Tamano(); i++){
		if (!tabb.Buscar(vector[i])){
			arbol.Insertar(vector[i]);
		}
	}
	return arbol;
}

// Métodos auxiliares

void 
TABBCalendario::InordenAux(TVectorCalendario &vc, int &pos) const{
	if(raiz!=NULL){
		raiz->iz.InordenAux(vc, pos);
		vc[pos]=Raiz();
		pos++;
		raiz->de.InordenAux(vc,pos);
	}
}

void 
TABBCalendario::PreordenAux(TVectorCalendario &vc, int &pos) const{
	if (raiz!=NULL){
		vc[pos]=Raiz();
		pos++;
		raiz->iz.PreordenAux(vc,pos);
		raiz->de.PreordenAux(vc,pos);
	}
}

void 
TABBCalendario::PostordenAux(TVectorCalendario &vc, int &pos) const{
	if (raiz!=NULL){
		raiz->iz.PostordenAux(vc,pos);
		raiz->de.PostordenAux(vc,pos);
		vc[pos]=Raiz();
		pos++;
	}
}

TCalendario
TABBCalendario::BuscarMayor() const {
	TCalendario aux;

	if(raiz){
		if(!raiz->de.raiz){
			aux = raiz->item;
		}
		else{
			aux = raiz->de.BuscarMayor();
		}
	}

	return aux;
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




//<------------------------------------------------------------------------------------------>

TListaCalendario
TABBCalendario::camino(TABBCalendario &tabb, TCalendario &cal, TListaCalendario &l){
	/*
	if (raiz->item==cal || raiz==NULL){
		//cout<<raiz->item<<endl;
		l.Insertar(cal);
		//cout<<l<<endl;
		return l;
	} 
	else if (cal < raiz->item){
		l.Insertar(raiz->item);
		raiz->iz.camino(*this, cal, l);

	} 
	else if (cal > raiz->item){
		l.Insertar(raiz->item);
		//cout<<l<<endl;
		raiz->de.camino(*this, cal, l);
	} 
	*/

	if(raiz->item==cal){

	}

	return l;
}

void
TABBCalendario::camino2(TVectorCalendario &vc, TCalendario &cal, int n){

	if(raiz->item<cal){
		vc.Redimensionar(n+1);
		vc[n+1] = Raiz();
		n++;

		raiz->de.camino2(vc,cal,n);
	}
	else if(raiz->item==cal){
		vc.Redimensionar(n+1);
		vc[n+1] = Raiz();
	}
	
	else {
		vc.Redimensionar(n+1);
		vc[n+1] = Raiz();
		n++;

		raiz->iz.camino2(vc,cal,n);
	}

}


TVectorCalendario
TABBCalendario::ABBCamino(TListaCalendario &l){
	TVectorCalendario vc;

	if(l.EsVacia()){
		return vc;
	}
	else{
		for(int i=0; i<l.Longitud(); i++){
			TCalendario cal = l.Obtener(l.Primera());

			if(!Buscar(cal)){
				Insertar(cal);

				/*
				TListaCalendario lista;
				
				camino(*this, cal, lista);

				cout<<lista<<endl;
				*/

				camino2(vc, cal, 0);

			}

			l.Borrar(cal);

		}
	}

	return vc;
}