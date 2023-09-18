
#include <iostream>
#include <cstdlib>
#include <random>


#include "Nodo.h"
Nodo::Nodo() {
    
    this->data = numAleatorio();
    this->next = nullptr;
    this->prev = nullptr;
    this->cientifico = cientificoAleatorio();
    this->evento = 'N';
}

char Nodo::cientificoAleatorio() const {
  std::random_device rd;  // Dispositivo de generación de números aleatorios
  std::mt19937 gen(rd()); // Motor Mersenne Twister
  std::uniform_int_distribution<int> distribucionC(1, 2);
  int n = distribucionC(gen);
  if (n == 1) {
    return 'E';
  } else {
    return 'R';
  }
}

int Nodo::numAleatorio() {
  std::random_device rd;  // Dispositivo de generación de números aleatorios
  std::mt19937 gen(rd()); // Motor Mersenne Twister
  std::uniform_int_distribution<int> distribucion(0, 100); // Definir la distribución
  int n = distribucion(gen);
  return n;
}