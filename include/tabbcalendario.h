#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"

using namespace std;

#ifndef TABBCALENDARIO_H_
#define TABBCALENDARIO_H_

class TNodoABB;

class TABBCalendario {
	friend class TNodoABB;

	public:
		TABBCalendario();
		TABBCalendario(const TABBCalendario);
		~TABBCalendario();
		TABBCalendario & operator=(const TABBCalendario &);
		bool operator==(const TABBCalendario &);
		bool EsVacio();
		bool Insertar(const TCalendario &);
		bool Borrar(const TCalendario &);
		bool Buscar(const TCalendario &);
		TCalendario Raiz();
		int Altura();
		int Nodos();
		int NodosHoja();
		TVectorCalendario Inorden();
		TVectorCalendario Preorden();
		TVectorCalendario Postorden();
		TVectorCalendario Niveles();
		friend ostream & operator<<(ostream & const TABBCalendario &);
		TABBCalendario operator+(const TABBCalendario &);
		TABBCalendario operator-(const TABBCalendario &);

	private:
		TNodoABB *raiz;
		TABBCalendario* MayorArbol();
		void copiar(const TABBCalendario &);
};

class TNodoABB{

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