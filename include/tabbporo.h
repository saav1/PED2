#ifndef _TABBPoro_
#denife _TABBPoro_

#include <iostream>
using namespace std;

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
	bool operator == (TABBPoro &);
	//Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
	bool EsVacio();
	//Inserta el elemento en el árbol
	bool Insertar(TPoro &);
	//Borra el elemento en el árbol
	bool Borrar(TPoro &);
	//Devuelve el elemento en la raíz del árbol
	TPoro raiz();
	//Devuelve la altura del árbol (la altura de un árbol vacío es 0)
	int Altura();
	//Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
	int Nodos();
	//Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
	int NodosHoja();
	//Devuelve el recorrido en inorden
	TVectorPoro Inorden();
	//Devuelve el recorrido en preorden
	TVectorPoro Postorden();
	//Devuelve el recorrido en niveles
	TVectorPoro Niveles();
	//Suma de dos ABB
	TABBPoro operator + (TABBPoro &);
	//Resta de dos ABB
	TABBPoro oerator - (TABBPoro &);
	
//Sobrecarga del operador salida
firend ostream & operator << (ostream &, TABBPoro &);	


};

#endif _TABBPoro_
