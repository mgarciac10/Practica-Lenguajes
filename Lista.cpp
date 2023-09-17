
#include "Lista.h"
#include <iostream>
using namespace std;

Lista::Lista() {
  this->head = nullptr;
}

void Lista::insertarCola(Nodo *nodo) {
  // Si la lista está vacía, el nuevo nodo se convierte en la cabeza.
  if (this->head == nullptr) {
    this->head = nodo;
  } else {
    Nodo *temp = this->head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = nodo;
    nodo->prev = temp;
  }
}

void Lista::crearEventos() {
  for (int i = 0; i < 22; i++) {
    Nodo *nodo = new Nodo();
    insertarCola(nodo);
  }
}

void Lista::display() {
  if (this->head == nullptr) {
    cout << "La lista está vacía" << endl;
  } else {
    Nodo *temp = this->head;
    // iterate linked list
    while (temp != nullptr) {
      // Mostrar el valor del nodo
      cout << "[" << temp->data << "|" << temp->cientifico << "]" << "-> ";
      // Visita el siguiente nodo
      temp = temp->next;
    }
    cout << endl;
  }
}

void Lista::imprimirEvento(Nodo *nodo) {
  cout << "[" << nodo->data << "|" << nodo->cientifico << "|" << nodo->evento << "]" << "-> ";
}

bool Lista::primo(int data)
{
  if (data <= 1) {
    return false;
  }
  else {
    for (int i = 2; i * i <= data; i++) {
      if (data % i == 0) {
        return false;
        break;
      }
    }
  }
  return  true;
}

bool Lista::coprimos(int dataA, int dataC) {

  // algoritmo de Euclides.
  int a = dataA;
  int b = dataC;
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }

  if (a==1) {
    return true;
  } else {
    return false;
  }
}

void Lista::eventos() {
  bool eventoA = false;
  bool eventoB = false;
  bool eventoC = false;
  Nodo *A = nullptr;
  Nodo *B = nullptr;

  Nodo *temp = this->head;
  while (temp != nullptr) {
    if (primo(temp->data) && (temp->cientifico == 'E') && !eventoA) {
      eventoA = true;
      temp->evento = 'A';
      A = temp;
      cout << "Se ha producido un evento de tipo A: " << temp->data << endl;
      imprimirEvento(A);
      cout << endl;
      cout<< endl;
      temp = temp->next;
      continue;
    }
    if (eventoA && primo(temp->data) && !eventoB) {
      eventoB = true;
      temp->evento = 'B';
      B = temp;
      cout << "Se ha producido un evento de tipo B: " << temp->data << endl;
      imprimirEvento(A);
      imprimirEvento(B);
      cout << endl;
      cout<< endl;
      temp = temp->next;
      continue;
    }
    
    if (eventoB && coprimos(A->data,temp->data) && !eventoC) {
      eventoC = true;
      temp->evento = 'C';
      cout << "Se ha producido un evento de tipo C: " << temp->data << endl;
      if (primo(temp->data) && B->cientifico != 'R') {
        cout << "Se ha viajado en el tiempo y se han compartido datos" << endl;
      } else {
        cout << "Se ha viajado en el tiempo y no se han compartido datos" << endl;
      }
      imprimirEvento(A);
      imprimirEvento(B);
      imprimirEvento(temp);
      cout << endl;
      cout<< endl;
      temp = temp->next;
      eventoA = false;
      eventoB = false;
      eventoC = false;
      A = nullptr;
      B = nullptr;
      continue;
    }
    temp = temp->next;
  }
}