class Player{
public:
    // propetries
    int X, Y;
    string View = "☺";
        
    // health in-game
    int P_maxHealth = 100;
    int P_currentHealth = 50;
    
    // stamina in-game
    int P_maxStamina = 100;
    int P_currentStamina = 50;
    
    // mana in-game
    int P_maxMana = 100;
    int P_currentMana = 50;

    string Inventory[10];
    bool isShowInv = false;
    void ShowInv(){
        cur_move(62, 32);
        cout << "Inventory :";
        cur_move(62, 34);
        cout << Inventory[0];
    }
    void constructor(){
        Inventory[0] = "Sword";
        Inventory[1] = "Shield";
        Inventory[2] = "Mana potion";
        Inventory[3] = "Health potion";
        Inventory[4] = "Yorik";
        Inventory[5] = "Eto ne moe mne podkinyli";
        Inventory[6] = "Bow";
        Inventory[7] = "Arrow";
        Inventory[8] = "Torch";
        Inventory[9] = "Passport";
    }
    // metod's
    void P_move(vector <string> map_out){
        if(isShowInv)
            ShowInv();

        if (kbhit()){
            switch(getch()){
                // W
                case 119:
                    if(!Collision(this->X, this->Y-1, map_out) && Y > 2){
                        this->Y--;
                    }
                    break;
                // S
                case 115:
                    if(!Collision(this->X, this->Y+1, map_out) && Y < 29){
                        this->Y++;
                    }
                    break;
                // A
                case 97:
                    if(!Collision(this->X-1, this->Y, map_out) && X > 1){
                        this->X--;
                    }
                    break;
                // D
                case 100:
                    if(!Collision(this->X+1, this->Y, map_out) && X < 60){
                        this->X++;
                    }
                    break;
                case 9:
                    if(isShowInv){
                        isShowInv = false; 
                    } else{
                        isShowInv = true;
                    }

            }
        }
    }
    bool Collision(int X, int Y, vector <string> map_out){
        // проверка колизии перед игроком, если есть то мы стоим (возвращаем 1), если нет (возвращаем 0)
        Y= Y-1;
        X= X-1;
        if(map_out[Y][X] == '#' || map_out[Y][X] == '0'){
            return true;
        }
        else{
            return false;
        }
    };
};
