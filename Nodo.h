
#ifndef Practica_NODO_H
#define Practica_NODO_H


class Nodo {
public: int data; char cientifico; char evento;
    Nodo *next;
    Nodo *prev;
    Nodo();
    char cientificoAleatorio() const;
    int numAleatorio();
};


#endif //Practica_NODO_H
