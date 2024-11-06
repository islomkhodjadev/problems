
/*

В коде сторонней библиотеки обнаружился баг. 
Вместо отсортированного массива строк библиотека возвращает массив случайно упорядоченных строк. 
К счастью, в каждую строку в случайной позиции библиотека записывает порядковый индекс – позицию, 
где строка должна быть в выходном массиве, например, "str2ing".

Ваша задача обработать баг библиотеки и написать функцию, которая:
- извлечёт индекс из строки;
- с помощью индекса расположит строку в нужной позиции.

*/


#include <iostream>
#include <unordered_map>
#include <sstream> 
#include <vector>
#include <cctype> 






int main() {
      std::string catalog;
      std::unordered_map<int, std::string> library;
      std::getline(std::cin, catalog, '\0');
      int index = 0;
      std::ostringstream  word;
      for (char c: catalog) {
        
        
        if(c == '\n') {
          library[index-1] = word.str();
          index = 0;
          word.str("");
          word.clear();
          
        } 
        else if(std::isdigit(c)) {
            
            index = index * 10 + (c - '0');
            
          
        } 
        else {
          word << c;
        }
        
      }
      
       if (!word.str().empty()) {
        library[index - 1] = word.str();
    }
    
      for (int i = 0; i< library.size(); i++) {
        for (char ch : library[i]) {
            std::cout << ch;
        }
        std::cout<<'\n';
      }
      
      return 0;
      
}
