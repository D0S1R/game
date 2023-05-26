#include "player.hpp"
#include "controls.hpp"

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