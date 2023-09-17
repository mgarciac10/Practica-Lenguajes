
#ifndef Practica_Lista_H
#define Practica_Lista_H


#include "Nodo.h"

class Lista {
public: Nodo *head;
    Lista();
    void insertar(int value);
    void insertarCola(Nodo *nodo);
    void crearEventos();
    void display();
    bool primo(int data);
    bool coprimos(int dataA, int dataC);
    void eventos();
    void imprimirEvento(Nodo *nodo);
};


#endif //Practica_Lista_H
