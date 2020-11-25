
#include <iostream>
#include <map>
#include "getnum.h"
#include "dialog.h"
#include "alphabet.h"


namespace oop3 {

int first(std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur ) {
    std::cout << "Введите название алфавита" << std::endl;
    std::string  name;
    std::cin >> name;
    std::map<std::string, alphabet> ::iterator t1;

    if((t1 = alftable.find(name))!= alftable.end()){
        std::cout << "name is used";

    }
    else{
        alphabet alf(name);
        alftable.insert(make_pair(name, alf));
        cur = alftable.find(name);
    }

}


int third(std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur ) {
    if (alftable.size() > 0) {
        std::cout << cur->second;
    } else{
        std::cout << "no alfa";
    }
}
int forth (std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur ) {
std::cout << "Введите букву" << std::endl;
char buf;
std::cin >> buf;
cur->second = cur->second.Set_char(buf);


}
int five(std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur ){
    std::cout << "Введи имя алфавита " << std::endl;
    std::string  name;
    std::cin >> name;
    std::map<std::string, alphabet> ::iterator t1;
    if((t1 = alftable.find(name)) != alftable.end()) {
        std::cout << "name is wrong" << std::endl;
    }
    else{
        std::cout << "Введите строку" << std::endl;
        char buf[100] = "";
        std::cin >> buf;
        alphabet alf(name,buf);
        alftable.insert(make_pair(name, alf));
        cur = alftable.find(name);
    }


}
int second(std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur ) {
    std::cout << "Введите имя " << std::endl;
    std::string  name;
    std::cin >> name;
    std::map<std::string, alphabet> ::iterator t1;
    if((t1 = alftable.find(name)) != alftable.end()) {
        std::cout << "name is used" <<std::endl;
    }
    else {
        alphabet alf(name);
        std::cin >> alf;
        alftable.insert(make_pair(name, alf));
        cur = alftable.find(name);
    }
}

int six(std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur) {
    std::cout << " Введите имя первого алфавита"<<std::endl;
    std::string  name1;
    std::cin >> name1;
    std::cout << " Введите имя второго алфавита"<<std::endl;
    std::string  name2;
    std::cin >> name2;

    std::map<std::string, alphabet> ::iterator t1, t2;
    if(((t1 = alftable.find(name1)) != alftable.end()) && ((t2 = alftable.find(name2)) != alftable.end())){
        t1->second += t2->second;
    }
    else {
        std::cout << "wrong names";
        throw std::invalid_argument("wrong input");
    }
}
int seven(std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur ){

    std::cout << "Введи строку" << std::endl;
    std::string  str;
    std::cin >>str;
    std::cout << "Введи n" << std::endl;
    int n;
    n = getNum<int>();
    std::cout<< "Encoded string  ->  "<< cur->second.encoder(str,n)<<"\n";

}
int eight(std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur ){

    std::cout << "Введи строку" << std::endl;
    std::string  str;
    std::cin >>str;
    std::cout << "Введи n" << std::endl;
    int n;
    n = getNum<int>();
    std::cout<< "Decoded string  ->  "<< cur->second.decoder(str,n)<<"\n";

}
int nine(std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur ){

    std::cout << "Введит букву"<< std::endl;
    char a;
    std::cin >> a;
    if(cur->second.findchar(a)){
        std::cout << "Yes"<< std::endl;
    }
    else
        std::cout << "No"<< std::endl;
}
int ten(std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur ){
    std::cout << "Введите имя " << std::endl;
    std::string  name;
    std::cin >> name;
    std::map<std::string, alphabet> ::iterator t1;
    if((t1 = alftable.find(name)) != alftable.end()) {
        std::cout << "name is used" <<std::endl;
    }
    else {
        alphabet newalf;
        std::cout << "Введите имя инцилизатора" << std::endl;
        std::string  name2;
        std::cin >> name2;
        std::map<std::string, alphabet> ::iterator t2;
        if((t2 = alftable.find(name2)) == alftable.end()) {
            std::cout << "name is wrong" <<std::endl;
        }
        else{
            alphabet newalf(name,t2->second);
            alftable.insert(make_pair(name, newalf));
            cur = alftable.find(name);
        }

    }
}
int eleven(std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur ){
    std::cout << "Введите имя " << std::endl;
    std::string  name;
    std::cin >> name;
    std::map<std::string, alphabet> ::iterator t1;
    if((t1 = alftable.find(name)) == alftable.end()) {
        std::cout << "name is wrong" <<std::endl;
    }
    else {
        cur = t1;
    }

}

int twelve(std::map<std::string,alphabet>&alftable,std::map<std::string,alphabet>::iterator &cur) {
    std::cout << " Введите имя первого алфавита"<<std::endl;
    std::string  name1;
    std::cin >> name1;
    std::cout << " Введите имя второго алфавита"<<std::endl;
    std::string  name2;
    std::cin >> name2;

    std::map<std::string, alphabet> ::iterator t1, t2;
    if(((t1 = alftable.find(name1)) != alftable.end()) && ((t2 = alftable.find(name2)) != alftable.end())){
        t1->second = t2->second;
    }
    else {
        std::cout << "wrong names";
        throw std::invalid_argument("wrong input");
    }
}





}
