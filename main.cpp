#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main(){
    // 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получить консоль

    CONSOLE_FONT_INFOEX fontInfo;
    GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Получить текущий шрифт

    //   КУСОК КОДА !АТЕНШН!    wcsncpy(L"Arial Cyr", fontInfo.FaceName, LF_FACESIZE);
    fontInfo.dwFontSize.X = 48;           // Размер (в логических единицах)
    fontInfo.dwFontSize.X = 24;                   // Ширина символов кароче
    fontInfo.dwFontSize.Y = 24;                  // А эт высота типа

    SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo); // Установить новый

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

