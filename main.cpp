// ! g++ lib_game/intro.cpp main.cpp -IE:/git/game/lib_game -o walker

// TODO: 
// -I - путь, в которых находятся быблиотеки
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
#include "includs_h.h"

using namespace std;

// TODO: Подключение ОБЪЯВЛЕННЫХ функций и/или переменных, макросов и т.д.
#include "settings_console.h"
#include "intro.h"

int main(){
    // Тут мы вызываем изменение настроек консоли
    Console_setting();
    // Тут мы вызываем интро
    intro();

    int gggggg;
    cin >> gggggg;
}

