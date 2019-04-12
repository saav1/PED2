#include "tabbporo.h"
/*....................TNodoABB...............................*/
//Constructor
TNodoABB::TNodoABB():item(), iz(), de(){}

//Constructor de copia
TNodoABB::TNodoABB(const TNodoABB &nodoAbb){
	if(this != &nodoAbb){
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
	if(this != &nodoAbb){
		this->item = nodoAbb.item;
		this->iz = nodoAbb.iz;
		this->de = nodoAbb.de;
	}
	return(*this);
}
/*...........................................................*/

/*....................TABBPoro...............................*/					
//Constructor
TABBPoro::TABBPoro():nodo(NULL){}

//Constructor de copia
TABBPoro::TABBPoro(const TABBPoro &abbPoro){
	//EL CONSTRUCTOR FALTA POR IMPLEMENTAR//

	//El constructor de copia debe copiar todos los nodos del árbol.
	
	if(this != &abbPoro){
		this->nodo = new TNodoABB(*abbPoro.nodo);
	}
}
//
//Destructor
TABBPoro::~TABBPoro(){
	//if(this->nodo != NULL) delete nodo;
	this->nodo = NULL;
}

//Sobrecarga del operador asignación
TABBPoro & TABBPoro::operator = (const TABBPoro &abbPoro){
	if(this != &abbPoro){
		this->nodo = abbPoro.nodo;
	}
	return(*this);
}  	

//Sobrecarga del operador igualdad
bool TABBPoro::operator == (const TABBPoro &abbPoro){
	bool iguales = (( (this->nodo == NULL && abbPoro.nodo == NULL) || 
		(this->nodo != NULL && abbPoro.nodo != NULL)) &&
		(this->nodo == abbPoro.nodo) ) ? true : false;
	return iguales;
} 

//Devuelve TRUE si el arbol está vacío
bool TABBPoro::EsVacio()const{
	if(this->nodo == NULL) return true;
	return false;
}

//Inserta el elemento en el árbol
bool TABBPoro::Insertar(const TPoro &poro){
	if((*this).EsVacio()){

		TNodoABB *abbNodo = new TNodoABB();
		abbNodo->item = poro;
		this->nodo = abbNodo;
		return true;

	}else{

		if((*this).nodo->item.Volumen() != poro.Volumen()){

			if(poro.Volumen() < this->nodo->item.Volumen()){

				cout << "iz" << endl;
				return this->nodo->iz.Insertar(poro);

			}else{
				cout << "de" << endl;
				return this->nodo->de.Insertar(poro);
			} 
		}

		return false;
	}
}


//Borra el elemento del árbol
bool TABBPoro::Borrar(const TPoro &poro){
	return false;
}


//Devuelve TRUE  si el elemento está en el árbol
bool TABBPoro::Buscar(const TPoro &poro){
	
	if(this->nodo == NULL) return false;
	if((*this).nodo->item == poro) return true;

	if(poro.Volumen() < (*this).nodo->item.Volumen())
		return (*this).nodo->iz.Buscar(poro);
	else 
		return (*this).nodo->de.Buscar(poro);
	
}

bool TABBPoro::auxBuscar(const TPoro &poro,  TABBPoro &abb){
	if(abb.nodo == NULL) return false;
	if(abb.nodo->item == poro) return true;
	return(auxBuscar(poro, abb.nodo->iz) && auxBuscar(poro, abb.nodo->de) );
	return true;
}


//Devuelve el elemento en la raíz del árbol
TPoro TABBPoro::Raiz()const{
	TPoro poro;
	if(!(*this).EsVacio()){
		poro = nodo->item;
	}
	return poro;
}



//Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TABBPoro::Altura()const{
	int i = 0;
	if(!(*this).EsVacio()){
		//Que pasa cuando el árbol no es vacío. 
		i++;
		if(!(*this).nodo->iz.EsVacio()) 
			i += (*this).nodo->iz.Altura();
		else
			i += (*this).nodo->de.Altura();

	}
	return i;
}

//Devuelve el número de nodos del árbol(un árbol vacío posee 0 nodos)
int TABBPoro::Nodos()const{
	return 1;
}

//Devuelve el número de nodos hoja en el árbol (la raiz puede ser un nodo hoja)
int TABBPoro::NodosHoja()const{
	return 1;
}

