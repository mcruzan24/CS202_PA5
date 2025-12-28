//Author: Margaux Cruzan
//Date: 5/8/25
//Purpose: CS202 PA5, Treasure Hunt Adventure Game
#include "board.h"
#include "user.h"
#include "opponent.h"
#include "helpers.h"

int main() {
    srand(time(0));//randomly seeds generator so it generates differently each time

    Board board;//creating objects
    User user;
    Opponent opponent;

    displayMainMenu();//shows menu only once
    int choice = getUserInput<int>();//gets user's choice to play or not

    if(choice == 1){//if the users chooses to play,
        bool playing = true;
        while(playing){
            generateBoard(board);//generates a random board to play on
            board.placeEntityOnDisplayed(0, 0, 'P');//places the user at inital position (0,0)
            gameLoop(board, user, opponent);//runs the game
            playing = playingAgain(user, board);//prompts the user to play again or exit after finishing a round
        }
    }
    else if(choice == 2){//if the user chooses to exit
        cout << "Thanks for playing!" << endl;
    }
    return 0;
}