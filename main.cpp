#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>//otsleg
// #define _WIN32_WINNT 0x0A00
#include <windows.h>

using namespace std;

#include "lib_game/settings_console.cpp"
#include "lib_game/intro.cpp"
// подрубим файлус для настройки консоли т.к оно тут не надо (совсем)



int main(){
    // Тут мы вызываем изменение настроек консоли
    Console_setting();
    // Тут мы вызываем интро
    intro();

    int gggggg;
    cin >> gggggg;
}

