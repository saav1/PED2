#include <iostream>
#include "tporo.h"
#include "tvectorporo.h"
#include "tabbporo.h"
using namespace std;

int main(void){

  TPoro a(1, 2, 1, "a"); //Se pondrá en la raíz.
  TPoro b(2, 3, 2, "b"); //Se pondrá a la derecha del 'a'.
  TPoro c(4, 5, 0, "c"); //Se pondrá a la izquierda del 'a'.
  TPoro d(1, 2, 3, "s");
  TABBPoro abb;
  
 
   cout << abb.Insertar(a) << endl;
   cout << abb.Insertar(b) << endl;
   cout << abb.Insertar(c) << endl;


return 0;
}
