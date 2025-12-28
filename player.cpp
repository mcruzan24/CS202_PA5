#include "player.h"

Player::Player(){
    name = "";
    xPos = 0;
    yPos = 0;
}
Player::Player(string n, int x, int y){
    name = n;
    xPos = x;
    yPos = y;
}
Player::Player(const Player& rhs){
    name = rhs.name;
    xPos = rhs.xPos;
    yPos = rhs.yPos;
}
string Player::getName(){
    return name;
}
int Player::getX(){
    return xPos;
}
int Player::getY(){
    return yPos;
}
void Player::setName(string n){
    name = n;
}
void Player::setX(int x){
    xPos = x;
}
void Player::setY(int y){
    yPos = y;
}