#include "user.h"
#include "helpers.h"

User::User():Player(){
    userHealth = 100;
    numTreasures = 0;
}
User::User(string n, int x, int y, int uH, int nT):Player(n, x, y){
    userHealth = uH;
    numTreasures = nT;
}
User::User(const User& rhs):Player(rhs){
    userHealth = rhs.userHealth;
    numTreasures = rhs.numTreasures;
}
int User::getUserHealth(){
    return userHealth;
}
int User::getNumTreasures(){
    return numTreasures;
}
void User::setUserHealth(int health){
    userHealth = health;
}
void User::setNumTreasures(int treasures){
    numTreasures = treasures;
}
bool User::checkWin(){
    if(numTreasures >=3){
        return true;
    }
    else{
        return false;
    }
}
bool User::checkLose(){
    if(userHealth <= 0){
        return true;
    }
    else{
        return false;
    }
}
void User::playerMove(Board& board){
    cout << "Enter your move (W/A/S/D): ";//prompts and gets user's move
    char move = getUserInput<char>();
    
    char currentChar = board.getHiddenCharAtIndex(xPos, yPos);
    if(currentChar != 'X'){
        board.placeEntityOnDisplayed(xPos, yPos, '.');//replaces P w/ . when player moves, unless its a trap
    }

    if(move == 'w' || move == 'W'){//moves user desired direction
        xPos--;
    }
    else if(move == 'a' || move == 'A'){
        yPos--;
    }
    else if(move == 's' || move == 'S'){
        xPos++;
    }
    else if(move == 'd' || move == 'D'){
        yPos++;
    }
    else{
        cout << "Invalid move. Enter your move (W/A/S/D): " << endl;
    }

    if(checkInBounds(xPos, yPos)){
        board.placeEntityOnDisplayed(xPos, yPos, 'P');//puts P where user moved 
    }else{
        cout << "Out of bounds. Enter your move (W/A/S/D): " << endl;

        if(move == 'w' || move == 'W'){//boots player back where they were if they tried to move out of bounds
            xPos++;
        }
        else if(move == 'a' || move == 'A'){
            yPos++;
        }
        else if(move == 's' || move == 'S'){
            xPos--;
        }
        else if(move == 'd' || move == 'D'){
            yPos--;
        }
        board.placeEntityOnDisplayed(xPos, yPos, 'P');//puts P where user moved
    }
}
User& User::operator+(const Treasure& treasure){
    numTreasures++;
    return *this;
}
User& User::operator-(const Trap& trap){
    userHealth -= 20;
    return *this;
}
User& User::operator-(const Opponent& opponent){
    userHealth -= 30;
    return *this;
}
ostream& operator<<(ostream& out, User& user){
    out << "Health: " << user.userHealth << " | Treasures: " << user.numTreasures << "/3";
    return out;
}