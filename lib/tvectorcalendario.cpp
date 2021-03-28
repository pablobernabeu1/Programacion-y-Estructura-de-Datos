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

  if(this->c == NULL){
    this->tamano = 0;
  }

  for(int i=0; i<this->tamano; i++){
    this->c[i] = vc.c[i];
  }

  this->error = vc.error;

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

    if(this->c == NULL){
      this->tamano = 0;
    }

    for(int i=0; i<this->tamano; i++){
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

  for(int i=1; i<=this->tamano; i++){
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
    cout<<"[]";
  }
  else{

    TCalendario cal(d, m, a, NULL);
    int tam=0;

    for(int i=0; i<this->tamano; i++){
      if(this->c[i]==cal || this->c[i]>cal){
        tam++;
      }
    }

    cout<<"[";

    for(int i=0; i<this->tamano; i++){
      if(this->c[i]==cal || this->c[i]>cal){
        if(i==this->tamano-1){
          cout<<c[i];
        }
        else{
          cout<<c[i]<<", ";
        }

      }
    }

    cout<<"]"<<endl;

  }
}

bool
TVectorCalendario::Redimensionar(int n){
  if(n<=0 || n==this->tamano){
    return false;
  }
  else if(n>0 && n>this->tamano){
    TVectorCalendario vc2(n);

    for(int i=0; i<this->tamano; i++){
      vc2.c[i] = this->c[i];
    }
    for(int i=this->tamano+1; i<n; i++){
      TCalendario cal;
      vc2[i] = cal;
    }
    *this = vc2;

    return true;
  }
  else if(n>0 && n<this->tamano){
    TVectorCalendario vc2(n);

    for(int i=1; i<=n; i++){
      vc2[i] = this->c[i-1];
    }

    *this = vc2;

    return true;
  }

  return false;
}

ostream & operator<<(ostream &os, const TVectorCalendario &vc){

  if(vc.tamano == 0){
    os<<"[]";
  }
  else{
    os<<"[";
    for(int i=1; i<=vc.tamano; i++){
      if(i==vc.tamano){
        os<<"("<<i<<") "<<vc[i]<<"]";
      }
      else{
        os<<"("<<i <<") "<<vc[i]<<", ";
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
