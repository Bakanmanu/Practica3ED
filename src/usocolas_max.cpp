#include <iostream>
//#include "pila.h"
#include "cola_max_pila.h"

using namespace std;

int main(){
  cola_max_pila q;
  int i;

  for (i=10; i>=0; i-- )
    q.poner(i);

  while (!q.vacia()){
    Elemento x = q.frente();
    cout << x << endl;
  }
  // q.mostrar_cola();

  return 0;
}
