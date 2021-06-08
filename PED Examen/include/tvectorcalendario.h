#include<iostream>
#include<cstring>
#include "tcalendario.h"

using namespace std;

#ifndef TVECTORCALENDARIO_H_
#define TVECTORCALENDARIO_H_

class TVectorCalendario {

  private:
    TCalendario *c;
    int tamano;
    TCalendario error;
    bool comprobarFechaCorrecta(int, int, int);

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

#endif