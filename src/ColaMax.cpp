#include "ColaMax.h"
#include <cassert>
#include <iostream>

using namespace std;

typedef int T;

template <class T>
ColaMax<T>::ColaMax(const ColaMax<T> & original){
    if(!original.vacia()){                  //Si tiene elementos procedemos a copiarlos todos
        Celda *p = original.primera;            //Copiamos el puntero a la primera celda
        primera = p;                            //Lo guardamos en la nueva cola
        ultima = new Celda(p->elemento, 0);     //Inicializamos la celda ultima con el elemento de la primera celda 
        p = primera->siguiente;                 //Avanzamos el puntero de la cola
        while(p!=0){
            ultima->siguiente = new Celda(p->elemento,0);   //Copiamos el elemento
            ultima = ultima->siguiente;                     //Avanzamos los punteros de las colas
            p = p->siguiente;
        }
    }else{
        primera = ultima = 0;               //Si no tiene elementos se inicializa todo a 0
    }
    num_elem = original.num_elem;
}

template <class T>
ColaMax<T>::~ColaMax(){
    Celda *aux;
    while(primera!=0){                  //Mientras queden elementos en la cola
        aux = primera;                  //Se copia el puntero 
        primera = primera->siguiente;   //Avanza primera
        delete aux;                     //Se borra la celda copiada
    }
}

template<class T>
ColaMax<T>& ColaMax<T>::operator= (const ColaMax<T> & otra){
    Celda *p;

    if(this != &otra){						//Comprobamos si ambos objetos son el mismo, en tal caso se devuelve él mismo
        while(primera!=0){					//Procedemos al borrado de la cola *this
            p = primera;					
            primera = primera->siguiente;
            delete p;
        }
		if(otra.primera!=0){				//Si la otra cola tiene elementos
			p = otra.primera;				//Copiamos el puntero inicial de la cola
			primera = ultima = new Celda(p->elemento, 0);	//Reservamos el primer nodo de la cola
			p = p->siguiente;				//Avanzamos el puntero 
			while(p!=0){					//Procedemos al copiado de la cola mientras queden elementos
				ultima->siguiente = new Celda(p->elemento, 0);	//Creamos un nuevo nodo
				ultima = ultima->siguiente;				//Actualizamos ultima
				p = p->siguiente;						//Avanzamos el puntero para continuar con la cola
			}
		}else
			primera=ultima=0;				//Si la otra cola esta vacia inicializamos a 0
		num_elem = otra.num_elem;			
    }
	return *this;					//Devolvemos el objeto para permitir encadenamiento
}

template<class T>
void ColaMax<T>::poner(const Elemento & elem){
    Celda * aux = new Celda(elem, 0);           // Creamos el nuevo nodo a introducir
    if(primera==0){                             // Si la cola esta vacía 
        primera = ultima = aux;                 // Inicializamos todo al nodo introducido
    }else{                                      // En caso contrario
        ultima->siguiente = aux;                // Enlazamos el puntero siguiente de ultima al nuevo nodo
        ultima = aux;                           // Actualizamos ultima al nuevo nodo
    }
    num_elem++;                                 // Aumentamos el numer de elementos de la cola
}

template<class T>
void ColaMax<T>::quitar(){
    assert(primera!=0);
    Celda<T> *aux = primera;
    primera = primera->siguiente;
    delete aux;
    if (primera==0)
        ultima = 0;
    num_elem--;
}


