#ifndef OOP4_LENA_ROOM_H
#define OOP4_LENA_ROOM_H
#include <string>
namespace oop4 {
    class Room {
    private:
        int num;
        int busy;
        int cost_per_day;
        std::string type;

    protected:
        friend std::ostream& operator << (std::ostream& out, const Room&);
        virtual std::ostream& show(std::ostream&)const = 0;
        virtual Room& Take(int d, int t, int p) = 0;
        virtual Room& Checkout(int p) = 0;
    public:
         Room &Set_first(int n, int c, const std::string&);
         Room &Set_busy(int);
         int Get_busy() const;
         int Get_number() const ;
    };
}

#endif