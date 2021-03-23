#include<iostream>
#include<cstring>
#include "tcalendario.h"

using namespace std;

class TVectorCalendario {

  private:
    TCalendario *c;
    int tamano;
    TCalendario error;

  public:
    TVectorCalendario();
    TVectorCalendario(int);
    TVectorCalendario(const TVectorCalendario &);
    ~TVectorCalendario();
    TVectorCalendario & operator=(const TVectorCalendario &);

    bool operator==(const TVectorCalendario &);
    bool operator!=(const TVectorCalendario &);
    TCalendario & operator[](int);
    TCalendario operator[](int) const;
    int Tamano();
    int Ocupadas();
    bool ExisteCal(TCalendario &);
    void MostrarMensajes(int, int, int);
    bool Redimensionar(int);

    friend ostream & operator<<(ostream &, const TVectorCalendario &);

};
