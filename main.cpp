#include <iostream>
#include <array>
#include<random>
#include<time.h>

using namespace std;

int random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

void drawBord(string bord[9]){
    cout << endl;
    cout<< bord[0] << " | " << bord[1] << " | " << bord[2] << endl;
    cout<< bord[3] << " | " << bord[4] << " | " << bord[5] << endl;
    cout<< bord[6] << " | " << bord[7] << " | " << bord[8] << endl;
}

void setValusInBord(string bord[9],int player[9],int computer[9]){
    for(int i=0;i<9;i++){
        if(player[i]==1){
            bord[i]="X";
        }
        else if(computer[i]==1){
            bord[i]="O";
        }
    }
    drawBord(bord);
}

void computerPlay(int player[9],int computer[9]){
    int win[8][3]={ {0,1,2},
                    {3,4,5},
                    {6,7,8},
                    {0,3,6},
                    {1,4,7},
                    {2,5,8},
                    {0,4,8},
                    {2,4,6} };

    int w[3];

    for(int i=0;i<8;i++){
        int counter=0;
        for(int j=0;j<3;j++){

            if(computer[win[i][j]]==1){
                counter++;
            }
            if(counter==2){
                //w = win[i];
                // íæÌÏ ØÑíÞÉ ááÝæÒ
                for(int s=0;s<3;s++){
                    if(computer[win[i][s]]==0 && player[win[i][s]]==0){
                        computer[win[i][s]]=1;
                        cout<< endl << win[i][s]+1<< endl;
                        return;
                    }
                }

            }

        }
    }


    for(int i=0;i<8;i++){
        int counter=0;
        for(int j=0;j<3;j++){

            if(player[win[i][j]]==1){
                counter++;
            }
            if(counter==2){
                //w = win[i];
                // íæÌÏ ØÑíÞÉ ááÝæÒ
                for(int s=0;s<3;s++){
                    if(player[win[i][s]]==0 && computer[win[i][s]]==0){
                        computer[win[i][s]]=1;
                        cout<< endl << win[i][s]+1<< endl;
                        return;
                    }
                }

            }

        }
    }


    //  áÇíæÌÏ ØÑíÞÉ ÝæÒ
    int randm;
    while(true){
        randm=random(1, 9);
        randm--;
        if(computer[randm]==0 && player[randm]==0){
            computer[randm]=1;
            cout<< endl << randm+1<< endl;
            //cout<< randm;
            return;
        }
    }

    /*if(w.empty()){
        //  áÇíæÌÏ ØÑíÞÉ ÝæÒ
        int randm;
        while(true){
            randm=(rand() % 9) + 1;
            if(computer[randm]==0){
                computer[randm]=1;
                break;
            }
        }

    }
    else{
        // íæÌÏ ØÑíÞÉ ÝæÒ
    }*/
}

bool checkIfPlayerWin(int anyPlayer[9]){
    if(anyPlayer[0]==1 && anyPlayer[1]==1 && anyPlayer[2]==1){
        return true;
    }
    else if(anyPlayer[3]==1 && anyPlayer[4]==1 && anyPlayer[5]==1){
        return true;
    }
    else if(anyPlayer[6]==1 && anyPlayer[7]==1 && anyPlayer[8]==1){
        return true;
    }
    else if(anyPlayer[0]==1 && anyPlayer[3]==1 && anyPlayer[6]==1){
        return true;
    }
    else if(anyPlayer[1]==1 && anyPlayer[4]==1 && anyPlayer[7]==1){
        return true;
    }
    else if(anyPlayer[2]==1 && anyPlayer[5]==1 && anyPlayer[8]==1){
        return true;
    }
    else if(anyPlayer[0]==1 && anyPlayer[4]==1 && anyPlayer[8]==1){
        return true;
    }
    else if(anyPlayer[2]==1 && anyPlayer[4]==1 && anyPlayer[6]==1){
        return true;
    }
    else{
        return false;
    }
}

int checkWinner(int player[9],int computer[9]){
    if(checkIfPlayerWin(player)){
        cout << "\n The Player wins." << endl;
        return 1;
    }
    else if(checkIfPlayerWin(computer)){
        cout << "\n The computer wins." << endl;
        return 2;
    }
    else{
        return 0;
    }
}

int main()
{
    string bord[9]={ "1", "2", "3",
                       "4", "5", "6",
                       "7", "8", "9" };

    int player[9]={    0, 0, 0,
                       0, 0, 0,
                       0, 0, 0 };

    int computer[9]={  0, 0, 0,
                       0, 0, 0,
                       0, 0, 0 };
    int pos;
    int counter=0;

    drawBord(bord);

    while(counter<9){

    cout<< "Enter pos: ";
    cin>> pos;
    pos--;
    if(player[pos]==0 && computer[pos]==0){
        player[pos]=1;
    }
    else{
        cout<< "\n Not avilabl!" << endl;
        continue;
    }



    setValusInBord( bord, player, computer);
    if(checkWinner( player, computer)){
        break;
    }


    computerPlay( player, computer);
    setValusInBord( bord, player, computer);
    if(checkWinner( player, computer)){
        break;
    }
    counter++;

    }




    return 0;
}
