//Bebudo
//Created Jul 1st 2024

#include <iostream>
#include <fstream>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <unistd.h> // for usleep

#include "engine.h"
#include "inventory.h"
#include "commands.h"

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