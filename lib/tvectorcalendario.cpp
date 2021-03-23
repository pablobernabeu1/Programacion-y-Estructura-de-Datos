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

TVectorCalendario::TVectorCalendario(const TVectorCalendario &vc):error() {
  this->tamano = vc.tamano;
  this->c = new TCalendario[vc.tamano];

  for(int i=0; i<=this->tamano; i++){
    this->c[i] = vc.c[i];
  }

}

TVectorCalendario::~TVectorCalendario(){
  if(this->c!=NULL){
    delete[] this->c;
  }
  this->tamano = 0;
}

TVectorCalendario&
TVectorCalendario::operator=(const TVectorCalendario &vc) {

  if(this != &vc){
    (*this).~TVectorCalendario();

    this->tamano = vc.tamano;
    this->c = new TCalendario[this->tamano];

    if(this->c = NULL){
      this->tamano = 0;
    }

    for(int i=0; i<=this->tamano; i++){
      this->c[i] = vc.c[i];
    }

    this->error = vc.error;

  }

  return *this;
}

bool
TVectorCalendario::operator==(const TVectorCalendario &vc){

  if(this->tamano == vc.tamano){
    for(int i=0; i<=this->tamano; i++){
      if(this->c[i] != vc.c[i]){
        return false;
      }
    }
    return true;
  }
  return false;
}

bool
TVectorCalendario::operator!=(const TVectorCalendario &vc){

  if(this->tamano == vc.tamano){
    for(int i=0; i<=this->tamano; i++){
      if(this->c[i] != vc.c[i]){
        return true;
      }
    }
    return false;
  }
  return true;

}

TCalendario&
TVectorCalendario::operator[](int n){

  for(int i=1; i<=this->tamano; i++){
    if(n==i){
      return this->c[n-1];
    }
  }

  return error;

}

TCalendario
TVectorCalendario::operator[](int n) const{

  for(int i=1; i<this->tamano; i++){
    if(n==i){
      return this->c[n-1];
    }
  }

  return error;
}

int
TVectorCalendario::Tamano(){
  return this->tamano;
}

int
TVectorCalendario::Ocupadas(){
  int cont=0;

  for(int i=0; i<=this->tamano; i++){
    if(this->c[i].EsVacio()==false){
      cont++;
    }
  }

  return cont;
}

bool
TVectorCalendario::ExisteCal(TCalendario &c){
  for(int i=0; i<=this->tamano; i++){
    if(this->c[i] == c){
      return true;
    }
  }
  return false;
}

void
TVectorCalendario::MostrarMensajes(int d, int m, int a){

}

ostream & operator<<(ostream &os, const TVectorCalendario &c){


  return os;
}
