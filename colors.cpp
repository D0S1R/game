#include <iostream>
#include <windows.h>
using namespace std;
/*
0  : Black
1  : Blue
2  : Green
3  : Cyan
4  : Red
5  : Purple
6  : Yellow(dark)
7  : Default white
8  : Grey
9  : Bright blue
10 : Bright green
11 : Bright cyan
12 : Bright red
13 : pink
14 : yellow
15 : Bright white
*/
// SetConsoleTextAttribute(col, (цвет_фона << 4) | цвет_символа);
int main()
{
    HANDLE col;
    col =  GetStdHandle(STD_OUTPUT_HANDLE);

    Scale_Percent = (Walker.P_currentHealth / Walker.P_maxHealth) * 100;
  
    for (int i = 0; i < 16; i++) {
        for (int j=0; j<16; j++){
            SetConsoleTextAttribute(col, (i << 4) | j);
            cout << "A ";
            // FlushConsoleInputBuffer(col);
            SetConsoleTextAttribute(col, (0 << 4) | 7);
        }
        SetConsoleTextAttribute(col, (0 << 4) | 7);
        cout << endl;
    }
    cin >> col;
    return 0;
}