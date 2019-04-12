#include <iostream>
#include "tporo.h"
#include "tvectorporo.h"
#include "tabbporo.h"
using namespace std;

int main(void){

  TPoro a(1, 2, 3, "a"); //Se pondrá en la raíz.
  TPoro b(2, 3, 2, "b"); //Se pondrá a la derecha del 'a'.
  TPoro c(4, 5, 4, "c"); //Se pondrá a la izquierda del 'a'.
  TPoro d(1, 2, 1, "s");
  TPoro e(1, 2, 5, "a");
  TABBPoro abb;
    
 
   cout << "Insertar a: " << abb.Insertar(a) << endl;
   cout << "Insertar b: " << abb.Insertar(b) << endl;
   cout << "Insertar c: " << abb.Insertar(c) << endl;
   cout << "Insertar a: " << abb.Insertar(a) << endl;
   cout << "Insertar d: " << abb.Insertar(d) << endl;
   cout << "Insertar e: " << abb.Insertar(e) << endl;
   cout << "Altura: " << abb.Altura() << endl;

   cout << "Nodos: " << abb.Nodos() << endl;


return 0;
}
