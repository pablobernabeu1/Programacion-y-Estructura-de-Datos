#ifndef tnodocalendario_h
#define tnodocalendario_h

#include<iostream>
#include<cstring>
#include "tcalendario.h"

using namespace std;

class TNodoCalendario {

  private:
    TCalendario c;
    TNodoCalendario *siguiente;
    bool operator==(const TNodoCalendario &);
    bool operator!=(const TNodoCalendario &);

  public:
    TNodoCalendario();
    TNodoCalendario(const TNodoCalendario &);
    ~TNodoCalendario();
    TNodoCalendario & operator=(const TNodoCalendario &);

    friend class TListaPos;
    friend class TListaCalendario;

};

#endif

#ifndef tlistapos_h
#define tlistapos_h

class TListaPos {

  private:
    TNodoCalendario *pos;

  public:
    TListaPos();
    TListaPos(TListaPos &);
    ~TListaPos();
    TListaPos & operator=(const TListaPos &);

    bool operator==(const TListaPos &);
    bool operator!=(const TListaPos &);
    TListaPos Siguiente();
    bool EsVacia();

    friend class TListaCalendario;

};

#endif


#ifndef tlistacalendario_h
#define tlistacalendario_h

class TListaCalendario {

  TNodoCalendario *primero;

  TListaCalendario();
  TListaCalendario(TListaCalendario &);
  ~TListaCalendario();
  TListaCalendario & operator=(TListaCalendario &);

  TListaPos Primera();


};

#endif