//Devuelve el recorrido en inorden
TVectorPoro TABBPoro::Inorden()const{
	TVectorPoro vp;
	return vp;
}

//Devuelve el recorrido en preorden
TVectorPoro TABBPoro::Preorden()const{
	TVectorPoro vp;
	return vp;
}

//Devuelve el recorrido en postorden
TVectorPoro TABBPoro::Postorden()const{
	TVectorPoro vp;
	return vp;
}

//Suma de dos ABB
TABBPoro TABBPoro::operator + (const TABBPoro &abbPoro){
	TABBPoro abb;
	return abb;
}

//Resta de dos ABB
TABBPoro TABBPoro::operator - (const TABBPoro &abbPoro){
	TABBPoro abb;
	return abb;
}




//Sobrecarga del operador de salida << 
ostream & operator << (ostream &os,const TABBPoro &abb){
	os << abb.nodo->item << endl;
}	

/*...........................................................*/



/*	
	ACLARACIONES 

1. Se permite amistad entre las clases TABBPoro y TNodoABB.

2. La forma de emplear los métodos AUXILIARES para las ordenaciones,
es, por ejemplo, para el caso en INORDEN:
	
	//Devuelve el recorrido en inorden
	TVectorPoro TABBPoro::Inorden(){
		
		//Posición en el vector que almacena el recorrido
		int posicion = 1;

		//Vector del tamaño adecuado para almacenar todos los nodos
		TVectorPoro v(Nodos());
		InordenAux(v, posicion);
		return v;
	}

	De este modo se reduce el coste de crear múltiples objetos de tipo
	TVectorPoro, ya que solo se emplea uno durante el cálculo del recorrido.

3.Los TPoro en el árbol están ordenados en función del volumen.

4.Para simplificar los algoritmos, el árbol NO puede contener elementos 
con el mismo volumen. Por tanto, solo se podrá insertar 1 TPoro vacío, al no
poder repetirse el volumen en el árbol.

5.El Consturctor de Copia tiene que realizar una copia exacta duplicando
todos los nodos del árbol.

6.El Destructor tiene que liberar toda la memoria que ocupe el árbol.

7.Si se asigna un árbol a un árbol no vacío, se destruye el árbol incial. 
La Asignación tiene que realizar una copia exacta duplicando todos los nodos
del árbol.

8.En el operador '==', dos árboles son iguales si poseen los mismos elementos
independientemente de la esturctura interna del árbol (No se exige que la
estructura de ambos sea la misma).

9.Insertar devuelve TRUE si el elemento se puede insertar y FALSE en caso 
contrario (por ejemplo, porque el elemento a insertar ya existe en el árbol)

10.Borrar devuelve el TRUE si el elemento se puede borrar y FALSE en caso 
contrario (por ejemplo, porque no existe en el árbol). El criterio de borrado
es sustituir por el mayor de la izquierda.

11.Raiz devuelve el TPoro raíz del árbol. Si el árbol está vacío, devuelve un
TPoro vacío.

12.Los 4 recorridos devuelven un vector(TVectorPoro) en el que todas las posiciones
están ocupadas por los elementos del árbol(no pueden quedar posiciones sin asignar).
Si el árbol está vacío, se devuelve un vector vacío(vector de dimensión 0).

13.El operador SALIDA muestra el recorrido por NIVELES del ABB, con el formato
pedido en el CUADERNILLO 1 para la clase TVectorPoro.

14.Para implementar el recorido por NIVELES hace falta utilizar una estructura de tipo
COLA de punteros ABB. Para implementar el uso de la estructura, el alumno puede emplear
elementos que considere oportunos. Algunas opciones son:
	14.1 Estrcuturas "queue" pre-definidas en las STL consultar 'cplusplus/queue' y 'push'
	14.1 Una adaptación de las estructuras TListaPoro para que se comporte como COLA
	de putneros a ABB.

15.En el operador '+' primero se tiene que sacar una copia del operando(árbol) de la 
izquierda y a continuación insertar los elementos del operando(árbol) de la derecha
según su recorrido por INORDEN.

16.En el operador '-' se recorre el operando(árbol) de la izquierda por INORDEN y si 
el elemento NO está en el operando(árbol) de la derecha, se inserta en el árbol resultante
(incialmente vacío) y el proceso se repite para todos los elementos del operando de la 
izquierda.

*/































