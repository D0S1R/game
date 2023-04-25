// TODO: Заголовок для работы с интро

#pragma once    // Умная защита переопределения (Не все компиляторы поддерживают, только современные)

void intro(){
    // Создаём переменную
    string line;
    ifstream in("assets/intro.txt"); // таким макаром открываем файл чтобы прочесть
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
        
    }
    in.close(); // а теперь закрываем его
}