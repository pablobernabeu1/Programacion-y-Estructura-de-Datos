#include "tcalendario.h"

TCalendario::TCalendario(){
    fechaPorDefecto(*this);
}

TCalendario::TCalendario(int dia, int mes, int anyo, char *mens){  // Comentario de comprobacion

    if(this->comprobarFechaCorrecta(dia, mes, anyo)){
        this->dia=dia;
        this->mes=mes;
        this->anyo=anyo;

        if(mens!=NULL){
            mensaje = new char[strlen(mens)+1];
            strcpy(mensaje, mens);
        }
        else{
            this->mensaje=NULL;
        }

    }
    else{
        fechaPorDefecto(*this);
    }

}

TCalendario::TCalendario(const TCalendario &c){
    Copia(c);
}

TCalendario::~TCalendario(){
    this->dia = 1;
    this->mes = 1;
    this->anyo = 1900;
    if(this->mensaje!=NULL){
      delete[] this->mensaje;
      this->mensaje = NULL;
    }
    else{
      this->mensaje=NULL;
    }
}

TCalendario&
TCalendario::operator=(const TCalendario &c){
    if(this != &c){
        (*this).~TCalendario();

        Copia(c);
    }
    return *this;
}

TCalendario
TCalendario::operator+(const int n){
    TCalendario temp(*this);
    //preguntar si está esto bien o simplemente hay que sumar días.

    if(n>=0){
      temp.dia=temp.dia+n;

      int diaMes;

      diaMes=30;
      if(temp.mes==1 || temp.mes==3 || temp.mes==5 || temp.mes==7 || temp.mes==8 || temp.mes==10 || temp.mes==12){
        diaMes=31;
      }
      if(temp.mes==2){
        if((temp.anyo%4==0) && ((temp.anyo%100!=0) || (temp.anyo%400==0))) {  // En este caso el año es bisiesto
          diaMes = 29;
        }
        else{   // En este caso el año no es bisiesto
          diaMes = 28;
        }
      }

      while(temp.dia>diaMes){
        temp.dia = temp.dia-diaMes;
        temp.mes++;

        while(temp.mes>12){
          temp.anyo++;
          temp.mes=1;
        }

        diaMes=30;
        if(temp.mes==1 || temp.mes==3 || temp.mes==5 || temp.mes==7 || temp.mes==8 || temp.mes==10 || temp.mes==12){
          diaMes=31;
        }

        if(temp.mes==2){
          if((temp.anyo%4==0) && ((temp.anyo%100!=0) || (temp.anyo%400==0))) {  // En este caso el año es bisiesto
            diaMes = 29;
          }
          else{   // En este caso el año no es bisiesto
            diaMes = 28;
          }
        }


      }

    }

    return temp;
}

TCalendario
TCalendario::operator-(const int n){
    TCalendario temp;

    temp.dia = this->dia - ((n%365)%31);
    temp.mes = this->mes - ((n%365)/31);
    temp.anyo = this->anyo - (n/365);

    if(this->Mensaje()!=NULL){
        temp.mensaje = new char[strlen(this->Mensaje())+1];
        strcpy(temp.mensaje, this->Mensaje());
    }
    else{
        temp.mensaje = NULL;
    }

    if(temp.dia>=1 && temp.dia<=31 && temp.mes>=1 && temp.mes<=12 && temp.anyo>=1900){
        return temp;
    }
    else{
        fechaPorDefecto(temp);
    }

    return temp;
}

TCalendario
TCalendario::operator++(int n){
  TCalendario temp(*this);

  switch (mes) {
    case 2:
      if(dia==29 && bisiesto(anyo)){
        mes++;
        dia=1;
      }
      else if(dia==28 && !bisiesto(anyo)){
        mes++;
        dia=1;
      }
      else{
        dia++;
      }
      break;

    case 4:
      if(dia==30){
        mes++;
        dia=1;
      }
      else{
        dia++;
      }
      break;

    case 6:
      if(dia==30){
        mes++;
        dia=1;
      }
      else{
        dia++;
      }
      break;

    case 9:
      if(dia==30){
        mes++;
        dia=1;
      }
      else{
        dia++;
      }
      break;

    case 11:
      if(dia==30){
        mes++;
        dia=1;
      }
      else{
        dia++;
      }
      break;
    default:
    if(dia==31){
      if(mes==12){
        dia=1;
        mes=1;
        anyo++;
      }
      else{
        mes++;
        dia=1;
      }
    }
    else{
      dia++;
    }
  }

  return temp;
}

TCalendario&
TCalendario::operator++(){

  switch (mes) {
    case 2:
      if(dia==29 && bisiesto(anyo)){
        mes++;
        dia=1;
      }
      else if(dia==28 && !bisiesto(anyo)){
        mes++;
        dia=1;
      }
      else{
        dia++;
      }
      break;

    case 4:
      if(dia==30){
        mes++;
        dia=1;
      }
      else{
        dia++;
      }
      break;

    case 6:
      if(dia==30){
        mes++;
        dia=1;
      }
      else{
        dia++;
      }
      break;

    case 9:
      if(dia==30){
        mes++;
        dia=1;
      }
      else{
        dia++;
      }
      break;

    case 11:
      if(dia==30){
        mes++;
        dia=1;
      }
      else{
        dia++;
      }
      break;
    default:
    if(dia==31){
      if(mes==12){
        dia=1;
        mes=1;
        anyo++;
      }
      else{
        mes++;
        dia=1;
      }
    }
    else{
      dia++;
    }
  }

  return *this;
}

