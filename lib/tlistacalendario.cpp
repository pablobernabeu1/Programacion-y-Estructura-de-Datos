#include "tlistacalendario.h"

TNodoCalendario::TNodoCalendario(): c(){
  this->siguiente=NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &nc): c(nc.c){
  this->siguiente=NULL;
}

TNodoCalendario::~TNodoCalendario(){
  if(this->siguiente==NULL){
    c.~TCalendario();
  }
  else{
    this->siguiente=NULL;
    c.~TCalendario();
  }
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
  this->pos = NULL;
}

TListaPos::TListaPos(const TListaPos &lp){
  this->pos = lp.pos;
}

TListaPos::~TListaPos(){
  (*this->pos).~TNodoCalendario();
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
} //Seguramente hay que corregirlo

TListaCalendario::~TListaCalendario(){
  TListaPos p, q;
  q = Primera();

  while(!q.EsVacia()){
    p=q;
    q = q.Siguiente();
    delete p.pos;
  }

  this->primero = NULL;

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

  for(int i=0; i<Longitud(); i++){ // cambiar por un while
    //lcSuma
  }


  return lcSuma;
}

bool
TListaCalendario::Insertar(const TCalendario &cal){

  TListaPos lp;
  TListaPos ant;
  TNodoCalendario *nc = new TNodoCalendario();

  lp=Primera();
  ant = Primera();

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
TListaCalendario::Buscar(const TCalendario &cal){

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
TListaCalendario::Longitud(){
  int longitud=0;
  TListaPos lp ;
  lp = Primera();

  while(!lp.EsVacia()){
    lp = lp.Siguiente();
    longitud++;
  };

  return longitud;
}

TListaPos
TListaCalendario::Primera() const {
  TListaPos lp;
  lp.pos = primero;
  return lp;
}
