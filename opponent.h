#ifndef OPPONENT_H
#define OPPONENT_H
#include "player.h"

class Opponent: public Player{
    public:
        Opponent();
        Opponent(string, int, int);
        Opponent(const Opponent&);

        void playerMove(Board&);//implementation of pure virtual method, moves opponent to a random location (with constraints) on the board each turn

        friend ostream& operator<<(ostream&, Opponent&);
};

#endif