TCalendario
TCalendario::operator--(int){
  TCalendario temp(*this);

  dia--;
  if(temp.dia>=1 && temp.dia<=31 && temp.mes>=1 && temp.mes<=12 && temp.anyo>=1900){
      return temp;
  }
  else{
      fechaPorDefecto(temp);
  }

  return temp;
}

TCalendario&
TCalendario::operator--(){
  dia--;

  if(this->dia>=1 && this->dia<=31 && this->mes>=1 && this->mes<=12 && this->anyo>=1900){
      return (*this);
  }
  else{
      fechaPorDefecto(*this);
  }

  return *this;
}

bool
TCalendario::ModFecha(int d, int m, int a){

    if(this->comprobarFechaCorrecta(d, m, a)){
      this->dia = d;
      this->mes = m;
      this->anyo = a;

      return true;
    }
    return false;
}

bool
TCalendario::ModMensaje(char *mens){
    if(mens != NULL){
        mensaje = new char[strlen(mens)+1];
        strcpy(mensaje, mens);
        return true;
    }
    mensaje = NULL;
    return true;
}

bool 
TCalendario::operator ==(const TCalendario& c) {
  if(this->dia==c.dia && this->mes==c.mes && this->anyo==c.anyo){
    if(this->mensaje==NULL && c.mensaje==NULL){
      return true;
    }
    else if(this->mensaje==NULL || c.mensaje==NULL){
      return false;
    }
    else if(strcmp(this->mensaje, c.mensaje)==0){
      return true;
    }
    else
      return false;
  }
  else
    return false;
}

bool
TCalendario::operator!=(const TCalendario &c){
  return !(*this == c);
}

bool 
TCalendario::operator >(const TCalendario& c) {
  if(anyo>c.anyo){
      return true;
  }
  else{
    if(anyo==c.anyo){
      if(mes>c.mes){
          return true;
      }
      else{
        if(mes==c.mes){
          if(dia>c.dia){
            return true;
          }
          else{
            if(dia==c.dia){
              if(mensaje==NULL && c.mensaje==NULL){//NULL>NULL-->FALSE
                return false;
              }
              else if(mensaje==NULL){//NULL>X-->FALSE
                return false;
              }
              else if(c.mensaje==NULL){//X>NULL-->TRUE
                return true;
              }
              else{
                if(strcmp(mensaje, c.mensaje)==0){//X>X-->FALSE
                  return false;
                }
                else if(strcmp(mensaje, c.mensaje)>0){//X>Y-->TRUE
                  return true;
                }
                else{//Y>X-->FALSE
                  return false;
                }

              }
            }
            return false;
          }
        }
      return false;
      }
    }
    return false;
  }
}

bool 
TCalendario::operator <(const TCalendario& c) {
  if(anyo<c.anyo){
        return true;
    }
    else{
      if(anyo==c.anyo){
        if(mes<c.mes){
            return true;
        }
        else{
          if(mes==c.mes){
            if(dia<c.dia){
              return true;
            }
            else{
              if(dia==c.dia){
                if(mensaje==NULL && c.mensaje==NULL){//NULL<NULL-->FALSE
                  return false;
                }
                else if(mensaje==NULL){//NULL<X-->TRUE
                  return true;
                }
                else if(c.mensaje==NULL){//X<NULL-->FALSE
                  return false;
                }
                else{
                  if(strcmp(mensaje, c.mensaje)==0){//X<X-->FALSE
                    return false;
                  }
                  else if(strcmp(mensaje, c.mensaje)<0){//X<Y-->TRUE
                    return true;
                  }
                  else{//Y<X-->FALSE
                    return false;
                  }

                }
              }
              return false;
            }
          }
          return false;
        }
      }
      return false;
    }
}

bool
TCalendario::EsVacio(){
    if(dia==1 && mes==1 && anyo==1900 && mensaje==NULL){
        return true;
    }
    return false;
}

int
TCalendario::Dia(){
    return this->dia;
}

int
TCalendario::Mes(){
    return this->mes;
}

int
TCalendario::Anyo(){
    return this->anyo;
}

char *
TCalendario::Mensaje(){
    return this->mensaje;
}

ostream & operator<<(ostream &os, const TCalendario &c){
  if(c.dia<10){
    os<<"0"<<c.dia<<"/";
  }
  else{
    os<<c.dia<<"/";
  }

  if(c.mes<10){
    os<<"0"<<c.mes<<"/";
  }
  else{
    os<<c.mes<<"/";
  }

  os<<c.anyo;
  os<<" \"";

  if(c.mensaje==NULL){
    os<<"\"";
  }
  else{
    os<<c.mensaje<<"\"";
  }

  return os;
}

void
TCalendario::Copia(const TCalendario &c){
    this->dia = c.dia;
    this->mes = c.mes;
    this->anyo = c.anyo;

    if(c.mensaje!=NULL){
        this->mensaje = new char[strlen(c.mensaje)+1];
        strcpy(this->mensaje, c.mensaje);
    }
    else{
        this->mensaje = NULL;
    }
}   // Función que copia el contenido del objeto que se pasa como argumentos a 'this'

void
TCalendario::fechaPorDefecto(TCalendario &c){
    c.dia=1;
    c.mes=1;
    c.anyo=1900;

    c.mensaje = NULL;
}   // Función que establece la fecha por defecto al objeto que se le pase

bool
TCalendario::comprobarFechaCorrecta(int dia, int mes, int anyo){   // Función que comprueba el número correcto de días y los años bisiestos
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

bool
TCalendario::bisiesto(int a){
  if(a%4==0){
    if(a%100==0){
      if(a%400==0){
        return true;
        return false;
      }
      return false;
    }
    return false;
  }
  else{
    return false;
  }
}
