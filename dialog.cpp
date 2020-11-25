#include <iostream>
#include <map>
#include "alphabet.h"
#include "getnum.h"

namespace oop3{
     void dialog() {
         std::map<std::string, alphabet> alftable;
         std::map<std::string, alphabet>::iterator cur;
         while (true) {
             if (alftable.size() > 0) {
                 std::cout<< "\n";
                 std::cout << "current alf is -> " ;
                 std::cout << cur->first;
             }
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
             std::cout << "9. Проверка алфавита на наличие буквы " << std::endl;
             std::cout << "10. инцилизация другим" << std::endl;
             std::cout << "11. Смена текущего алфавита" << std::endl;
             std::cout << "12. Приравнять" << std::endl;
             int pt;
             pt = getNum<int>();
             if (pt < 0 || pt > 13){
                 std::cout << "wrong number"<< std::endl;
                 throw std::invalid_argument("wrong input");
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
                     cur = alftable.find(name);
                 }

             }


             if (pt == 3) {
                 if (alftable.size() > 0) {
                     std::cout << cur->second;
                 } else{
                     std::cout << "no alfa";
                 }
             }
             if (pt == 4) {
                     std::cout << "Введите букву" << std::endl;
                     char buf;
                     std::cin >> buf;
                     cur->second = cur->second.Set_char(buf);


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
                     cur = alftable.find(name);
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
                     cur = alftable.find(name);
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
                     t1->second += t2->second;
                 }
                 else {
                     std::cout << "wrong names";
                     throw std::invalid_argument("wrong input");
                 }
             }
             if(pt == 7){

                     std::cout << "Введи строку" << std::endl;
                     std::string  str;
                     std::cin >>str;
                     std::cout << "Введи n" << std::endl;
                     int n;
                     n = getNum<int>();
                     std::cout<< "Encoded string  ->  "<< cur->second.encoder(str,n)<<"\n";

             }
             if(pt == 8){

                     std::cout << "Введи строку" << std::endl;
                     std::string  str;
                     std::cin >>str;
                     std::cout << "Введи n" << std::endl;
                     int n;
                     n = getNum<int>();
                     std::cout<< "Decoded string  ->  "<< cur->second.decoder(str,n)<<"\n";

             }
             if(pt == 9){

                     std::cout << "Введит букву"<< std::endl;
                     char a;
                     std::cin >> a;
                     if(cur->second.findchar(a)){
                         std::cout << "Yes"<< std::endl;
                     }
                     else
                         std::cout << "No"<< std::endl;
                 }
             if (pt == 10){
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
             if (pt == 11){
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
             if (pt == 12) {
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

         for (auto x: alftable ){
             delete &x.second;
         }
     }
}
