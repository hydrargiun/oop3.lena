#include <string>
namespace oop3 {
    class alphabet {
    private:
        char* alf{};
        int size;
        static const int QUOTA = 10;
        std::string name;
    public:
        alphabet();
        ~alphabet(){delete [] alf;};
        explicit alphabet(std::string);
        alphabet(std::string, char*);
        alphabet(std::string,const alphabet&);
        int findchar(char c);
        int findchar_pos(char c);
        alphabet &Set_char(char);
        alphabet& operator += (alphabet& );
        friend std::istream& operator >> (std::istream& in, alphabet& );
        friend std::ostream& operator << (std::ostream& out, const alphabet& );
        std::string encoder(std::string ,int);
        std::string decoder(std::string ,int);
        alphabet &operator =(const alphabet &);



    };


}

