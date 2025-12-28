#include "trap.h"

Trap::Trap():Entity(){
}
Trap::Trap(int x, int y):Entity(x,y){
}
Trap::Trap(const Trap& rhs):Entity(rhs){
}