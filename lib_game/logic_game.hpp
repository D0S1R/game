// API игры
#include "core.hpp"

// вот это вот всё чтобы карту вывести ёкарный бабай
void Start_game(){
    // line- это где хранится строчка файла
    string line;

    // массив с картой
    vector <string> map;

    // открывает файл карты для вывода/обработки
    ifstream test_map("assets/maps/map1.txt", ios::in);
    
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

    // массив с цветами символов, в виде строк
    vector < string > arr_color;

    //* открываем файл, и запихиваем файл в переменную file_txt
    ifstream file_txt("assets/maps/map1_color.txt"); // окрываем файл для чтения

    string all_str = "";
    //* проверка, открылся ли файл
    if (file_txt.is_open()){
        //* каждую строчку файла, записываем в переменную line
        while (getline(file_txt, line)){
            //TODO: каждую строчку запихиваем(сливаем) в одну большую
            all_str += line;
        }
    }

    string_split(all_str, ';', arr_color);
    vector < string > arr_color_true[arr_color.size()];

    for(int i = 0; i < arr_color.size()-5; i++){
        string_split(arr_color[i], '-', arr_color_true[i]);

        // arr_color["1-6","2-6","3-5"...]
    }
    int arr_int_color[arr_color.size()][2];

    // arr_int_color[i][0] = stoi(arr_color_true[i][0]);

    
    for(int i = 0; i < arr_color.size()-5; i++){
        arr_int_color[i][0] = stoi(arr_color_true[i][0]);
        arr_int_color[i][1] = stoi(arr_color_true[i][1]);
    }
    

    // arr_color[i].back_color;

    file_txt.close();     // закрываем файл

    
    Player Walker;
    // начальное положение игрока
    Walker.X = 3;
    Walker.Y = 3;



    // Цикл обновления сцены
    while(true){
        // перемещаем курсор чтобы глаза не мазолило, а также чтобы переписать экран сцены
        cur_move(0, 0);

        int k = 0;
        for(int i = 0; i < map.size(); i++){
            for(int j = 0; j < map[i].size(); j++){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  (arr_int_color[k][0] << 4) | arr_int_color[k][1]);
                    k++;
                    cout << map[i][j];
            }
            cout << endl;
        }

        Walker.P_move();
        cur_move(Walker.X, Walker.Y);
        cout << Walker.View;
        
        cur_move(-1, 0);
        Sleep(10);
    }
    
}