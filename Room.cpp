#include "Room.h"
#include <iostream>
#include <string>
namespace oop4 {




    std::ostream& operator << (std::ostream& out, const Room& room){
        out << "Room num -> ";
        out <<" "<< room.num<<"\n";
        out << "Room type -> ";
        out <<" "<< room.type<<"\n";
        (room.busy == 1)?(out << "busy\n"):(out << "free\n");
        out << "Room cost -> ";
        out <<" "<<room.cost_per_day<<"\n";
        room.show(out);
        return out;

    }





    int Room::Get_number() const {
        return this->num;
    }

    Room &Room::Set_first(int n, int c, const std::string& t)  {
        this->num = n;
        this->cost_per_day = c;
        this->busy = 0;
        this->type = t;
        return *this;
    }
    Room &Room::Set_busy(int b)  {
        this->busy = 0;
        return *this;
    }

    int Room::Get_busy() const{
        return this->busy;
    }


}
