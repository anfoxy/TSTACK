#include <iostream>
#include "TStack.h"

void main() {
  TStack a(10);
  a.Put(2);
  a.Put(10);
  a.Print();
  getchar();
  getchar();
}