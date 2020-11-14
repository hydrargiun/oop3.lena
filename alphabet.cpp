#include "alphabet.h"
#include <string>
#include <iostream>
#include <set>
namespace oop3 {
    alphabet::alphabet() {    //сеттер если значение не прередали
        this->name = "";
        this->size = 0;
    }

  alphabet::alphabet(std::string name) {
      this->name = name;
      this->size = 0;

  }


    alphabet::alphabet(std::string name, char buf[] ){
        std::set<char> buf2;
        for(int i = 0; buf[i]!= '\0'; i++){
            buf2.insert(buf[i]);
        }
        int j =0;
        for(auto z : buf2){
            this->alf[j] = z;
            j++;
        }
        this->name = name;
        this->size = buf2.size();
    }




    std::ostream& operator << (std::ostream& out, const alphabet& alf){
        std::cout << " Имя алфавита -> "<<alf.name <<std::endl;
        for (int i = 0; i <alf.size; i++) {
            out << alf.alf[i];
            out << " ";
        }

        return out;

    }

    int alphabet::findchar(char c){
        for (int i = 0; i < this->size; i++ ){
            if(this->alf[i] == c ){
                return 1;
            }
        }
        return 0;


    }
    alphabet &alphabet::Set_char(char buf){
        if (!(findchar(buf))){
            this->alf[this->size] = buf;
            this->size +=1;
            return *this;
        }
        else {
            return *this;
        }
    }
    std::istream& operator >> (std::istream& in, alphabet& alf) {
        std::cout << "Введите размер"<<std::endl;
        int num;
        in >> num;
        if (num < 1 || num> 100) {
            throw std::invalid_argument("invalid number!");
        }
        std::cout << "Введите алфавит"<<std::endl;
        std::set<char> buf2;
        for (int i = 0; i < num; i++) {
            char a;
            in >> a;
            buf2.insert(a);
            }
          int i =0;
           for( auto x: buf2){
               alf.alf[i] = x;
               i++;
           }
           alf.size = buf2.size();

        return in;
    }
    alphabet& alphabet::operator += (alphabet& alf ){
        std::set<char> buf2;
        if (alf.size == 0){
            throw  std::invalid_argument("buf not found");
        }

        for (int i =0; i< alf.size; i++ ){
            buf2.insert(alf.alf[i]);
        }
        for (int i =0; i< this->size; i++ ){
            buf2.insert(this->alf[i]);
        }
        if(buf2.size() < 100){
            int i =0;
            for (auto x: buf2){
                this->alf[i] = x;
                i++;
            }
            this->size= buf2.size();

        }
        return *this;
    }

    int alphabet::findchar_pos(char c){
        for (int i = 0; i < this->size; i++ ){
            if(this->alf[i] == c ){
                return i;
            }
        }
        return -1;


    }

    std::string alphabet::encoder (std::string str , int num){
        for(int i =0; i< str.size(); i++){
            int pos =0 ;
            if(( pos = this->findchar_pos(str[i])) < 0) {
                throw  std::invalid_argument("wrong text");
            }
            else
            {
                pos =pos + num;
                std::cout <<"pos = "<< pos;
                std::cout << "sz = "<<this->size <<"\n";

                if(pos > this->size -1) {
                    pos = ((pos - (this->size -1)) -1);
                }


                str[i] = this->alf[pos];
            }

        }

        return str;
    }
    std::string alphabet::decoder (std::string str , int num){
        for(int i =0; i< str.size(); i++){
            int pos =0 ;
            if(( pos = this->findchar_pos(str[i])) < 0) {
                throw  std::invalid_argument("wrong text");
            }
            else
            {
                pos =pos - num;
                std::cout <<"pos = "<< pos;
                std::cout << "sz = "<<this->size <<"\n";

                if(pos < 0) {
                    pos =(this->size + pos);
                }


                str[i] = this->alf[pos];
            }

        }

        return str;
    }





}