#include <string>
namespace oop3 {
    class alphabet {
    private:
        char alf[100];
        int size;
        std::string name;
    public:
        alphabet();
        alphabet(std::string);
        alphabet(std::string, char []);
        void show();
        int findchar(char c);
        int findchar_pos(char c);
        alphabet &Set_char(char);
        alphabet& operator += (alphabet& );
        friend std::istream& operator >> (std::istream& in, alphabet& );
        friend std::ostream& operator << (std::ostream& out, const alphabet& );
        std::string encoder(std::string ,int);
        std::string decoder(std::string ,int);



    };


}

