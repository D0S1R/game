// #include "player.hpp"
// #include "controls.hpp"

// Курсор чтобы переместить, глаза мазолит
void cur_move(int x1, int y1){
    COORD pos;
    pos.X = x1;
    pos.Y = y1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void player_move(int x2, int y2){
    COORD pos;
    pos.X = x2;
    pos.Y = y2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    cout << "☺";
}

// Разделитель строк на элементы массива, используется вектор
void string_split(string str, char separator, vector <string> &fin_str) {
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= str.size(); i++) {
        
        // If we reached the end of the word or the end of the input.
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            fin_str.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
}