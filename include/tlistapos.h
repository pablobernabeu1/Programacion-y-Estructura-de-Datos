#include<iostream>
#include<cstring>
#include "tnodocalendario.h"

using namespace std;

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
