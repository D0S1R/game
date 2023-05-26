// 
class Player{
public:
    // propetries
    int X, Y;
    string View = "☺";

    // metod's
    void P_move(){
        if (kbhit()){
            switch(getch()){
                // W
                case 119:
                    this->Y--;
                    // if(Y != 1){
                    //     this->Y--;
                    // }
                    break;
                // S
                case 115:
                    this->Y++;
                    // if(Y !=100){
                    //     this->Y++;
                    // }
                    break;
                // A
                case 97:
                    this->X--;
                    // if(X !=1){
                    //     this->X--;
                    // }
                    break;
                // D
                case 100:
                    this->X++;
                    // if(X !=300){
                    //     this->X++;
                    // }
                    break;
            }
        }
    }
};
