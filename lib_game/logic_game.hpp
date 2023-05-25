#include "core.hpp"
// вот это вот всё чтобы карту вывести ёкарный бабай
void Start_game(){
    // line- это где хранится строчка файла
    string line;
    // открывает файл карты для вывода/обработки
    ifstream test_map("assets/maps/map1.txt");
    
    // Цикл обновления сцены
    while(true){
        // перемещаем курсор чтобы глаза не мазолило, а также переписать экран сцены
        cur_move(-1, 0);

        // проверка открыт ли файл
        if (test_map.is_open())
        {
            // вывод всего файла построчно с помощью getline()
            while (getline(test_map, line))
            {
                // вывод строки файла
                cout << line << endl;
            }
        }
        // Sleep(150);
    }
    // схлопываем файл
    test_map.close();
}