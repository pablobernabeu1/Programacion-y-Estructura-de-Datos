#include<iostream>
#include<cstring>
#include"TCalendario.h"

using namespace std;

TCalendario::TCalendario(){
    dia=1;
    mes=1;
    anyo=1900;
    mensaje = NULL;
}

TCalendario::TCalendario(int dia, int mes, int anyo, char *mens){

    if(dia>=1 && dia<=31 && mes>=1 && mes<=12 && anyo>=1900){
        this->dia=dia;
        this->mes=mes;
        this->anyo=anyo;
        this->mensaje=mens;
    }
    else{
        this->dia=1;
        this->mes=1;
        this->anyo=1900;
        mensaje=NULL;
    }

}

TCalendario::TCalendario(TCalendario &c){
    this->dia=c.Dia();
    this->mes=c.Mes();
    this->anyo=c.Anyo();
    this->mensaje=c.Mensaje();
}

TCalendario::~TCalendario(){
    dia=1;
    mes=1;
    anyo=1900;
    mensaje = NULL;
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