#include<iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"

using namespace std;

#ifndef _TAVLCALENDARIO_H_
#define _TAVLCALENDARIO_H_


class TNodoAVL;


class TAVLCalendario {
	friend class TNodoAVL;

private: 
	TNodoAVL *raiz;
	void InordenAux(TVectorCalendario &, int &) const;
	void PreordenAux(TVectorCalendario &, int &) const;
	void PostordenAux(TVectorCalendario &, int &) const;
	void copiar(const TAVLCalendario &);
	bool EquilibrarIzquierda();
	//Equilibra el arbol por la derecha
	bool EquilibrarDerecha();
	//Reequilbra los factores de equilibrio
	void reequilibrarFE();
	void Mover(TAVLCalendario&,TAVLCalendario&);
	// Mueve el arbol al que apunta el puntero al arbol
	void Mover(TAVLCalendario&,TAVLCalendario*&);
	// Mueve el arbol a la posición donde apunta el puntero
	void Mover(TAVLCalendario*&,TAVLCalendario&);
	// Mueve el arbol al que apunta el arbol de la derecha al puntero que apunta el árbol de la izquierda
	void Mover(TAVLCalendario*&,TAVLCalendario*&);

public:
	TAVLCalendario();
	TAVLCalendario(const TAVLCalendario &);
	~TAVLCalendario();
	TAVLCalendario & operator=(const TAVLCalendario &);

	bool operator==(const TAVLCalendario &) const;
	bool operator!=(const TAVLCalendario &) const;
	bool EsVacio() const;
	bool Insertar(const TCalendario &);
	bool Borrar(const TCalendario &);
	bool Buscar(const TCalendario &);
	TCalendario Raiz() const;
	int Altura() const;
	int Nodos() const;
	int NodosHoja() const;
	TVectorCalendario Inorden() const;
	TVectorCalendario Preorden() const;
	TVectorCalendario Postorden() const;

	friend ostream & operator<<(ostream &, const TAVLCalendario &);
};


class TNodoAVL {
	friend class TAVLCalendario;

	private: 

		TCalendario item;
		TAVLCalendario iz, de;
		int fe;

	public:

		TNodoAVL();
		TNodoAVL(const TNodoAVL &);
		~TNodoAVL();
		TNodoAVL & operator=(const TNodoAVL &);
};


#endif