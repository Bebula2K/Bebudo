#include "printinventory.h"
#include "inventory.h"

#include <iostream>

void printInventory(){
    std::cout << "\nInventory:\n";
    std::cout << "{\033[32mDust\033[0m}      > \033[33" << dustItem << "\033[0m\n";
    std::cout << "{\033[32mString\033[0m}    > \033[33" << stringItem << "\033[0m\n";
    std::cout << "{\033[32mGravel\033[0m}    > \033[33" << gravelItem << "\033[0m\n";
    std::cout << "{\033[32mClay\033[0m}      > \033[33" << clayItem << "\033[0m\n";
    std::cout << "{\033[32mClay bowl\033[0m} > \033[33" << clayBowlItem << "\033[0m\n";
}
