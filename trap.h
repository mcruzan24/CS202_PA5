#ifndef TRAP_H
#define TRAP_H
#include "entity.h"

class Trap:public Entity{
    public:
        Trap();
        Trap(int, int);
        Trap(const Trap&);
};
#endif