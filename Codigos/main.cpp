#include<iostream>
using namespace std;
#include "tcalendario.h"
/*
int main(){

    TCalendario c1;

    cout<<c1.Dia()<<endl;
    cout<<c1.Mes()<<endl;
    cout<<c1.Anyo()<<endl;
    cout<<c1.Mensaje()<<endl;

    return 0;
}*/

/*
int main(){

    TCalendario c1, c4;
    TCalendario c2(19,4,2001, (char *)"Fecha de nacimiento.");

    c4 = c1 - 10;

    //TCalendario c1(c2);

    cout<<c1.Dia()<<endl;
    cout<<c1.Mes()<<endl;
    cout<<c1.Anyo()<<endl;
    cout<<c1.Mensaje()<<endl;




    return 0;
}
*/

int main(){

    TCalendario c1(19, 4, 2001, (char *)"Mi fecha de cumpleaños.");

    TCalendario c2 = c1+2;

    cout<<c2<<endl;

    return 0;
}
