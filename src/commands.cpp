#include "commands.h"
#include "inventory.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <sys/ioctl.h>

void printLogo(){
    margin();
    std::cout << "██████  ███████ ██████  ██    ██ ██████   ██████  " << std::endl; margin();
    std::cout << "██   ██ ██      ██   ██ ██    ██ ██   ██ ██    ██ " << std::endl; margin();
    std::cout << "██████  █████   ██████  ██    ██ ██   ██ ██    ██ " << std::endl; margin();
    std::cout << "██   ██ ██      ██   ██ ██    ██ ██   ██ ██    ██ " << std::endl; margin();
    std::cout << "██████  ███████ ██████   ██████  ██████   ██████  " << std::endl; margin();
    std::cout << "" << std::endl;
}

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

void margin(){
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    //Minus the length of text in cols divide by 2 again
    int leftMargin = w.ws_col / 2 - 25;
    for (int i=0;i<leftMargin;i++){
        std::cout << ' ';
    }

}

void clearScreen(){
    system("clear");
}