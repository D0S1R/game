// TODO: Заголовок для работы с интро

#pragma once    // Умная защита переопределения (Не все компиляторы поддерживают, только современные)

void intro(){

    int iWidth = GetSystemMetrics(SM_CXSCREEN);  // разрешение экрана по горизонтали
    int iHeight = GetSystemMetrics(SM_CYSCREEN); // разрешение экрана по вертикали

    float dd = (iHeight/100);
    float size_x = (int)((dd/100.0)*60.0); // размер символа 

    int col_sym_x = (int)(iWidth/size_x);
    int col_sym_y = 100;
    int vysota = (col_sym_y-64)/2;
    


    // Создаём переменную
    for(int boba=0; boba < vysota; boba++){
        cout << " " << endl;
    }
    string line;
    ifstream in("assets/intro.txt"); // таким макаром открываем файл чтобы прочесть
    if (in.is_open())
    {
        while (getline(in, line))
        {
            int left_space = (col_sym_x - 128)/2;
            // cout << left_space;
            for(int boba=0; boba < left_space; boba++){
                cout << " ";
            }
            cout << line << endl;
        }
        
    }
    in.close(); // а теперь закрываем его
}