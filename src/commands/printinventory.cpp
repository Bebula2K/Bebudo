#include "printinventory.h"
#include "inventory.h"

#include <iostream>

void printInventory(){
    std::cout << "\nInventory:\n";
    std::cout << "{\033[32mDust\033[0m}      > " << dustItem << "\n";
    std::cout << "{\033[32mString\033[0m}    > " << stringItem << "\n";
    std::cout << "{\033[32mGravel\033[0m}    > " << gravelItem << "\n";
    std::cout << "{\033[32mClay\033[0m}      > " << clayItem << "\n";
    std::cout << "{\033[32mClay bowl\033[0m} > " << clayBowlItem << "\n";
}
