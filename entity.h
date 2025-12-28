#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
using namespace std;

class Entity{
    protected:
    int xPos;
    int yPos;
    public:
        Entity();
        Entity(int, int);
        Entity(const Entity&);

        int getX();
        int getY();

        void setX(int);
        void setY(int);

        friend ostream& operator<<(ostream& out, const Entity& entity);
};
#endif