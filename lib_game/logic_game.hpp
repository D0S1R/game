// API игры
#include "core.hpp"

// вот это вот всё чтобы карту вывести ёкарный бабай
void Start_game(){
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