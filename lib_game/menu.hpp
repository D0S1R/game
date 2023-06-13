// сделать меню
// название самой игры(вдруг забыли)
// добавить 3 кнопыча "начать игру, настройки, выход"
// ну и функционыч туда тоже завезти
#include "logic_game.hpp"

void resize_sym_console(int y){
    int iWidth = GetSystemMetrics(SM_CXSCREEN);  // разрешение экрана по горизонтали
    int iHeight = GetSystemMetrics(SM_CYSCREEN); // разрешение экрана по вертикали
        // TODO: Настройка объекта шрифта cfi
    CONSOLE_FONT_INFOEX cfi;                    // ? структура данных шрифта
    cfi.cbSize = sizeof cfi;                    // ? на чс, размер объекта типа данных CONSOLE_FONT_INFOEX
    cfi.nFont = 0;                              // ? Номер шрифта
    cfi.dwFontSize.X = 0;                       // ? Размер шрифта
    cfi.dwFontSize.Y = (int)(iHeight/y);      // ? Размер шрифта
    cfi.FontFamily = FF_DONTCARE;               // ? Название шрифта
    cfi.FontWeight = FW_NORMAL;                 // ? Ширина символа

    // Функция для редактирования "Строчек-объекттов-ЧТО_ТО_ПОДОБНОЕ"
    wcscpy(cfi.FaceName, L"Lucida Console");
    // Установка другого шрифта и размера в текучей(GetStdHandle(STD_OUTPUT_HANDLE)) консоли
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void menu(){
    string line;
    ifstream mn_lg("assets/menu_logo.txt");
     if (mn_lg.is_open())
    {
        while (getline(mn_lg, line))
        {
            cout << line << endl;
        }
    }
    mn_lg.close();
    // внизу кнопки а вверху лого
    ifstream mn_bt("assets/menu_buttons.txt");
     if (mn_bt.is_open())
    {
        while (getline(mn_bt, line))
        {
            cout << line << endl;
        }
    }
    mn_bt.close();
    
    while(true){
        // GetAsyncKeyState('V')
        if(GetKeyState('1')){
            system("CLS");
            resize_sym_console(39);
            Start_game();       
            break;
        }
        if(GetKeyState('2')){
            abort();
        }
        if(GetKeyState('3')){
            abort();
        }
    }
}
