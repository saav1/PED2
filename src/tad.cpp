#include <iostream>
#include "tporo.h"
#include "tvectorporo.h"
#include "tabbporo.h"
using namespace std;

int main(void){

  TPoro a(1, 2, 3, "a"); //Se pondrá en la raíz.
  TPoro b(2, 3, 2, "b"); //Se pondrá a la derecha del 'a'.
  TPoro c(4, 5, 4, "c"); //Se pondrá a la izquierda del 'a'.
  TPoro d(1, 2, 1, "d");
  TPoro e(1, 2, 5, "e");
  TPoro f(1, 3, 3.5, "f");
  TPoro g(1, 2, 2.5, "g");
  TABBPoro abb;
    
 
   cout << "Insertar a: " << abb.Insertar(a) << endl;
   cout << "Insertar b: " << abb.Insertar(b) << endl;
   cout << "Insertar c: " << abb.Insertar(c) << endl;
   cout << "Insertar a: " << abb.Insertar(a) << endl;
   cout << "Insertar d: " << abb.Insertar(d) << endl;
   cout << "Insertar e: " << abb.Insertar(e) << endl;
   cout << "Insertar f: " << abb.Insertar(f) << endl;
   cout << "Insertar g: " << abb.Insertar(g) << endl;
   cout << "Altura: " << abb.Altura() << endl;

   cout << "Nodos: " << abb.Nodos() << endl;
   cout << "Nodos Hoja: " << abb.NodosHoja() << endl;


   TABBPoro abb2(abb);
	
   cout << "Nodos abb2: " << abb2.Nodos() << endl;


return 0;
}
