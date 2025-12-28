#ifndef BOARD_H
#define BOARD_H
#include <iostream>
using namespace std;

#define SIZE 5

class Board{
private:
    char displayedBoard[SIZE][SIZE];//the board the user sees
    char hiddenBoard[SIZE][SIZE];//the board that holds all the hidden entities

public:
    Board();
    Board(char, char);
    Board(const Board&);

    char getHiddenCharAtIndex(int, int);//gets a single tile at a point
    char getDisplayedCharAtIndex(int, int);

    void clearBoard();
    void placeEntityOnHidden(int, int, char);//places an entity on the board
    void placeEntityOnDisplayed(int, int, char);

    friend ostream& operator<<(ostream&, Board&);
};

#endif