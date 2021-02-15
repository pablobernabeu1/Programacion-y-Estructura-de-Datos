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

    TCalendario c1(1,1,1901, (char *)"Hola.");
    TCalendario c2(c1);

    /*
    cout<<c1.Dia()<<endl;
    cout<<c1.Mes()<<endl;
    cout<<c1.Anyo()<<endl;
    cout<<c1.Mensaje()<<endl;
    */  
    cout<<c2.Dia()<<endl;
    cout<<c2.Mes()<<endl;
    cout<<c2.Anyo()<<endl;
    cout<<c2.Mensaje()<<endl;


    return 0;
}