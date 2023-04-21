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