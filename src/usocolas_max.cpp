#include <iostream>
#include "Cola_max_Pila.h"

using namespace std;

int main(){
  Cola_max_Pila q;
  int i;

  for (i=10; i>=0; i-- )
    q.poner();

  while (!q.vacia()){
    elemento x = q.frente();
    cout << x << endl;
  }
  
  return 0;
}
