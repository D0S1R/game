#include "core.hpp"

void Start_game(){
while(true){
    string line;
        ifstream test_map("assets/maps/map1.txt");
        if (test_map.is_open())
        {
            while (getline(test_map, line))
            {
                cout << line << endl;
            }
        }
        test_map.close();
        Sleep(10);
        // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
}