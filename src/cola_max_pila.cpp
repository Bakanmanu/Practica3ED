#include <iostream>
#include "cola_max_pila.h"
#include <cassert>

using namespace std;


template <class T>
Pila<T>::Pila(const Pila<T> & otra){
  if (otra.primera!=0){            //Si la pila original no est� vac�a
    Celda *p = otra.primera;       //Copio el puntero al primer nodo
    Celda *nueva;
    primera = 
    nueva = new Celda(p->elemento,0); //Creamos el primer nodo
    p = p->siguiente;                 //Avanzamos el puntero
    while (p!=0){                                  //Mientras queden elementos
      nueva->siguiente = new Celda(p->elemento,0); //Creamos un nuevo nodo
      nueva = nueva->siguiente;                    //Avanzamos los punteros
      p = p->siguiente;
    }
  }
  else                              //Si la pila original est� vac�a
    primera = 0;
  num_elem = otra.num_elem;     //En cualquier caso, copiamos num_elem
}

/* _________________________________________________________________________ */

template <class T>
Pila<T>::~Pila(){
  Celda *aux;
  while (primera!=0){              //Mientras la pila no est� vac�a,
    aux = primera;                 //Copiamos el puntero al tope de la pila
    primera = primera->siguiente;  //Avanzamos primera
    delete aux;                    //Borramos el nodo de la lista
  }
}

/* _________________________________________________________________________ */

template <class T>
Pila<T>& Pila<T>::operator=(const Pila<T> & otra){
  Celda * p;
  
  if (this!=&otra){    //Comprobaci�n de rigor. Si son diferentes objetos
    while (primera!=0){    //Borramos la lista de nodos de la pila *this
      p = primera;
      primera = primera->siguiente;
      delete p;
    }
    if (otra.primera!=0){        //Si la otra pila tiene elementos
      p = otra.primera;          //Copiamos el puntero al primero nodo
      Celda *nueva;
      primera = nueva = new Celda(p->elemento,0);//Reservamos el primer nodo
      p = p->siguiente;                             //Avanzamos el puntero
      while (p!=0){                                 //Mientras queden elementos
        nueva->siguiente = new Celda(p->elemento,0); //Creamos un nuevo nodo
        nueva = nueva->siguiente;                   //Avanzamos nueva (auxiliar)
        p = p->siguiente;                           //Avanzamos el puntero
      }
    }
    num_elem=otra.num_elem;      //En cualquier caso, copiamos num_elem
  }
  return *this; //Devolvemos el objeto para permitir el encadenamiento (a=b=c)
}

/*_________________________________________________________________________ */

template <class T>
void Pila<T>::poner(const T & elem){
  primera = new Celda(elem,primera); //Creamos un nuevo nodo en el tope
  num_elem++;                        //Actualizamos num_elem
}

/* _________________________________________________________________________ */

template <class T>
void Pila<T>::quitar(){
  assert(primera!=0);           //Si la pila no tiene elementos, abortar
  Celda *p = primera;           //Copiamos el puntero al tope
  primera = primera->siguiente; //Actualizamos primera
  delete p;                     //Borramos el nodo que ocupaba el tope
  num_elem--;                   //Actualizamos num_elem
}


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
    
    if(pila.vacia()){        
        pila.poner(elem);
    }else{
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
