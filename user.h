#ifndef USER_H
#define USER_H
#include "player.h"
#include "treasure.h"
#include "trap.h"
#include "opponent.h"

class User: public Player{
    int userHealth;
    int numTreasures;
    public:
        
        User();
        User(string, int, int, int, int);
        User(const User&);

        int getUserHealth();
        int getNumTreasures();

        void setUserHealth(int);
        void setNumTreasures(int);

        bool checkWin();//checks if user has reached 3 treasures
        bool checkLose();//checks if user has lost all health
        void playerMove(Board&);//implementation of pure virtual method, moves user around board based on direction input
        
        User& operator+(const Treasure&);//adds 1 to treasure count
        User& operator-(const Trap&);//subtracts 20 from health
        User& operator-(const Opponent&);//subtracts 30 from health

        friend ostream& operator<<(ostream&, User&);//displays stats

};

#endif