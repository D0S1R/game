class Player{
public:
    // propetries
    int X, Y;
    string View = "☺";
        
    // health in-game
    int P_maxHealth = 100;
    int P_currentHealth = 50;
    string line_Hp = "";
    
    // stamina in-game
    int P_maxStamina = 100;
    int P_currentStamina = 50;
    string line_Stam = "";
    
    // mana in-game
    int P_maxMana = 100;
    int P_currentMana = 50;
    string line_Mana = "";

    // Блок кода про инвентарь 
    int Current_item = 0;
    string Inventory[10];
    bool isShowInv = false;
    bool isBox = false;

    // ВРЕМЕННО, потом перенести в логичное и правельное место
    int coords_chest[10][2];
    string item_chest[10];

    // init chest
    void initChest(){
        // char arr[100];

        // cin.getline
        string line;
        ifstream chest("assets/maps/Chest_info.txt");
        char seporator = ' ';
        if (chest.is_open())
        {
            int num_item = 0;
            // вывод всего файла в массив строк с помощью getline()
            while (getline(chest, line))
            {
                // map_str = map_str+"|"+line+"\n";
                // map.push_back(line);
                string y = "", x = "", item = "";
                bool isY = true, isX = false, isItem = false;
                for(int i = 0; i < line.length(); i++){
                    if(line[i] != seporator && isY){
                        y += line[i];
                        if(line[i+1] == seporator){
                            isY = false;
                            isX = true;
                        }
                    }
                    if(line[i] != seporator && isX){
                        x += line[i];
                        if(line[i+1] == seporator){
                            isY = false;
                            isX = false;
                            isItem = true;
                        }
                    }
                    if(line[i] != seporator && isItem){
                        item += line[i];
                        if(line[i+1] == seporator){
                            isY = false;
                            isX = false;
                            isItem = true;
                        }
                    }
                }
                coords_chest[num_item][0] = std::stoi(y);
                coords_chest[num_item][1] = std::stoi(x);
                item_chest[num_item] = item;
                num_item++;
            }
        }
    }

    void ShowInv(){
        cur_move(62, 32);
        cout << "Inventory : #" << Current_item+1 << "/10";
        cur_move(62, 33);
        cout << this->Inventory[Current_item];
    }

    void initInventory(){
        initChest();
        this->Inventory[0] = "Sword";
        this->Inventory[1] = "Shield";
        this->Inventory[2] = "Mana potion";
        this->Inventory[3] = "Health potion";
        this->Inventory[4] = "Beer";

        for(int i=0; i < this->P_currentHealth; i +=10){
            line_Hp += "█";
        }
        
        for(int i=0; i < this->P_currentStamina; i +=10){
            line_Stam += "█";
        }

        for(int i=0; i < this->P_currentMana; i +=10){
            line_Mana += "█";
        }
    }

    void reLineHP(){
        line_Hp = "";

        for(int i=0; i < this->P_currentHealth; i +=10){
            line_Hp += "█";
        }
    }
    void reLineStam(){
        line_Stam = "";

        for(int i=0; i < this->P_currentStamina; i +=10){
            line_Stam += "█";
        }
    }
    void reLineMana(){
        line_Mana = "";

        for(int i=0; i < this->P_currentMana; i +=10){
            line_Mana += "█";
        }
    }

    // metod's
    void P_move(vector <string> map_out){
        if(isShowInv)
            ShowInv();

        if (kbhit()){
            // cout << getch();
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
                    if(Current_item < 9){
                        Current_item++;
                    }
                    break;
                case 75:
                    if(Current_item > 0){
                        Current_item--;
                    }
                    break;
                case 101:
                    if(isShowInv){
                        useItem();
                    }
                    if(
                        map_out[this->Y][this->X+1] == '0' ||
                        map_out[this->Y][this->X-1] == '0' ||
                        map_out[this->Y+1][this->X] == '0' ||
                        map_out[this->Y-1][this->X] == '0' ||
                        map_out[this->Y+1][this->X+1] == '0' ||
                        map_out[this->Y+1][this->X-1] == '0' ||
                        map_out[this->Y-1][this->X+1] == '0' ||
                        map_out[this->Y-1][this->X-1] == '0' ||
                        isBox
                    ){

                        isBox = true;
                        cur_move(62, 33);
                        int num_item = 0;
                        for(int i = 0; i < 10; i++){
                            if(coords_chest[i][0] == this->Y && coords_chest[i][1] == this->X+1){
                                num_item = i;
                            }
                        }
                        cout << "Chest: " << item_chest[num_item];

                    }
                    // if(map_out[this->Y][this->X+1] == "0"){
                    //     cout << "623487154875623874621398745623956239875629873456982375629387459";
                    // }
                // 
                break;
            }
        }
    }

    void useItem(){
        if(Inventory[Current_item]=="Beer"){
            this->P_currentHealth+=150;
            this->P_currentStamina+=100;
            this->P_currentMana-=50;

            reLineHP();
            reLineStam();
            reLineMana();

            this->Inventory[Current_item] = "";
        }
        if(Inventory[Current_item]=="Health potion"){
            this->P_currentHealth+=50;
            reLineHP();

            this->Inventory[Current_item] = "";
        }
        if(Inventory[Current_item]=="Mana potion"){
            this->P_currentMana+=50;
            reLineMana();

            this->Inventory[Current_item] = "";
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
