#include "tcalendario.h"
using namespace std;


#ifndef TLISTACALENDARIO_H_
#define TLISTACALENDARIO_H_

class TNodoCalendario {

  friend class TListaPos;
  friend class TListaCalendario;

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

};

class TListaPos {

  friend class TListaCalendario;

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

};


class TListaCalendario {

  private:
    TNodoCalendario *primero;
  public:
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
  bool Buscar(const TCalendario &) const;
  int Longitud() const;
  TListaPos Primera() const;
  TListaPos Ultima() const;
  TListaCalendario SumarSubl(int I_L1, int F_L1, TListaCalendario &L2, int I_L2, int F_L2);
  TListaCalendario ExtraerRango(int n1, int n2);

  friend ostream & operator<<(ostream &os, const TListaCalendario &lc);


};
#endif
