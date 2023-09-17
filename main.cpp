#include <iostream>
#include "Lista.h"
#include "Nodo.h"

using namespace std;

int main() {
  Lista *puntero = new Lista();

  puntero->crearEventos();
  puntero->eventos();
  puntero->display();

  return 0;
}
