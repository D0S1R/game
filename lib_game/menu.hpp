// сделать меню
// название самой игры(вдруг забыли)
// добавить 3 кнопыча "начать игру, настройки, выход"
// ну и функционыч туда тоже завезти
void menu(){
    string line;
    ifstream mn_lg("assets/menu_logo.txt");
     if (mn_lg.is_open())
    {
        while (getline(mn_lg, line))
        {
            cout << line << endl;
        }
    }
    mn_lg.close();
    // внизу кнопки а вверху лого
    ifstream mn_bt("assets/menu_buttons.txt");
     if (mn_bt.is_open())
    {
        while (getline(mn_bt, line))
        {
            cout << line << endl;
        }
    }
    mn_bt.close();
}
