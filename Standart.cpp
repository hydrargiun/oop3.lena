
#include <iostream>
#include "Standart.h"
namespace oop4{
          Standart::Standart(int a, int b) {
              this->Set_first(a, b, "Standart");
              this->Set_busy(0);
              date = 0;
              time = 0;
              people = 0;
          }

    std::ostream &Standart::show(std::ostream &out) const {
        out << "Amount of people ";
        out << this->people << "\n";
        (this->Get_busy() == 1) ? (out << "busy from " << date << "\n" << "busy for " << time << "\n") : (out
                << "not busy");
        return out;


    }

    Room &Standart::Take(int d, int t, int p) {
        this->Set_busy(1);
        date = d;
        time = t;
        people = p;
        return *this;

    }

    Room &Standart::Checkout(int p) {
       this->Set_busy(0);
       people = 0;
       date = 0;
       time = 0;
        return *this;
    }


    Standart::Standart() = default;







}
