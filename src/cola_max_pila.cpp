#include <iostream>
#include "include/cola_max_pila.h"

using namespace std;

cola_max_pila::cola_max_pila(){
    num_elem = 0;
}

cola_max_pila::cola_max_pila(const cola_max_pila &otra){
    if(!otra.pila.vacia())
        pila = otra.pila;    
    num_elem = otra.num_elem;
}


cola_max_pila::~cola_max_pila(){
    while(!pila.vacia()){
        pila.quitar();
    }
    num_elem = 0;
}


void cola_max_pila::poner(const int valor){
    // Creamos una pila auxiliar para ayudarnos a mantener la estructura FIFO
    Pila<Elemento> aux;
    //Procedemos a la creacion del dato elemento que se va a añadir a la cola
    Elemento elem;          
    elem.ele = valor;                // Inicializamos el valor del elemento
    if(valor > frente_max())           // Comprobamos si el valor dado es el maximo de la cola
        elem.maximo = valor;
    else                             // Si no es un nuevo maximo le asignamos el maximo de la cola
        elem.maximo = frente_max();

    //Volcamos la pila en otra pila para mantener el orden de los datos introducidos
    while(!pila.vacia()){
        aux.poner(pila.tope());
        pila.quitar();
    }
    // Insertamos el nuevo elemento
    pila.poner(elem);
    // Devolvemos los datos a la pila original
    while(!aux.vacia()){
        pila.poner(aux.tope());
        aux.quitar();
    }
    num_elem++;
}

void cola_max_pila::quitar(){
    pila.quitar();
    num_elem--;
}

Elemento cola_max_pila::frente(){
    return pila.tope();
}

int cola_max_pila::frente_ele(){
    return pila.tope().ele;
}

int cola_max_pila:: frente_max(){
    return pila.tope().maximo;
}

bool cola_max_pila::vacia(){
    if(num_elementos()==0)
        return true;
    else   
        return false;
}
int cola_max_pila::num_elementos(){
    return this->num_elem;
}

void cola_max_pila::mostrar_cola(){
    cola_max_pila aux(*this);       // Creamos una instancia de cola_max_pila auxiliar para no modificar la cola original
    cout << "La cola contiene los siguientes elementos: "<< endl;
    while(!aux.vacia()){
        cout << aux.frente() << endl;
        aux.quitar();
    }

}
