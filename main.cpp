#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>//otsleg
// #define _WIN32_WINNT 0x0A00
#include <windows.h>

using namespace std;


int main(){
    CONSOLE_FONT_INFOEX cfi;        // структура данных шрифта
    cfi.cbSize = sizeof cfi;        // на чс, размер объекта типа данных CONSOLE_FONT_INFOEX
    cfi.nFont = 0;                  // Номер шрифта
    cfi.dwFontSize.X = 0;           // Размер шрифта
    cfi.dwFontSize.Y = 48;          // Размер шрифта
    cfi.FontFamily = FF_DONTCARE;   // Название шрифта
    cfi.FontWeight = FW_NORMAL;     // Ширина символа

    // Функция для редактирования "Строчек-объекттов-ЧТО_ТО_ПОДОБНОЕ"
    wcscpy(cfi.FaceName, L"Lucida Console");
    // Установка другого шрифта и размера в текучей(GetStdHandle(STD_OUTPUT_HANDLE)) консоли
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    // Установка(Изменение) кодировки на UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string line;
    ifstream in("assets/intro.txt"); // таким макаром открываем файл чтобы прочесть
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
        
    }
    in.close(); // а теперь закрываем его


cin >> line;
}

