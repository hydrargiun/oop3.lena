
#include "Multiseat.h"
namespace oop4 {
        Multiseat::Multiseat(int a, int b,int p) :places(p), free_places(p), people(0) {
            this->Set_first(a, b, "Multiseat");

            for(int i = 0; i < 4; i++){
                this->hum->time = 0;
                this->hum->date = 0;
                this->hum->number= 0;
            }

    }

    Room &Multiseat::Take(int d, int t, int p) {
        if (p <= free_places) {
            for (int i = 0; i < p; i++) {
                hum[i].number = i + 1;
                hum[i].date = d;
                hum[i].time = t;
            }
            free_places += p;
            this->Set_busy(1);
            people = places  - free_places;
            if(people == places){
                this->Set_busy(1);
            }

        }
        return *this;
    }

    Room &Multiseat::Checkout(int p) {
            this->people = people - p;
            this->free_places = free_places + p;
            for (int i = 0; i < p; i++){
                hum[i].date = 0 ;
                hum[i].time = 0 ;
                hum[i].date = 0 ;
            }
       if (free_places == places)
           this->Set_busy(0);
    }


    Multiseat::Multiseat() = default;


}