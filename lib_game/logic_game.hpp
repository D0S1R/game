// API игры
#include "core.hpp"

// вот это вот всё чтобы карту вывести ёкарный бабай
void Start_game(){
    // line- это где хранится строчка файла
    string line;
    string ramka_line;

    vector <string> map;
    vector <string> ramka;
    
    Player Walker;

    string map_str = "";

    // 
    int Scale_Percent;

    // открывает файл карты и рамки для вывода/обработки
    ifstream test_map("assets/maps/map1.txt");
    ifstream test_ramka("assets/interface/square.txt");

    // проверка открыт ли файл
    if (test_map.is_open())
    {
        // вывод всего файла в массив строк с помощью getline()
        while (getline(test_map, line))
        {
            map_str = map_str+"|"+line+"\n";
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
        
        // части интерфейса (хп, стамина)
        cur_move(1, 40-7);
        cout << "HP      :";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 << 4) | 4);
        Scale_Percent = (Walker.P_currentHealth / Walker.P_maxHealth) * 100;
        for(int i=0; i < Scale_Percent; i +=10){
            cout << "█";
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 << 4) | 7);
        cur_move(1, 40-6);
        cout << "Stamina :";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 << 4) | 2);
        cout << "██████████";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 << 4) | 7);

        cur_move(1, 40-5);
        cout << "Mana    :";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 << 4) | 1);
        cout << "██████████";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 << 4) | 7);
        
        // выводим карту
        cur_move(0, 1);
        cout << map_str;

        // Передвижение относительно карты
        Walker.P_move(map);

        // вывод цветного Walker
        cur_move(Walker.X, Walker.Y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 << 4) | 1);
        cout << Walker.View;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0 << 4) | 7);
        
        // передвигаем курсор
        cur_move(-1, 0);

        // спим
        Sleep(10);
    }
}