#ifndef TREASURE_H
#define TREASURE_H
#include "entity.h"

class Treasure:public Entity{
    public:
        Treasure();
        Treasure(int, int);
        Treasure(const Treasure&);
};
#endif