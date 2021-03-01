#include<iostream>
#include<cstring>
#include"TCalendario.h"

using namespace std; // Comprobar github

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

TCalendario::TCalendario(TCalendario &c){
    Copia(c);
}

TCalendario::~TCalendario(){
    fechaPorDefecto(*this);
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
    TCalendario temp;
    //preguntar si está esto bien o simplemente hay que sumar días.

    if(n>=0){
        temp.dia = this->dia + ((n%365)%31);
        modificarMes(*this);
        temp.mes = this->mes + ((n%365)/31);
        modificarAnyo(*this);
        temp.anyo = this->anyo + (n/365);
    }

    if(this->Mensaje()!=NULL){
        temp.mensaje = new char[strlen(this->Mensaje())+1];
        strcpy(temp.mensaje, this->Mensaje());
    }
    else{
        temp.mensaje = NULL;
    }

    return temp;
}

TCalendario
TCalendario::operator-(const int n){
    TCalendario temp;
    //preguntar si está esto bien o simplemente hay que sumar días.

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

  dia++;
  modificarMes(*this);
  modificarAnyo(*this);

  return temp;
}

TCalendario&
TCalendario::operator++(){
  dia++;
  modificarMes(*this);
  modificarAnyo(*this);

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
      this->anyo = anyo;

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
TCalendario::operator==(const TCalendario &c){
  bool temp;

  temp == ((this->dia == c.dia) && (this->mes == c.mes) && (this->anyo == c.anyo) && strcmp(this->mensaje, c.mensaje));

  return temp;
}

bool
TCalendario::operator!=(const TCalendario &c){
  return !(*this == c);
}

bool
TCalendario::operator>(const TCalendario &c){
  if(this->anyo>c.anyo){
    return true;
  }
  else if(this->anyo==c.anyo){

    if(this->mes>c.mes){
      return true;
    }
    else if(this->mes==c.mes){

      if(this->dia>c.dia){
        return true;
      }
      else if(this->dia==c.dia){
        if(this->Mensaje()!=NULL && c.mensaje!=NULL){
          if(strcmp(this->Mensaje(), c.mensaje)==true){
            return false;
          }
          else{
            return false; //Provisional
          }
        }
        else{
          return false; //Provisional
        }
      }
      else{
        return false;
      }
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}

bool
TCalendario::operator<(const TCalendario &c){
  if(this->anyo>c.anyo){
    return false;
  }
  else if(this->anyo==c.anyo){

    if(this->mes>c.mes){
      return false;
    }
    else if(this->mes==c.mes){

      if(this->dia>c.dia){
        return false;
      }
      else if(this->dia==c.dia){
        if(this->Mensaje()!=NULL && c.mensaje!=NULL){
          if(strcmp(this->Mensaje(), c.mensaje)==true){
            return false;
          }
          else{  // comprobar que cadena es mayor, no se como hacerlo
            return false; //Provisional
          }
        }
        else{
          return false; //Provisional
        }
      }
      else{
        return true;
      }
    }
    else{
      return true;
    }
  }
  else{
    return true;
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

ostream & operator<<(ostream &os, TCalendario &c){
  if(c.Dia()<10){
    os<<"0"<<c.Dia()<<"/";
  }
  else{
    os<<c.Dia()<<"/";
  }

  if(c.Mes()<10){
    os<<"0"<<c.Mes()<<"/";
  }
  else{
    os<<c.Mes()<<"/";
  }

  os<<c.Anyo();
  os<<" ";

  if(c.Mensaje()==NULL){
    os<<"";
  }
  else{
    os<<c.Mensaje();
  }

  return os;
}

void
TCalendario::Copia(const TCalendario &c){
    this->dia = c.dia;
    this->mes = c.mes;
    this->anyo = c.anyo;

    if(c.mensaje!=NULL){
        this->mensaje = new char[strlen(c.mensaje+1)];
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

    mensaje = NULL;
}   // Función que establece la fecha por defecto al objeto que se le pase

void
TCalendario::modificarMes(TCalendario &c){
    c.ModFecha(1, c.Mes()+1, c.Anyo());
}  // Función que cambia de mes si el dia es mayor de 31

void
TCalendario::modificarAnyo(TCalendario &c){
  if(c.Mes()>12){
    c.ModFecha(c.Dia(), 1, c.Anyo()+1);
  }
}  // Función que cambia de año si el mes es mayor de 12

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
