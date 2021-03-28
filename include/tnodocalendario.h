#include<iostream>
#include<cstring>
#include "tcalendario.h"

using namespace std;

class TNodoCalendario {

  private:
    TCalendario c;
    TNodoCalendario *siguiente;

  public:
    TNodoCalendario();
    TNodoCalendario(TNodoCalendario &);
    ~TNodoCalendario();
    TNodoCalendario & operator=(TNodoCalendario &);

};
