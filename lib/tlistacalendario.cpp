#include "tlistacalendario.h"

TNodoCalendario::TNodoCalendario(): c(){
  this->siguiente=NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &nc): c(nc.c){
  this->siguiente=NULL;
}

TNodoCalendario::~TNodoCalendario(){
  this->siguiente=NULL;
}

TNodoCalendario&
TNodoCalendario::operator=(const TNodoCalendario &nc){
  //if(*this != &nc){
    (*this).~TNodoCalendario();

    this->c = nc.c;
    this->siguiente = nc.siguiente;
  //}

  return *this;
}

bool
TNodoCalendario::operator==(const TNodoCalendario &nc){
  if(this->c==nc.c){
    return true;
  }
  return false;
}

bool
TNodoCalendario::operator!=(const TNodoCalendario &nc){
  if(this->c==nc.c){
    return false;
  }
  return true;
}



// Metodos de TListaPos




TListaPos::TListaPos() {
  this->pos = NULL;
}

TListaPos::TListaPos(TListaPos &lp){
  pos = lp.pos;
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
TListaPos::EsVacia(){
  return this->pos ==NULL;
}



// Metodos de tlistacalendario



TListaCalendario::TListaCalendario(){
  this->primero=NULL;
}

TListaCalendario::TListaCalendario(TListaCalendario &lc){
  this->primero=lc.primero;
}

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

TListaPos
TListaCalendario::Primera(){
  TListaPos p;
  p.pos = primero;
  return p;
}
