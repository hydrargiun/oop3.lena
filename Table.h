#ifndef OOP4_LENA_TABLE_H
#define OOP4_LENA_TABLE_H
#include <map>
#include <vector>
#include "Room.h"
namespace oop4 {
    class Table {
    private:
        class TMap{
        public:
            std::map<int,Room*> all;
            std::map<int, Room*> free;
        };
        TMap map_all;
    public:
        Table();
        void Display();
        Table &Add(Room *);
        Table &Del(Room *);



};

}

#endif
