// ! g++ main.cpp -IE:/git/game/lib_game -o walker

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
    // char Title[1024];
    // GetConsoleTitle(Title, 1024); // Узнаем имя окна
    // // GetModuleFileName(NULL,Title, sizeof(Title));
    // HWND hwnd=FindWindow(NULL, Title); // Узнаем hwnd окна
    // int iWidth = GetSystemMetrics(SM_CXSCREEN);  // разрешение экрана по горизонтали
    // int iHeight = GetSystemMetrics(SM_CYSCREEN); // разрешение экрана по вертикали
    // SetWindowLongPtr(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
    // SetWindowPos(hwnd,hwnd,0,0,0,0,SWP_NOZORDER|SWP_NOSIZE);
    // SetWindowPos(hwnd,hwnd,0,0,iWidth,iHeight,SWP_NOZORDER|SWP_NOMOVE);
    cin >> gggggg;
}

