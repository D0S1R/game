// API игры
#include "core.hpp"

// вот это вот всё чтобы карту вывести ёкарный бабай
void Start_game(){
    // line- это где хранится строчка файла
    string line;
    // открывает файл карты для вывода/обработки
    ifstream test_map("assets/maps/map1.txt", ios::in);
    test_map.seekg(0);//перевод курсора в начало, для перевода в конец, нужен eof
    int len_str_map = 0;
    string test;
    // проверка открыт ли файл
    if (test_map.is_open())
    {
        // вывод всего файла построчно с помощью getline()
        while (getline(test_map, line))
        {
            if(len_str_map==0){
                test=line;
            }else{
                test="11";
            }
            // вывод строки файла
            len_str_map++;
        }
    }
    string map[len_str_map];
    test_map.seekg(0);
    // проверка открыт ли файл
    if (test_map.is_open())
    {
        int i = 0;
        // вывод всего файла построчно с помощью getline()
        while (getline(test_map, line))
        {
            // вывод строки файла
            map[i] = line;
            i++;
        }
    }
    
    system("cls");
    cout << map[0] << " 123 " << test << endl;
    Sleep(10000);
    
    Player Walker;
    // начальное положение игрока
    Walker.X = 3;
    Walker.Y = 3;



    // Цикл обновления сцены
    while(true){
        // перемещаем курсор чтобы глаза не мазолило, а также чтобы переписать экран сцены
        cur_move(-1, 0);

        for(int i = 0; i < len_str_map; i++){
            cout << map[i];
        }
        
        Walker.P_move();
        cur_move(Walker.X, Walker.Y);
        cout << Walker.View;

        
        
        Sleep(1);
    }
    // схлопываем файл
    test_map.close();
    
}