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

    cout<<c1<<endl;

    return 0;
}
