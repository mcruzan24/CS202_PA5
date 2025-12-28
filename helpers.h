#include <cstdlib>
#include <ctime> 
#include "board.h"
#include "user.h"
#include "opponent.h"

int getRandomCoordinate();//gets a random x or y coordinate (will be called twice when used to get both)
void generateBoard(Board&);//populates the hidden game board with traps and treasures
void gameLoop(Board&, User&, Opponent&);
bool checkInBounds(int, int);//checks if a point is on the board or not
bool checkSpaceEmpty(Board&, int, int);//checks if a space is empty so that an object can be placed there
bool checkIfTreasureSurrounded(Board&, int, int);//ensures a treasure is not surrounded by a trap on all sides
void checkMovement(int&, int&, Board&, User&);//checks if the player encountered an entity and behaves accordingly
void displayMainMenu();//displays the main menu
bool playingAgain(User&, Board&);//checks if the user is player again
void resetGame(User&, Board&);//clears the board and resets the player's stats and position

template <typename T>
T getUserInput(){//templated function that can get the user's input
    T input;
    cin >> input;
    return input;
}