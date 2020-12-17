#include <iostream>
#include "Lux.h"
namespace oop4{

    Lux::Lux(int n, int cost) {
        this->Set_first(n, cost, "Lux");
     people = 0;
     time = 0;
     date = 0;

    }


    Room &Lux::Checkout(int p) {
        this->people =0;
        this->Set_busy(0);
        this->time= 0;
        this->date = 0;
        return *this;

    }
    std::ostream &Lux::show(std::ostream &out) const {
        out << "Amount of people ";
        out << this->people <<"\n";
        (this->Get_busy() == 1)?(out << "busy from "<<date<<"\n"<<"busy for "<<time<<"\n"):(out <<"not busy");
        return out;


    }

    Room &Lux::Take(int d, int t, int p) {
        this->date = d;
        this->time = t;
        this->Set_busy(1);
        people = p;
    }


}
