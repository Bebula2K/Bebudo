#include "printcommandsheet.h"
#include <iostream>

void printCommandSheet(){
    std::cout << "\nCommands:" << std::endl;
    std::cout << "| [C] commands" << std::endl;
    std::cout << "| [M] stats" << std::endl;
    std::cout << "| [F] quests" << std::endl;
    std::cout << "| [I] inventory" << std::endl;
    std::cout << "| [G] buy items" << std::endl;
    std::cout << "| [D] sell items" << std::endl;
    std::cout << "| [T] craft items" << std::endl;
    std::cout << "| [R] scavenge" << std::endl;
    std::cout << "| [Q] clear screen" << std::endl;
    std::cout << "| [S] save game" << std::endl;
    std::cout << "| [E] exit" << std::endl;
}