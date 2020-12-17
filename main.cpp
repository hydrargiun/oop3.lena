#include <iostream>
#include "Table.h"
#include "Lux.h"
#include "Multiseat.h"
using namespace oop4;
int main() {
    Table tab;


    Lux c(1,1);
    tab = tab.Add(&c);
   // Multiseat a(3,2,4);
  //  tab = tab.Add(&a);

    tab.Display();

}
