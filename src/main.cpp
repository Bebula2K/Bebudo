//Bebudo
//Created Jul 1st 2024

#include <iostream>
#include <fstream>
#include <unistd.h> // for usleep

#include "engine.h"
#include "commands/inventory.h"
#include "commands/craftitems.h"
#include "commands/loadgame.h"
#include "commands/savegame.h"
#include "commands/margin.h"
#include "commands/printcommandsheet.h"
#include "commands/printinventory.h"
#include "commands/printlogo.h"
#include "commands/printstats.h"
#include "commands/quests.h"
#include "commands/scavenge.h"
#include "commands/sellitems.h"
#include "commands/shop.h"

std::string username = "";

int main(){
    system("clear");
    printLogo();
    loadGame();
    if (username.empty()) {
        std::cout << "Enter a username: ";
        std::cin >> username;
        saveGame();
        system("clear");
    } else {
        system("clear");
        printLogo();
        std::cout << "";
    }
    Engine engine;
    engine.waitForInput();
    return 0;
}