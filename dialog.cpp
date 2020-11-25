#include <iostream>
#include <map>
#include "getnum.h"
#include "dialog.h"
#include "helper.h"
namespace oop3{
    int (*fptr[])(std::map<std::string,alphabet>&, std::map<std::string,alphabet>::iterator &) = {NULL, first,second, third, forth, five, six, seven, eight, nine, ten,eleven, twelve};
     void dialog() {
         std::map<std::string, alphabet> alftable;
         std::map<std::string, alphabet>::iterator cur;
         if (alftable.size() > 0) {
             std::cout << "\n";
             std::cout << "current alf is -> ";
             std::cout << cur->first;
         }
         while(true) {
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
                 if (!fptr[pt](alftable,cur)){
                     break;
                 }

         }
     }



}
