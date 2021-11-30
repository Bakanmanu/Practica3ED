/**
 * @file colaMax.h
 * @brief Fichero cabecera del TDA ColaMax
 *
 * Gestiona una secuencia de elementos de manera FIFO con la especificación 
 * del máximo elemento de dicha secuencia
 * 
 * @author Manuel Zafra y Claudia Salado
 */

#ifndef __ColaMax_H__
#define __ColaMax_H__

#include <cassert>


/**
 * @brief Estructura de los elementos que tendran las celdas de la colaMax
 * @param valor Valor del elemento de la celda
 * @param maximo Valor maximo de la cola
 */
struct Elemento{
    T valor;
    T maximo;

    /**
     * @brief Constructor por defecto
     */
    Elemento(): valor(0), maximo(0){}

    /**
     * @brief Constructor por parametros
     * @param val Contenido de valor 
     * @param max Contenido de maximo
     */
    Elemento(const T & val, const T & max): valor(val), maximo(max){}

    /**
     * @brief Constructor de copia
     * @param original Elemento del que se hara la copia
     */
    Elemento(const Elemento & original):valor(original.valor), maximo(original.maximo){} 
    
    /**
     * @brief Sobrecargar del operador "<<" para imprimir los valores del elemento
     * @param os 
     * @param elem 
     * @return ostream& 
     */
    friend ostream& operator<<(ostream& os, const Elemento& elem){
        os << "[" << elem.valor << ", " << elem.maximo << "] ";
        return os;
    }
    
};

/**
 * @brief T.D.A. ColaMax
 *
 */
template <class T>
class ColaMax{
    private:
        
        /**
         * @brief Estructura de las celdas de la colaMax
         * @param elemento Atributo de la celda que almacena el valor y el maximo
         * @param siguiente Puntero hacia la siguiente celda en la cola
         */
        struct Celda{
            Elemento elemento;  
            Celda *siguiente;

            /**
             * @brief Constructor por defecto de la celda
             */
            Celda() : siguiente(0){}
            /**
             * @brief Constructor por parametros
             * @param elem Valor que tendra el elemento de la celda
             * @param sig Puntero a la siguente celda
             */
            Celda(const Elemento & elem, Celda * sig): elemento(elem), siguiente(sig){}
        };
 
        Celda * primera;
        Celda * ultima;
        int num_elem;

    public:
        // -------------------- CONSTRUCTORES -------------------------
        /**
         * @brief Constructor por defecto
         * 
         */
        ColaMax() : primera(0), ultima(0), num_elem(0){
        }
        /**
         * @brief Constructor de copia
         * @param original ColaMax de la que se hará la copia
         */
        ColaMax(const ColaMax<T> & original);

        // -------------------- DESTRUCTOR ---------------------------
        /**
         * @brief Destroy the Cola Max object
         * 
         */
        ~ColaMax();

        // -------------------- OTRAS FUNCIONES ------------------------
        /**
         * @brief Operador de asignacion para una cola max
         * @param otra
         */
        ColaMax& operator= (const ColaMax<T> & otra);
        
        /**
         * @brief Comprueba si la cola está vacia
         * 
         * @return true si esta vacia
         * @return false si no esta vacia
         */
        bool vacia() const{
            return num_elem==0;
        }

        /**
         * @brief Devuelve el elemento del frente de la colaMax
         * 
         * @return T& 
         */
        Elemento& frente(){
            assert(primera!=0);
            return primera->elemento;
        }

        /**
         * @brief Añade un elemento al final de la cola en ultima
         * 
         * @param elem Elemento que se añade a la cola
         */
        void poner(const Elemento & elem);

        /**
         * @brief Quita el elemento del frente de la cola
         */
        void quitar();

        /**
         * @brief Get del numero de elementos en la cola
         * 
         * @return int 
         */
        int getNum_elem(){
            return num_elem;
        }

        /**
         * @brief Funcion para obtener el maximo de la cola 
         * 
         * @return T& 
         */
        T& getMaximo();
};








#endif