#include <iostream>
#include "tavlcalendario.h"
#include "tabbcalendario.h"

using namespace std;

int
main(void)
{
    TCalendario a(5,10,2006, (char*) "mensaje 5");
    TCalendario b(3,10,2006, (char*) "mensaje 3");
    TCalendario c(8,10,2006, (char*) "mensaje 8");
    TCalendario d(2,10,2006, (char*) "mensaje 2");
    TCalendario e(1,10,2006, (char*) "mensaje 1");
    TCalendario f(7,10,2006, (char*) "mensaje 7");
    TCalendario g(10,10,2006, (char*) "mensaje 10");
    
    TListaCalendario l;

    TABBCalendario tabb;

    tabb.Insertar(a);
    tabb.Insertar(b);
    tabb.Insertar(c);
    tabb.Insertar(d);
    tabb.Insertar(e);
    tabb.Insertar(f);
    //tabb.Insertar(g);

    l.Insertar(g);

    cout<<tabb.ABBCamino(l)<<endl;

    //cout<<l<<endl;

}
