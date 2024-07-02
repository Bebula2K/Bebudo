#include "printstats.h"
#include "inventory.h"
#include <iostream>
#include <iomanip>

void printStats(){
std::cout << std::endl;
std::cout << "Money > " << std::fixed << std::setprecision(10) << money << "$" << std::endl;
std::cout << "Level > " << level << std::endl;
std::cout << "Quests complete: " << questsDone << std::endl;
}