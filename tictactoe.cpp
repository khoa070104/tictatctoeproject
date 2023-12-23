//Tic Tac Toe Game by KHOA070104

#include <iostream>
#include <stdlib.h>
using namespace std;


int choice,row,col;
char turn = 'X';
bool draw = false;



//Cau truc bang luu gia tri nhap vao : 
// + Phan kien thuc lien quan : Mang 2 chieu 

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void display_show(){
    //Rander Game Board LAYOUT

    cout<<"PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}


void player_turn(){
    if(turn == 'X'){
        cout<<"\n\tPlayer - 1 [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\n\tPlayer - 2 [O] turn : ";
    }

    cin>> choice;


    switch(choice){
        case 1: row=0; col=0; break;
        case 2: row=0; col=1; break;
        case 3: row=0; col=2; break;
        case 4: row=1; col=0; break;
        case 5: row=1; col=1; break;
        case 6: row=1; col=2; break;
        case 7: row=2; col=0; break;
        case 8: row=2; col=1; break;
        case 9: row=2; col=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = 'O';
        turn = 'X';
    }else {
        //Check gia tri bi trung
        cout<<"Box already filled!n Please choose another!!nn";
        player_turn();
    }
    display_show();
}


// Check Static Functions
bool check_status(){
    //  ----- 1
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    // ------ 2

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    // ------ 3
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    draw = true;
    return false;
}


int main()
{
    cout<<"\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout<<"\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t";
    cout<<"\n\t\t\t\tGIT:KHOA070104\t\t\t\n";
    cout<<"======================================================================================\n";
    while(check_status()){
        display_show();
        player_turn();
        check_status();
    }
    if(turn == 'X' && draw == false){
        cout<<"\n\nCongratulations!Player with 'O' has won the game";
    }
    else if(turn == 'O' && draw == false){
        cout<<"\n\nCongratulations!Player with 'X' has won the game";
    }
    else
    cout<<"\n\nGAME DRAW!!!\n\n";
} 
