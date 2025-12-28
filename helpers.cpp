#include "helpers.h"

int getRandomCoordinate(){
    return rand() % SIZE; 
}
void generateBoard(Board& board){
    board.clearBoard();

    int trapsPlaced = 0;//tracks how many traps have been placed to ensure that exactly 5 are placed on the board
    while(trapsPlaced <= 5){//places trap at a random location on the board
        int x = getRandomCoordinate();
        int y = getRandomCoordinate();
        if(checkSpaceEmpty(board, x, y) && (x != 0 || y != 0)){//checks if the space is empty before placing and that the space is not (0,0)
            board.placeEntityOnHidden(x, y, 'X');
            trapsPlaced++;
        }
    }
    int treasuresPlaced = 0;//tracks how many treasures have been placed to ensure that exactly 5 are placed on the board
    while(treasuresPlaced <= 5){//places treasure at random location on the board
        int x = getRandomCoordinate();
        int y = getRandomCoordinate();
        if(checkSpaceEmpty(board, x, y) && !checkIfTreasureSurrounded(board, x, y) && (x != 0 || y != 0)){//checks if space is empty before placing and that the treasure wont be surrouded by traps and the space is not (0,0)
            board.placeEntityOnHidden(x, y, 'T');
            treasuresPlaced++;
        }
    }
}
void gameLoop(Board& board, User& user, Opponent& opponent){
    bool userPlaying = true;

    while(userPlaying == true){
        cout << user << endl;//displays stats
        cout << board << endl;//displays board
        user.playerMove(board);//gets players movement
        int x = user.getX();
        int y = user.getY();
        opponent.playerMove(board);//moves the opp to a random location
        checkMovement(x, y, board, user);//checks if the user ran into something
        if(user.checkWin()){//checks if the user won, ends game if so
            cout << "You Win! Congrats!" << endl;
            userPlaying = false;
        }
        else if(user.checkLose()){//checks if the user lost, ends game if so
            cout << "Game over." << endl;
            userPlaying = false;
        }
    }
}
bool checkInBounds(int x,int y){
    if(x >=  0 && x < 5 && y >= 0 && y < 5){
        return true;//in bounds
    }
    else{
        return false;//out of bounds
    }
}
bool checkSpaceEmpty(Board& board, int x, int y){
    if(board.getHiddenCharAtIndex(x,y) == '.'){
        return true;//space is empty and good to be filled with object
    }
    else{
        return false;//space is not empty and object should not be filled there
    }
}
bool checkIfTreasureSurrounded(Board& board, int x, int y){
    if(checkInBounds(x - 1, y) && board.getHiddenCharAtIndex(x - 1, y) != 'X'){
        return false;
    }
    if(checkInBounds(x + 1, y) && board.getHiddenCharAtIndex(x + 1, y) != 'X'){
        return false;
    }
    if(checkInBounds(x, y + 1) && board.getHiddenCharAtIndex(x, y + 1) != 'X'){
        return false;
    }
    if(checkInBounds(x, y - 1) && board.getHiddenCharAtIndex(x, y - 1) != 'X'){
        return false;
    }
    return true;
}
void checkMovement(int& x, int& y, Board& board, User& user){
    if(board.getHiddenCharAtIndex(x,y) == 'T'){
        Treasure treasure;
        user + treasure;
        board.placeEntityOnHidden(x,y,'.');//does this so that the treasure cant be collected again
        cout << endl<< "Treasure Found! (+1 Treasure)" << endl;
    }
    else if(board.getHiddenCharAtIndex(x,y) == 'X'){
        Trap trap;
        user - trap;
        board.placeEntityOnDisplayed(x,y,'X');//does this to reveal the location of the trap to the user
        cout << endl<< "A Trap! (-20 Health)" << endl;
    }
    else if(board.getHiddenCharAtIndex(x,y) == 'O'){
        Opponent opponent;
        user - opponent;
        cout << endl << "An Opponent! (-30 Health)" << endl;
    }
}
void displayMainMenu(){
    cout << "Welcome to Treasure Hunt Adventure Game!" << endl;
    cout << "1. Begin Game" << endl << "2. Exit" << endl;
    cout << "Please make a selection: ";
}
bool playingAgain(User& user, Board& board){
    cout << "Would you like to play again? (y/n): ";
        char playingAgain = getUserInput<char>();
        if(playingAgain == 'y'||playingAgain == 'Y'){
            resetGame(user,board);
            return true;
        }
        else{
            cout << "Thanks for playing!" << endl;
            return false;
        }
}
void resetGame(User& user, Board& board){
    user.setNumTreasures(0);
    user.setUserHealth(100);
    user.setX(0);
    user.setY(0);
    board.clearBoard();
}