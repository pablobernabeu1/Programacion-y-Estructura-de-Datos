#include "tlistacalendario.h"

TNodoCalendario::TNodoCalendario(): c(){
  this->siguiente=NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &nc): c(nc.c){
  this->siguiente=NULL;
}

TNodoCalendario::~TNodoCalendario(){
  this->siguiente=NULL;
  c.~TCalendario();
}

TNodoCalendario&
TNodoCalendario::operator=(const TNodoCalendario &nc){
  if(this != &nc){
    (*this).~TNodoCalendario();

    this->c = nc.c;
    this->siguiente = nc.siguiente;
  }

  return *this;
}




// Metodos de TListaPos




TListaPos::TListaPos() {
  pos = NULL;
}

TListaPos::TListaPos(const TListaPos &lp){
  pos = lp.pos;
}

TListaPos::~TListaPos(){
  if(pos!=NULL){
		pos=NULL;
	}
}

TListaPos&
TListaPos::operator=(const TListaPos &lp){

  if(this->pos!=lp.pos){
    (*this).~TListaPos();
    this->pos = lp.pos;
  }

  return *this;
}

bool
TListaPos::operator==(const TListaPos &lp){
  if(this->pos==lp.pos){
    return true;
  }
  return false;
}

bool
TListaPos::operator!=(const TListaPos &lp){
  if(this->pos==lp.pos){
    return false;
  }
  return true;
}

TListaPos
TListaPos::Siguiente(){
  if(this->pos->siguiente==NULL){
    TListaPos lp;
    return lp;
  }
  else{
    this->pos=this->pos->siguiente;
    return *this;
  }
}

bool
TListaPos::EsVacia() const {
  return this->pos ==NULL;
}



// Metodos de tlistacalendario



TListaCalendario::TListaCalendario(){
  this->primero=NULL;
}

TListaCalendario::TListaCalendario(const TListaCalendario &lc){
  this->primero=lc.primero;
}

TListaCalendario::~TListaCalendario(){

  TNodoCalendario *nc = NULL;

  while(!EsVacia()){
    nc = this->primero;
    this->primero = this->primero->siguiente;

    if(nc!=NULL){
      delete nc;
      nc = NULL;
    }
  }

}

TListaCalendario&
TListaCalendario::operator=(const TListaCalendario &lc){

  if(this!=&lc){
    (*this).~TListaCalendario();
    this->primero = NULL;
  }

  return *this;
}

bool
TListaCalendario::operator==(const TListaCalendario &lc){

  TNodoCalendario *nc1 = this->primero;
  TNodoCalendario *nc2 = lc.primero;

  for(int i=0; i<Longitud(); i++){
    if(nc1!=nc2){
      return false;
    }
    nc1 = nc1->siguiente;
    nc2 = nc2->siguiente;
  }

  return true;
}

TListaCalendario
TListaCalendario::operator+(const TListaCalendario &lc){

  TListaCalendario lcSuma;
  TListaPos lp(Primera());
  TListaPos lp2(lc.Primera());

  for(int i=0; i<Longitud(); i++){
    lcSuma.Insertar(lp.pos->c);
    lp = lp.Siguiente();
  }
  for(int i=0; i<lc.Longitud(); i++){
    lcSuma.Insertar(lp2.pos->c);
    lp2 = lp2.Siguiente();
  }

  return lcSuma;
}

TListaCalendario
TListaCalendario::operator-(const TListaCalendario &lc){

  TListaCalendario lcSuma(*this);
  TListaPos lp;

  while(!lp.EsVacia()){
    lcSuma.Borrar(Obtener(lp));
    lp = lp.Siguiente();
  }

  return lcSuma;
}

bool TListaCalendario::Insertar(const TCalendario& c) {
	TListaPos lp;
	TListaPos ant;
	TNodoCalendario* aux = new TNodoCalendario();
	lp=Primera();
	ant=Primera();

	if(lp.EsVacia()){
    //cout<<"Hola"<<endl;
		lp.pos=new TNodoCalendario();
		lp.pos->c=c;
		primero=lp.pos;
		return true;
	}

	if(Buscar(c)){
		return false;
	}
	else{
    //cout<<"Adios"<<endl;
		while(!lp.EsVacia()){
			if(lp.pos->c>c){
				if(lp==Primera()){
          cout<<"FF"<<endl;
					aux->c=c;
					aux->siguiente=lp.pos;
					primero=aux;
					return true;
				}
			}
			else{
        cout<<"Estoy aqi"<<endl;
				if(lp.Siguiente().EsVacia()){
          //cout<<"Estoy aqui2"<<endl;
					aux->c=c;
					aux->siguiente=lp.Siguiente().pos;
					lp.pos->siguiente=aux;
					return true;
				}
				else if(lp.Siguiente().pos->c>c){
					aux->c=c;
					aux->siguiente=lp.pos->siguiente;
					ant.pos->siguiente=aux;
					return true;
				}
			}
			lp=lp.Siguiente();
		}
	}
	return true;
}

bool
TListaCalendario::Borrar(const TCalendario &cal){
  TListaPos lp;
  TListaPos ant;
  TNodoCalendario *nc = new TNodoCalendario();
  TListaCalendario lc(*this);

  if(!lp.EsVacia() && Buscar(cal)){
    for(int i=0; i<Longitud(); i++){
      if(lp.pos->c==cal){
        if(i==0){
          nc = this->primero;
          this->primero = lp.Siguiente().pos;
        }
        else{
          nc = lp.Siguiente().pos;
          ant.pos->siguiente = nc;
        }
        return true;
      }
      ant = lp;
      lp = lp.Siguiente();
    }
  }
  return false;

}

bool TListaCalendario::EsVacia() {
	if(primero==NULL){
		return true;
	}
	return false;
}

TCalendario
TListaCalendario::Obtener(const TListaPos &lp) const {

  if(!lp.EsVacia()){
    return lp.pos->c;
  }
  TCalendario cal;

  return cal;
}

bool
TListaCalendario::Buscar(const TCalendario &cal) const {

  TListaPos lp;
  TListaCalendario lc(*this);

  lp.pos = lc.primero;
  while(!lp.EsVacia()){
    if(lp.pos->c==cal){
      return true;
    }
    lp = lp.Siguiente();
  }

  return false;
}

int
TListaCalendario::Longitud() const {
  int longitud=0;
  TListaPos lp ;
  lp = Primera();

  while(!lp.EsVacia()){
    lp = lp.Siguiente();
    longitud++;
  };

  return longitud;
}

TListaPos TListaCalendario::Primera() const {
	TListaPos lp;
	lp.pos=primero;
	return lp;
}

TListaPos TListaCalendario::Ultima() const{
	TListaPos lp;
	lp=Primera();
	for(int i=1;i<Longitud();i++){//Empiezas en la primera posicion por lo que i se inicializa a 1
		lp=lp.Siguiente();
	}
	return lp;
}

ostream & operator<<(ostream &o,const TListaCalendario &lc){
	TListaPos lp;
	lp=lc.Primera();
	if(lp.EsVacia()){
		o<<"<>";
	}
	else{
		o<<"<";
		for(int i=0;i<lc.Longitud();i++){
			if(i==0){
				o<< lc.Obtener(lp);
			}
			else{
				o<< " " << lc.Obtener(lp);
			}
			lp=lp.Siguiente();
		}
		o<<">";
	}
	return o;
}
