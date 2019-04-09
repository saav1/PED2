#include "tabbporo.h"
//....................TNodoABB...............................//

//Constructor
TNodoABB::TNodoABB():item(), iz(), de(){}

//Constructor de copia
TNodoABB::TNodoABB(const TNodoABB &nodoAbb){
	if(this != nodoAbb){
		this->item = nodoAbb.item;
		this->iz = nodoAbb.iz;
		this->de = nodoAbb.de;
	}
}

//Destructor
TNodoABB::~TNodoABB(){
	this->item = TPoro();
	this->iz = TABBPoro();
	this->de = TABBPoro();
}

//Sobrecarga del operador de asignación
TNodoABB & TNodoABB::operator = (const TNodoABB &nodoAbb){
	if(this != nodoAbb){
		this->item = nodoAbb.item;
		this->iz = nodoAbb.iz;
		this->de = nodoAbb.de;
	}
	return(*this);
}
//...........................................................//

//....................TABBPoro...............................//
//...........................................................//
