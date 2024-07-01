#include "commands.h"
#include "inventory.h"

#include <iostream>
#include <string>
#include <iomanip>

void printMoney(){
std::cout << std::fixed << std::setprecision(10) << money << "$" << std::endl;
}

void printCommandSheet(){
    std::cout << "\nCommands:" << std::endl;
    std::cout << "| [C] commands" << std::endl;
    std::cout << "| [E] exit game" << std::endl;
    std::cout << "| [M] print money" << std::endl;
    std::cout << "| [Q] clear screen" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
}