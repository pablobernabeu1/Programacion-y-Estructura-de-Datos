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
    TListaPos(const TListaPos &);
    ~TListaPos();
    TListaPos & operator=(const TListaPos &);

    bool operator==(const TListaPos &);
    bool operator!=(const TListaPos &);
    TListaPos Siguiente();
    bool EsVacia() const;

    friend class TListaCalendario;

};

#endif


#ifndef tlistacalendario_h
#define tlistacalendario_h

class TListaCalendario {

  TNodoCalendario *primero;

  TListaCalendario();
  TListaCalendario(const TListaCalendario &);
  ~TListaCalendario();
  TListaCalendario & operator=(const TListaCalendario &);

  bool operator==(const TListaCalendario &);
  TListaCalendario operator+(const TListaCalendario &);
  TListaCalendario operator-(const TListaCalendario &);
  bool Insertar(const TCalendario &);
  bool Borrar(const TCalendario &);
  bool Borrar(const TListaPos &);
  bool EsVacia();
  TCalendario Obtener(const TListaPos &) const;
  bool Buscar(const TCalendario &);
  int Longitud();
  TListaPos Primera() const;
  TListaPos Ultima();
  TListaCalendario SumarSubl(int I_L1, int F_L1, TListaCalendario &L2, int I_L2, int F_L2);
  TListaCalendario ExtraerRango(int n1, int n2);

  friend ostream & operator<<(ostream &, TListaCalendario &);


};

#endif
