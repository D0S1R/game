void Console_setting(){
    CONSOLE_FONT_INFOEX cfi;        // структура данных шрифта
    cfi.cbSize = sizeof cfi;        // на чс, размер объекта типа данных CONSOLE_FONT_INFOEX
    cfi.nFont = 0;                  // Номер шрифта
    cfi.dwFontSize.X = 8;           // Размер шрифта
    cfi.dwFontSize.Y = 8;          // Размер шрифта
    cfi.FontFamily = FF_DONTCARE;   // Название шрифта
    cfi.FontWeight = FW_NORMAL;     // Ширина символа

    // Функция для редактирования "Строчек-объекттов-ЧТО_ТО_ПОДОБНОЕ"
    // wcscpy(cfi.FaceName, L"Lucida Console");
    // Установка другого шрифта и размера в текучей(GetStdHandle(STD_OUTPUT_HANDLE)) консоли
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    // Установка(Изменение) кодировки на UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
}
