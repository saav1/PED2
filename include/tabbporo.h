#ifndef _TABBPoro_
#define _TABBPoro_

#include <iostream>
#include "tporo.h"
#include "tvectorporo.h"
#include "tlistaporo.h"
using namespace std;
class TNodoABB;
class TABBPoro{
private:
	//Puntero al nodo
	TNodoABB *nodo;
	//AUXILIAR: Devuelve el recorrido en inorden
	void InordenAux(TVectorPoro &, int &);
	//AUXILIAR: Devuelve el recorrido en preorden
	void PreordenAux(TVectorPoro &, int &);
	//AUXILIAR: Devuleve el recorrido en postorden
	void PostordenAux(TVectorPoro &, int &);

public:
	//Métodos del operador igualdad
	bool operator == (const TABBPoro &);
	//Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
	bool EsVacio() const ;
	//Inserta el elemento en el árbol
	bool Insertar(const TPoro &);
	//Borra el elemento en el árbol
	bool Borrar(const TPoro &);
	//Devuelve el elemento en la raíz del árbol
	TPoro raiz()const;
	//Devuelve la altura del árbol (la altura de un árbol vacío es 0)
	int Altura()const;
	//Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
	int Nodos()const;
	//Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
	int NodosHoja()const;
	//Devuelve el recorrido en inorden
	TVectorPoro Inorden()const;
	//Devuelve el recorrido en preorden
	TVectorPoro Preorden()const;
	//Devuelve el recorrido en postrden
	TVectorPoro Postorden()const;
	//Devuelve el recorrido en niveles
	TVectorPoro Niveles()const;
	//Suma de dos ABB
	TABBPoro operator + (const TABBPoro &);
	//Resta de dos ABB
	TABBPoro operator - (const TABBPoro &);
	
//Sobrecarga del operador salida
friend ostream & operator << (ostream &, TABBPoro &);	

};

class TNodoABB{
private:
	//El elemento del nodo
	TPoro item;
	//Subárbol izquierdo y derecho
	TABBPoro iz, de;
public:
	//Constructor por defecto
	TNodoABB();
	//Constructor de copia
	TNodoABB(const TNodoABB &);
	//Destructor
	~TNodoABB();
	//Sobrecarga del operador de asignación
	TNodoABB & operator = (const TNodoABB &);
};

#endif 