#include<iostream>
using namespace std;


class TCalendario {

    private:
        int dia, mes, anyo;
        char* mensaje;
        void Copia(const TCalendario &);
        void fechaPorDefecto(TCalendario &);
        void modificarMes(TCalendario &);
        void modificarAnyo(TCalendario &);

    public:
        TCalendario();
        TCalendario(int dia, int mes, int anyo, char *mens);
        TCalendario(TCalendario &);
        ~TCalendario();
        TCalendario & operator=(const TCalendario &);

        TCalendario operator+(const int);
        TCalendario operator-(int);
        TCalendario operator++(int);
        TCalendario &operator++();
        TCalendario operator--(int);
        TCalendario &operator--();

        bool ModFecha(int, int, int);
        bool ModMensaje(char *);
        bool operator ==(const TCalendario &);
        bool operator !=(const TCalendario &);
        bool operator>(const TCalendario &);
        bool operator<(const TCalendario &);

        bool EsVacio();
        int Dia();
        int Mes();
        int Anyo();
        char *Mensaje();

        friend ostream & operator<<(ostream &, TCalendario &);

};
