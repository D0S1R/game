// Курсор чтобы переместить, глаза мазолит
void cur_move(int x1, int y1){
    COORD pos;
    pos.X = x1;
    pos.Y = y1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

