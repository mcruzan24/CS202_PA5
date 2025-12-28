#include "entity.h"

Entity::Entity(){
    xPos = 0;
    yPos = 0;
}
Entity::Entity(int x, int y){
    xPos = x;
    yPos = y;
}
Entity::Entity(const Entity& rhs){
    xPos = rhs.xPos;
    yPos = rhs.yPos;
}
int Entity::getX(){
    return xPos;
}
int Entity::getY(){
    return yPos;
}
void Entity::setX(int x){
    xPos = x;
}
void Entity::setY(int y){
    yPos = y;
}
ostream& operator<<(ostream& out, const Entity& entity){
    out << "Entity Position: (" << entity.xPos << ", " << entity.yPos << ")";
    return out;
}