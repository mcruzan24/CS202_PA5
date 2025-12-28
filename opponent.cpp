#include "opponent.h"
#include "helpers.h"

Opponent::Opponent():Player(){
}
Opponent::Opponent(string n, int x, int y):Player(n, x, y){
}
Opponent::Opponent(const Opponent& rhs):Player(rhs){
}
void Opponent::playerMove(Board& board){
    board.placeEntityOnHidden(xPos, yPos, '.');
    do{
        xPos = getRandomCoordinate();
        yPos = getRandomCoordinate();
    }while(!checkSpaceEmpty(board, xPos, yPos));
    board.placeEntityOnHidden(xPos, yPos, 'O');
}
ostream& operator<<(ostream& out, Opponent& opponent){
    out << "Opponent Position: (" << opponent.xPos << ", " << opponent.yPos << ")" << endl;
    return out;
}