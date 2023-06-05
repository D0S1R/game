class Player{
public:
    // propetries
    int X, Y;
    string View = "☺";

    // metod's
    void P_move(vector <string> map_out){
        if (kbhit()){
            switch(getch()){
                // W
                case 119:
                    if(!Collision(this->X, this->Y-1, map_out)){
                        this->Y--;
                    }
                    break;
                // S
                case 115:
                    if(!Collision(this->X, this->Y+1, map_out)){
                        this->Y++;
                    }
                    break;
                // A
                case 97:
                    if(!Collision(this->X-1, this->Y, map_out)){
                        this->X--;
                    }
                    break;
                // D
                case 100:
                    if(!Collision(this->X+1, this->Y, map_out)){
                        this->X++;
                    }
                    break;
            }
        }
    }
    bool Collision(int X, int Y, vector <string> map_out){
        // проверка колизии перед игроком, если есть то мы стоим (возвращаем 1), если нет (возвращаем 0)
        if(map_out[Y][X] == '#'){
            return true;
        }
        else{
            return false;
        }
    }
};
