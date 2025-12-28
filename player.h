#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"

class Player{
    protected:
    string name;
    int xPos;
    int yPos;

    public:
        Player();
        Player(string, int, int);
        Player(const Player&);

        string getName();
        int getX();
        int getY();

        void setName(string);
        void setX(int);
        void setY(int);
        
        virtual void playerMove(Board&) = 0;//pure virtual method that moves the players around the board

};
#endif