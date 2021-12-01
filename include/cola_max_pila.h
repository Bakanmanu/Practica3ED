/**
 * @file cola_max_pila.h
 * @brief Fichero cabecera del TDA cola_max_pila
 * Gestiona una secuencia de elementos de manera FIFO implementado con Pilas (Estructura LIFO)
 * con la especificación del máximo elemento de la secuencia. 
 * 
 * @author Claudia Salado Méndez
 * @author Manuel Zafra Mota
 * 
 */

#ifndef __Cola_max_Pila_H__
#define __Cola_max_Pila_H__

#include <iostream>
#include <cassert>
// #include "pila.h"
using namespace std;

/**
 * @brief Estructura de los elementos que tendran las pilas de la cola_max_pila
 * @param ele Valor del elemento de la cola
 * @param maximo Valor maximo de la cola
 */
struct Elemento{
    int ele;
    int maximo;

    /**
     * @brief Constructor por defecto
     */
    Elemento(): ele(0), maximo(0){}

    /**
     * @brief Constructor por parametros
     * @param val Contenido de ele 
     * @param max Contenido de maximo
     */
    Elemento(const int val, const int max): ele(val), maximo(max){}

    /**
     * @brief Constructor de copia
     * @param original Elemento del que se hara la copia
     */
    Elemento(const Elemento & original):ele(original.ele), maximo(original.maximo){} 
    
    /**
     * @brief Sobrecargar del operador "<<" para imprimir los valores del elemento
     * @param os 
     * @param elem 
     * @return ostream& 
     */
    friend ostream& operator<<(ostream& os, const Elemento& elem){
        os << "[" << elem.ele << ", " << elem.maximo << "] ";
        return os;
    }
    
};

//Uso de la Implementacion del TDA Pila proporcionada por el profesorado

template <class T>
class Pila{
  private:
    struct Celda {
      T elemento;        ///< Elemento de informaci�n.
      Celda * siguiente; ///< Puntero al siguiente nodo.

      /**
       * @brief Constructor por defecto
       */
      Celda() : siguiente(0){
      }
      /**
       * @brief Constructor con par�metros
       * @param elem Elemento de informaci�n.
       * @param sig Puntero al siguiente nodo.
       */
      Celda(const T & elem, Celda * sig): elemento(elem), siguiente(sig){
      }
    };

    Celda * primera; ///< Puntero al primer nodo de la lista.
    int num_elem;    ///< N�mero de elementos de la pila.

  public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    Pila(): primera(0), num_elem(0){
    }
    /**
     * @brief Constructor de copias
     * @param otra La pila de la que se har� la copia.
     */
    Pila(const Pila<T> & otra);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Pila();
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignaci�n
     * @param otra La pila que se va a asignar.
     */
    Pila& operator= (const Pila<T>& otra);
    /**
     * @brief Comprueba si la pila est� vac�a
     */
    bool vacia() const{
      return (primera==0);
    }
    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    T& tope (){
      assert(primera!=0);       //Si la pila est� vac�a, abortar
      return primera->elemento; //Devuelve el elemento del tope de la pila
    }
    /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
    const T & tope () const{
      assert(primera!=0);       //Si la pila est� vac�a, abortar
      return primera->elemento; //Devuelve el elemento del tope de la pila
    }
    /**
     * @brief A�ade un elemento "encima" del tope de la pila
     * @param elem Elemento que se va a a�adir.
     */
    void poner(const T & elem);
    /**
     * @brief Quita el elemento del tope de la pila
     */
    void quitar();
    /**
     * @brief Devuelve el n�mero de elementos de la pila
     */
    int num_elementos() const{
      return num_elem;
    }
};


/**
 * @brief Implementacion del TDA Cola_max usando pilas
 * @param pila Un objeto del Pila con plantilla que utilizará el tipo de dato Elemento descrito anteriormente
 * @param num_elem Numero de elementos que contiene la cola, si es igual a 0 significa que esta vacía.
 *
 * @author Manuel Zafra Mota
 * @author Claudia Salado Méndez
 * 
 */

class cola_max_pila{
    private:
		Pila<Elemento> pila;
		int num_elem;
	public:
        /**
         * @brief Constructor por defecto de la cola
         */
		cola_max_pila();
        /**
         * @brief Constructor de copia de la cola
         * @param otra cola_max_pila de la que se hará la copia
         */
		cola_max_pila(const cola_max_pila &otra);


        /**
         * @brief Destructor de cola_max_pila
         *  
         */
        ~cola_max_pila();
		/**
		 * @brief Introduce un valor en la cola,
         * convirtiendolo previamente en un objeto de la estructura Elemento
         * y asignandole el maximo correspondiente 
		 * @param valor Dato a introducir en la cola
		 */
		void poner(const int valor);

        /**
         * @brief Elimina el valor del frente de la cola
         */
		void quitar();

        /**
         * @brief Devuelve el dato de tipo Elemento del frente de la cola
         * @return Elemento 
         */
		Elemento frente();
        /**
         * @brief Devuelve el entero @a ele del tipo de datos Elemento
         * del frente de la cola
         * @return int
         */
        int frente_ele();

        /**
         * @brief Devuelve el entero @a maximo del tipo de datos Elemento
         * del frente de la cola
         * 
         * @return int 
         */
		int frente_max();
        /**
         * @brief Devuelve si la cola esta vacia o no
         * 
         * @return true en caso de que esté vacia
         * @return false en caso de contener algun elemento
         */
		bool vacia();
        /**
         * @brief Devuelve el numero de elementos que contiene la cola 
         * @return @a num_elem
         */
		int num_elementos();

        /**
         * @brief Imprime en pantalla los valores de la cola
         * 
         */
        void mostrar_cola();
};

// #include <cola_max_pila.cpp>

#endif      //__cola_max_pila__