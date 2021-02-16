#include<iostream>
using namespace std;


class TCalendario {

    private:
        int dia, mes, anyo;
        char* mensaje;

    public:
        TCalendario();
        TCalendario(int dia, int mes, int anyo, char *mens);
        TCalendario(TCalendario &);
        ~TCalendario();
        TCalendario & operator=(TCalendario &);

        TCalendario operator+(int);
        TCalendario operator-(int);
        TCalendario operator++(int);
        TCalendario &operator++();
        TCalendario &operator--();
        
        bool ModFecha(int, int, int);
        bool ModMensaje(char *);
        bool operator ==(TCalendario &);
        bool operator !=(TCalendario &);
        bool operator>(TCalendario &);
        bool operator<(TCalendario &);

        bool EsVacio();
        int Dia();
        int Mes();
        int Anyo();
        char *Mensaje();

        friend ostream & operator<<(ostream &, TCalendario &);

};