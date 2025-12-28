#include "treasure.h"

Treasure::Treasure():Entity(){
}
Treasure::Treasure(int x, int y):Entity(x,y){
}
Treasure::Treasure(const Treasure& rhs):Entity(rhs){
}