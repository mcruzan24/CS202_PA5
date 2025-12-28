#include "board.h"

Board::Board(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            displayedBoard[i][j] = '.';
            hiddenBoard[i][j] = '.';
        }
    }
}
Board::Board(char dChar, char hChar){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            displayedBoard[i][j] = dChar;
            hiddenBoard[i][j] = hChar;
        }
    }
}
Board::Board(const Board& rhs){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            displayedBoard[i][j] = rhs.displayedBoard[i][j];
            hiddenBoard[i][j] = rhs.hiddenBoard[i][j];
        }
    }
}
char Board::getHiddenCharAtIndex(int x, int y){
    return hiddenBoard[x][y];
}
char Board::getDisplayedCharAtIndex(int x, int y){
    return displayedBoard[x][y];
}
void Board::placeEntityOnHidden(int x, int y, char obj){
    hiddenBoard[x][y] = obj;
}
void Board::placeEntityOnDisplayed(int x, int y, char obj){
    displayedBoard[x][y] = obj;
}

ostream& operator<<(ostream& out, Board& board){//displays only the displayed board
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            out << board.getDisplayedCharAtIndex(i, j) << " ";
        }
        out << endl;
    }
    return out;
}
void Board::clearBoard(){
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            displayedBoard[i][j] = '.';
            hiddenBoard[i][j] = '.';
        }
    }
}