#include <iostream>
#include <map>
#include "alphabet.h"
#include "getnum.h"

namespace oop3{
     void dialog() {
         std::map<std::string, alphabet> alftable;
         while (true) {
             std::cout << "" << std::endl;
             std::cout << "0. Выход" << std::endl;
             std::cout << "1. Создать пустой алфавит " << std::endl;
             std::cout << "2. Ввод алфавита по размеру" << std::endl;
             std::cout << "3. Вывод алфавита" << std::endl;
             std::cout << "4. Добавить букву в алфавит" << std::endl;
             std::cout << "5. Ввод алфавит по строке" << std::endl;
             std::cout << "6. Слияние" << std::endl;
             std::cout << "7. Encoder " << std::endl;
             std::cout << "8. Decoder " << std::endl;

             int pt;
             pt = getNum<int>();
             if (pt < 0 || pt > 9){
                 std::cout << "wrong number"<< std::endl;
                 throw std::invalid_argument("wrong input");
                 continue;
             }
             if (pt == 0) {
                 break;
             }

             if (pt == 1) {
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
                 }

             }


             if (pt == 3) {
                 std::cout << "Введите имя " << std::endl;
                 std::string  name;
                 std::cin >> name;
                 std::map<std::string, alphabet> ::iterator t1;
                 if((t1 = alftable.find(name))!= alftable.end()) {
                     std::cout << t1->second;
                 }
                 else {
                     std::cout << "name is not found";
                 }

             }
             if (pt == 4) {
                 std::cout << "Введи имя алфавита " << std::endl;
                 std::string  name;
                 std::cin >> name;
                 std::map<std::string, alphabet> ::iterator t1;
                 if((t1 = alftable.find(name))!= alftable.end()) {
                     std::cout << "Введите букву" << std::endl;
                     char buf;
                     std::cin >> buf;
                     t1->second = t1->second.Set_char(buf);

                 }

             }
             if (pt == 5){
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
                 }


             }
             if (pt == 2) {
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
                 }
             }

             if (pt == 6) {
                 std::cout << " Введите имя первого алфавита"<<std::endl;
                 std::string  name1;
                 std::cin >> name1;
                 std::cout << " Введите имя второго алфавита"<<std::endl;
                 std::string  name2;
                 std::cin >> name2;

                 std::map<std::string, alphabet> ::iterator t1, t2;
                 if(((t1 = alftable.find(name1)) != alftable.end()) && ((t2 = alftable.find(name2)) != alftable.end())){
                     t1->second+=t2->second;
                 }
                 else {
                     std::cout << "wrong names";
                     throw "wrong names to add";
                 }
             }
             if(pt == 7){
                 std::cout << "Введи имя алфавита " << std::endl;
                 std::string  name;
                 std::cin >> name;
                 std::map<std::string, alphabet> ::iterator t1;
                 if((t1 = alftable.find(name)) == alftable.end()) {
                     std::cout << "name is wrong" << std::endl;
                 }
                 else
                 {
                     std::cout << "Введи строку" << std::endl;
                     std::string  str;
                     std::cin >>str;
                     std::cout << "Введи n" << std::endl;
                     int n;
                     std::cin >>n;
                     std::cout<< "Encoded string  ->  "<< t1->second.encoder(str,n)<<"\n";
                 }

             }
             if(pt == 8){
                 std::cout << "Введи имя алфавита " << std::endl;
                 std::string  name;
                 std::cin >> name;
                 std::map<std::string, alphabet> ::iterator t1;
                 if((t1 = alftable.find(name)) == alftable.end()) {
                     std::cout << "name is wrong" << std::endl;
                 }
                 else
                 {
                     std::cout << "Введи строку" << std::endl;
                     std::string  str;
                     std::cin >>str;
                     std::cout << "Введи n" << std::endl;
                     int n;
                     std::cin >>n;
                     std::cout<< "Decoded string  ->  "<< t1->second.decoder(str,n)<<"\n";
                 }

             }


         }
     }
}
