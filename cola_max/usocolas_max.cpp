#include <iostream>
#include "ColaMax.h"

using namespace std;

int main(){
    ColaMax q;
    int i;
    for (i=10; i>=0; i--)
        q.poner(i);

    while(!q.vacia()){
        elemento x = q.frente();
        cout << x << endl;
        q.quitar();
    }
    return 0;
}