// API игры
#include "core.hpp"

// вот это вот всё чтобы карту вывести ёкарный бабай
void Start_game(){
    // line- это где хранится строчка файла
    string line;
    string ramka_line;

    vector <string> map;
    vector <string> ramka;


    // открывает файл карты и рамки для вывода/обработки
    ifstream test_map("assets/maps/map1.txt");
    ifstream test_ramka("assets/interface/square.txt");
    
    // проверка открыт ли файл
    if (test_map.is_open())
    {
        // вывод всего файла в массив строк с помощью getline()
        while (getline(test_map, line))
        {
            map.push_back(line);
        }
    }
    if (test_ramka.is_open())
    {
        // вывод всего файла в массив строк с помощью getline()
        while (getline(test_ramka, line))
        {
            ramka.push_back(line);
        }
    }

    // схлопываем файл
    test_map.close();
    test_ramka.close();

    Player Walker;
    // начальное положение игрока
    Walker.X = 20;
    Walker.Y = 3;



    // Цикл обновления сцены
    while(true){
        // перемещаем курсор чтобы глаза не мазолило, а также чтобы переписать экран сцены
        cur_move(0, 0);
        
        // выводим рамку
        for(int i = 0; i < ramka.size(); i++){
            cout << ramka[i] << endl;
        }

        // выводим карту
        for(int i = 0; i < map.size(); i++){
            cur_move(1, i+1);
            cout << map[i] << endl;
        }

        // Передвижение относительно карты
        Walker.P_move(map);

        // вывод Walker
        cur_move(Walker.X, Walker.Y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (3 << 4) | 9);
        cout << Walker.View;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 << 4) | 7);
        
        // передвигаем курсор
        cur_move(-1, 0);

        // спим
        Sleep(10);
    }
}