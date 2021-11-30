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
#include "pila.h"
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