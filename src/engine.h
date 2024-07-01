/*Bebtek engine v2*/
/*More optimized and faster version of Bebtek engine v1*/
/*Created Dec 16th, 2023*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <termios.h>
#include <fstream>

#include "commands.h"
#include "inventory.h"

class Engine {
public:
    void waitForInput() {
        setTerminalMode();
        char c;
        while (true) {
            std::cout << "[" << username << "]>";
            std::cin.get(c);
            if (c == 'm') {
                printStats();
            } else if (c == 'e') {
                system("clear");
                break;
            } else if (c == 'c') {
                printCommandSheet();
            } else if (c == 'q') {
                system("clear");
            } else if (c == 's') {
                saveGame();
            } else if (c == 'r') {
                scavenge();
            } else if (c == 'i') {
                printInventory();
            } else if (c == 'd') {
                sellItems();
            }  else {
                std::cout << "" << std::endl;
            }
        }
        restoreTerminalMode();
    }
private:
    struct termios originalTermios;

    void setTerminalMode() {
        tcgetattr(STDIN_FILENO, &originalTermios);

        struct termios newTermios = originalTermios;
        newTermios.c_lflag &= ~ICANON; // Disable canonical mode
        newTermios.c_lflag &= ~ECHO;   // Disable echoing input characters

        tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
    }

    void restoreTerminalMode() {
        tcsetattr(STDIN_FILENO, TCSANOW, &originalTermios);
    }
};