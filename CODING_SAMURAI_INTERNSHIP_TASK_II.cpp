/*
Description : Tic-Tac-Toe Game
Programmer : Malaya Gupta
Date : 22 June 2024
*/
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Globally declared 1D array to store board values
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

//Checks if any player has won or if match has ended in a draw
//Returns 1 if any player wins, returns 0 for draw and returns -1 to continue the game
//Checks all rows, columns and diagonals
int check_win(){
    if (square[1] == square[2] && square[2] == square[3]) 
        return 1;
    else if (square[4] == square[5] && square[5] == square[6]) 
        return 1;
    else if (square[7] == square[8] && square[8] == square[9]) 
    return 1;
    else if (square[1] == square[4] && square[4] == square[7]) 
        return 1;
    else if (square[2] == square[5] && square[5] == square[8]) 
        return 1;
    else if (square[3] == square[6] && square[6] == square[9]) 
        return 1;
    else if (square[1] == square[5] && square[5] == square[9]) 
        return 1; 
    else if (square[3] == square[5] && square[5] == square[7]) 
        return 1; 
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9'){
        return 0;
    } 
    else{
        return -1;
    }
}

//Displays the game board after each move in a formatted manner
void draw_board(){

    //To only display the latest board and clear the rest.
    system("cls");

    cout<<right<<setw(25)<<"TIC--TAC--TOE GAME"<<endl<<endl;
    cout<<right<<setw(32)<<"Player 1 (X)  -  Player 2 (O)"<<endl<<endl<<endl;

    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<square[1]<<"  |  "<<square[2]<<"  |  "<<square[3]<<"  "<<endl;
    cout<<"\t_____|_____|_____"<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<<"  "<<endl;
    cout<<"\t_____|_____|_____"<<endl;
    cout<<"\t     |     |     "<<endl;
    cout<<"\t  "<<square[7]<<"  |  "<<square[8]<<"  |  "<<square[9]<<"  "<<endl;
    cout<<"\t     |     |     "<<endl<<endl;
}

//Reassigns the game board to its original values if user wants to play again
void reassign_board(){
    square[0] = '0';
    square[1] = '1';
    square[2] = '2';
    square[3] = '3';
    square[4] = '4';
    square[5] = '5';
    square[6] = '6';
    square[7] = '7';
    square[8] = '8';
    square[9] = '9';
}

//Displays the score board once user is done playing
//Displays Player 1 Wins, Player 2 Wins, Draw matches and total number of matches played.
void score_board(int x, int o, int draw, int matches){
    cout<<endl<<right<<setw(26)<<"----SCORE BOARD----"<<endl;
    cout<<" __________________________________________"<<endl; //42
    cout<<left<<" |  Player 1(X)  |  Player 2(O)  |  Draw  |"<<endl;
    cout<<" ------------------------------------------"<<endl;
    cout<<left<<setw(4)<<" |"<<left<<setw(13)<<x<<left<<setw(3)<<"|"<<left<<setw(13)<<o<<left<<setw(3)<<"|"<<left<<setw(6)<<draw<<left<<setw(1)<<"|"<<endl;
    cout<<" ------------------------------------------"<<endl; //42
    cout<<" Matches played : "<<matches<<endl;
}

//Main Function
int main(){
    int player = 1, i, choice, play_again = 1, x_wins = 0, o_wins = 0, draw = 0, matches = 1;
    char mark;
    //Loop for user to play again
    do{
    //Loop to continue game till any player wins or game draws    
    do{
        draw_board();
        player = (player % 2)?1:2;
        cout<<"Player "<<player<<", enter the number : ";
        cin>>choice;
        mark = (player == 1)?'X':'O';

        //Assigns mark to player's square choice if it is within range and not already assigned
        if (square[choice] != 'X' && square[choice] != 'O' && choice<=9 && choice>0) {
            square[choice] = mark;
        }

        //Exception Handling and Data Validation
        //Handles integer inputs out of range of board, non-int data type inputs & inputs that are already taken
        else{
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"INVALID MOVE !";
                player--;
                cin.ignore();
            }
            else{
            cout<<"INVALID MOVE !";
            player--;
            cin.ignore();
            cin.get();
            }
        }

        i = check_win();
        player++;

    }while(i == -1);

    draw_board();
    if(i == 1){
        cout<<"CONGRATULATIONS! PLAYER "<<--player<<" WINS!"<<endl;

        //For score board
        if(player == 1){
            x_wins += 1;
        }
        else if(player == 2){
            o_wins += 1;
        }
    }
    else if(i == 0){
        cout<<"GAME DRAW!"<<endl;

        //For score board
        draw += 1;
    }
    cout<<"Do you want to play again? (Y->1 , N->0) : ";
    cin>>play_again;
    if(play_again == 1){
        reassign_board();
        player = 1;
        //For score board
        matches += 1;
    }
    }while(play_again == 1);

    score_board(x_wins,o_wins,draw,matches);

    //To keep the terminal open till desired.
    cin.ignore();
    cin.get();
}