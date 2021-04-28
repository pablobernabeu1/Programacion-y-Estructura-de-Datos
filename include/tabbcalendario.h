#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"
#include <queue>
 
using namespace std;

#ifndef TABBCALENDARIO_H_
#define TABBCALENDARIO_H_

class TNodoABB;

class TABBCalendario {
	friend class TNodoABB;

	public:
		TABBCalendario();
		TABBCalendario(const TABBCalendario&);
		~TABBCalendario();
		TABBCalendario & operator=(const TABBCalendario &);
		bool operator==(const TABBCalendario &);
		bool EsVacio() const;
		bool Insertar(TCalendario &);
		bool Borrar(TCalendario &); // *
		bool Buscar(TCalendario &) const;
		TCalendario Raiz() const;
		int Altura();
		int Nodos() const;
		int NodosHoja();
		TVectorCalendario Inorden() const;
		TVectorCalendario Preorden() const;
		TVectorCalendario Postorden() const;
		TVectorCalendario Niveles(); 
		friend ostream & operator<<(ostream &, const TABBCalendario &);
		TABBCalendario operator+(const TABBCalendario &);
		TABBCalendario operator-(const TABBCalendario &);

	private:
		TNodoABB *raiz;
		void InordenAux(const TVectorCalendario &, int &) const;
		void PreordenAux(const TVectorCalendario &, int &) const;
		void PostordenAux(const TVectorCalendario &, int &) const;
		void copiar(const TABBCalendario &);
};



class TNodoABB{
	friend class TABBCalendario;

	public:
		TNodoABB();
		TNodoABB(const TNodoABB &);
		~TNodoABB();
		TNodoABB & operator=(const TNodoABB &);

	private:
		TCalendario item;
		TABBCalendario iz, de;
};

#endif