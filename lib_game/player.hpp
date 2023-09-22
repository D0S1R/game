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
    // Блок кода про инвентарь 
    int Current_item = 0;
    string Inventory[10];
    bool isShowInv = false;
    void ShowInv(){
        cur_move(62, 32);
        cout << "Inventory :";
        cur_move(62, 33);
        cout << this->Inventory[Current_item];
    }
    void initInventory(){
        this->Inventory[0] = "Sword";
        this->Inventory[1] = "Shield";
        this->Inventory[2] = "Mana potion";
        this->Inventory[3] = "Health potion";
        this->Inventory[4] = "Beer";
    }
    // metod's
    void P_move(vector <string> map_out){
        if(isShowInv)
            ShowInv();

        if (kbhit()){
            cout << getch();
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
                    // if(Current_item < 9){
                    //     Current_item++;
                    // }
                    break;
                case 9:
                    if(isShowInv){
                        isShowInv = false; 
                    } else{
                        isShowInv = true;
                    }
                    break;
                case 77:
                    if(Current_item < 4){
                        Current_item++;
                    }
                    break;
                case 75:
                    if(Current_item > 0){
                        Current_item--;
                    }
                    break;
                case 101:
                    if(Inventory[Current_item]=="Beer"){
                        this->P_currentHealth+=200;
                        this->P_currentStamina+=100;
                        this->P_currentMana+=10;
                    }
                    if(inventory[Current_item]=="Health potion"){
                        this->P_currentHealth+=50;
                    }
                    if(inventory[Current_item]=="Mana potion"){
                        this->P_currentMana+=50;
                    }
                // 
                break;
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
