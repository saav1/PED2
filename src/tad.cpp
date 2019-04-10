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
  
  abb.Insertar(a);
  abb.Insertar(b);
  abb.Insertar(c);

  bool var = abb.Buscar(a);
  cout << var << endl;


  bool var1 = abb.Buscar(d);
  cout << var1 << endl;

  

return 0;
}
