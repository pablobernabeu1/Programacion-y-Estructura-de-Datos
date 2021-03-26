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

  for(int i=0; i<this->tamano; i++){
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
  if(!this->comprobarFechaCorrecta(d, m, a)){

  }
  else{

    TCalendario cal(d, m, a, NULL);
    TVectorCalendario vc;
    int tamVc=0;

    for(int i=0; i<this->tamano; i++){
      if(this->c[i]>cal || this->c[i]==cal){
        vc.tamano++;
      }
    }

    for(int i=0; i<this->tamano; i++){
      if(this->c[i]>cal || this->c[i]==cal){
        vc.c[tamVc] = this->c[i];
        tamVc++;
      }
    }

  }
}

ostream & operator<<(ostream &os, const TVectorCalendario &vc){

  if(vc.tamano == 0){
    os<<"[]";
  }
  else{
    os<<"[";
    for(int i=0; i<vc.tamano; i++){
      if(i==vc.tamano-1){
        os<<"("<<(i+1)<<") "<<vc[i]<<"]";
      }
      else{
        os<<"("<<(i+1)<<") "<<vc[i]<<", ";
      }
    }
  }

  return os;
}

bool
TVectorCalendario::comprobarFechaCorrecta(int dia, int mes, int anyo){   // Función que comprueba el número correcto de días y los años bisiestos
  bool check=false;

  if(dia>=1 && dia<=31 && mes>=1 && mes<=12 && anyo>=1900){
    if(!(dia==31 && (mes==2 || mes==4 || mes==6 || mes==9 || mes==11))){
      int diaFebrero;

      if((anyo%4==0) && ((anyo%100!=0) || (anyo%400==0))){  // En este caso el año es bisiesto
        diaFebrero = 29;
      }
      else{   // En este caso el año no es bisiesto
        diaFebrero = 28;
      }

      if(!(mes==2 && dia>diaFebrero)){
        check=true;
      }

    }
  }
  return check;
}
