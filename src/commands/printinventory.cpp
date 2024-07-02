#include "printinventory.h"
#include "inventory.h"

#include <iostream>

void printInventory(){
    std::cout << "\nInventory:\n";
    std::cout << "{Dust}      > " << dustItem << "\n";
    std::cout << "{String}    > " << stringItem << "\n";
    std::cout << "{Gravel}    > " << gravelItem << "\n";
    std::cout << "{Clay}      > " << clayItem << "\n";
    std::cout << "{Clay bowl} > " << clayBowlItem << "\n";
}