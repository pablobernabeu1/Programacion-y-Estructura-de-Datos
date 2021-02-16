#include<iostream>
using namespace std;
#include "TCalendario.h"
/*
int main(){

    TCalendario c1;

    cout<<c1.Dia()<<endl;
    cout<<c1.Mes()<<endl;
    cout<<c1.Anyo()<<endl;
    cout<<c1.Mensaje()<<endl;

    return 0;
}*/

int main(){

    TCalendario c1(19,4,2001, (char *)"Fecha de nacimiento.");

    c1.ModFecha(2,12,2030);
    c1.ModMensaje((char *)"Fecha de boda.");

    cout<<c1.Dia()<<endl;
    cout<<c1.Mes()<<endl;
    cout<<c1.Anyo()<<endl;
    cout<<c1.Mensaje()<<endl;
    
    


    return 0;
}