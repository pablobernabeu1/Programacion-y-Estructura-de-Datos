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
    this->dia=c.Dia();
    this->mes=c.Mes();
    this->anyo=c.Anyo();

    if(c.Mensaje()!=NULL){
        this->mensaje = new char[strlen(c.Mensaje())+1];
        strcpy(this->mensaje, c.Mensaje());
    }
    else{
        this->mensaje=NULL;
    }
}

TCalendario::~TCalendario(){
    dia=1;
    mes=1;
    anyo=1900;
    mensaje = NULL;
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
    if(mensaje != NULL){
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