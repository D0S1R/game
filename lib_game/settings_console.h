// TODO: Заголовок для работы с интро

// TODO: Защита заголовочного файла, от переопределения(чтобы не определялся ещё раз)
#ifndef _LIB_CONSOLE__SETTINGS_CONSOLE  // ? Условие на существует ли макрос _LIB_CONSOLE__SETTINGS_CONSOLE
#define _LIB_CONSOLE__SETTINGS_CONSOLE  // ? Определение макроса

void Console_setting(){
    // TODO: Настройка объекта шрифта cfi
    CONSOLE_FONT_INFOEX cfi;        // ? структура данных шрифта
    cfi.cbSize = sizeof cfi;        // ? на чс, размер объекта типа данных CONSOLE_FONT_INFOEX
    cfi.nFont = 0;                  // ? Номер шрифта
    cfi.dwFontSize.X = 0;           // ? Размер шрифта
    cfi.dwFontSize.Y = 7;           // ? Размер шрифта
    cfi.FontFamily = FF_DONTCARE;   // ? Название шрифта
    cfi.FontWeight = FW_NORMAL;     // ? Ширина символа

    // Функция для редактирования "Строчек-объекттов-ЧТО_ТО_ПОДОБНОЕ"
    wcscpy(cfi.FaceName, L"Lucida Console");
    // Установка другого шрифта и размера в текучей(GetStdHandle(STD_OUTPUT_HANDLE)) консоли
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    // Установка(Изменение) кодировки на UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
}

#endif  // ? Конец тела условия
