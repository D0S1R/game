#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>//otsleg
// #define _WIN32_WINNT 0x0A00
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>


using namespace std;

class Player{
public:
    // propetries
    int X, Y;
    string View = "☺";

    // metod's
    void P_move(vector <string> map_out){
        if (kbhit()){
            switch(getch()){
                // W
                case 119:
                    if(!Collision(this->X, this->Y-1, map_out)){
                        this->Y--;
                    }
                    break;
                // S
                case 115:
                    if(!Collision(this->X, this->Y+1, map_out)){
                        this->Y++;
                    }
                    break;
                // A
                case 97:
                    if(!Collision(this->X-1, this->Y, map_out)){
                        this->X--;
                    }
                    break;
                // D
                case 100:
                    if(!Collision(this->X+1, this->Y, map_out)){
                        this->X++;
                    }
                    break;
            }
        }
    }
    bool Collision(int X, int Y, vector <string> map_out){
        // проверка колизии перед игроком, если есть то мы стоим (возвращаем 1), если нет (возвращаем 0)
        char check_sym = map_out[Y][X];
        if(map_out[Y][X] == '#'){
            return true;
        }
        else{
            return false;
        }
    }
};


// Курсор чтобы переместить, глаза мазолит
void cur_move(int x1, int y1){
    COORD pos;
    pos.X = x1;
    pos.Y = y1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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


int main(){
    // line- это где хранится строчка файла
    string line;

    vector <string> map;

    // открывает файл карты для вывода/обработки
    ifstream test_map("assets/maps/map1.txt");
    // проверка открыт ли файл
    if (test_map.is_open())
    {
        // вывод всего файла в массив строк с помощью getline()
        while (getline(test_map, line))
        {
            map.push_back(line);
        }
    }

    // схлопываем файл
    test_map.close();

    Player Walker;
    // начальное положение игрока
    Walker.X = 20;
    Walker.Y = 3;



    // Цикл обновления сцены
    while(true){
        // перемещаем курсор чтобы глаза не мазолило, а также чтобы переписать экран сцены
        cur_move(0, 0);

        for(int i = 0; i < map.size(); i++){
            cout << map[i] << endl;
        }

        Walker.P_move(map);
        cur_move(Walker.X, Walker.Y);
        cout << Walker.View;
        
        cur_move(-1, 0);
        Sleep(10);
    }
}
