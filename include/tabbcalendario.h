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
		bool EsVacio();
		bool Insertar(TCalendario &);
		bool Borrar(TCalendario &);
		bool Buscar(TCalendario &);
		TCalendario Raiz();
		int Altura();
		int Nodos();
		int NodosHoja();
		TVectorCalendario Inorden();
		TVectorCalendario Preorden();
		TVectorCalendario Postorden();
		TVectorCalendario Niveles();
		friend ostream & operator<<(ostream &,	 const TABBCalendario &);
		TABBCalendario operator+(const TABBCalendario &);
		TABBCalendario operator-(const TABBCalendario &);

	private:
		TNodoABB *raiz;
		TABBCalendario* MayorArbol();
		void InordenAux(const TABBCalendario &, int &);
		void PreordenAux(const TABBCalendario &, int &);
		void PostordenAux(const TABBCalendario &, int &);
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