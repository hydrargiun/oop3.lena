#include <iostream>
#include "Table.h"


namespace oop4 {

    void Table::Display() {
       for (auto it = map_all.all.begin(); it != map_all.all.end(); ++it)
        {
            std::cout <<*it->second;
            std::cout<<std::endl;
            std::cout<<std::endl;
            std::cout<<std::endl;

        }
    }

    Table &Table::Add(Room *room) {
        map_all.all.insert(std::make_pair(room->Get_number(), room));
        map_all.free.insert(std::make_pair(room->Get_number(), room));
        return *this;
    }

    Table::Table() = default;


}
