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

class TListaPos {

  private:
    TNodoCalendario *pos;

  public:
    TListaPos();
    TListaPos(TListaPos &);
    ~TListaPos();
    TListaPos & operator=(TListaPos &);

    bool operator==(TListaPos &);
    bool operator!=(TListaPos &);
    TListaPos Siguiente();
    bool EsVacia();

};
