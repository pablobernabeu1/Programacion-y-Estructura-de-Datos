#include<iostream>
#include<cstring>
#include"TCalendario.h"

using namespace std; // Comprobar github

TCalendario::TCalendario(){
    fechaPorDefecto(*this);
}

TCalendario::TCalendario(int dia, int mes, int anyo, char *mens){  // Comentario de comprobacion

    if(dia>=1 && dia<=31 && mes>=1 && mes<=12 && anyo>=1900){
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
        this->dia=1;
        this->mes=1;
        this->anyo=1900;
        mensaje=NULL;
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
        temp.mes = this->mes + ((n%365)/31);
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

bool 
TCalendario::ModFecha(int d, int m, int a){

    if(dia>=1 && dia<=31 && mes>=1 && mes<=12 && anyo>=1900){
        dia = d;
        mes = m;
        anyo = a;
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
    return false;
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
}

void TCalendario::fechaPorDefecto(TCalendario &c){
    c.dia=1;
    c.mes=1;
    c.anyo=1900;

    mensaje = NULL;
}