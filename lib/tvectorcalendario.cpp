#include "tvectorcalendario.h"


TVectorCalendario::TVectorCalendario():error() {
  this->c = NULL;
  tamano = 0;
}

TVectorCalendario::TVectorCalendario(int tam):error() {
  if(tam>0){
    this->c = new TCalendario[tam];
    this->tamano = tam;
  }
  else{
    this->c = NULL;
    this->tamano = 0;
  }
}

TVectorCalendario::TVectorCalendario(const TVectorCalendario &vc) {
  this->tamano = vc.tamano;

  this->c = new TCalendario[vc.tamano];
  this->c = vc.c;

}

TVectorCalendario::~TVectorCalendario(){
  if(this->c!=NULL){
    delete[] this->c;
    this->tamano = 0;
  }
}

TVectorCalendario&
TVectorCalendario::operator=(const TVectorCalendario &vc){

  if(this->c == NULL){

  }

  return *this;
}
