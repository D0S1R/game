// ! g++ main.cpp -IE:/git/game/lib_game -o walker

// TODO: 
// -I - путь, в которых находятся заголовочные файлы
// -o - как называется скомпилированный файл
// 
// .lib - windows lib   (хранятся в системных папках)
// .a   - linux lib     (хранятся в данном случае в папках компилятора)
// .dll - W_dynamic lib (хранится могут и в системных папках и в папках компилятора)
// .so  - L_dynamic lib
// 
// lib  - библиотеки в двоичном коде, которые содержат определения функций, .h содержат объявления
// 

// ? Заголовок, в котором подключаются другие заголовки
#include "lib_game/includs_h.h"

using namespace std;

// TODO: Подключение ОБЪЯВЛЕННЫХ функций и/или переменных, макросов и т.д.
#include "lib_game/settings_console.hpp"
#include "lib_game/intro.hpp"
#include "lib_game/menu.hpp"

int main(){
    // Тут мы вызываем изменение настроек консоли
    Console_setting();
    // Тут мы вызываем интро
    intro();

    Sleep(230);
    system("CLS");
    menu();
    
    int gggggg;
    cin >> gggggg;
}

