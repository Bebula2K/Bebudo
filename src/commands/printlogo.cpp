#include "printlogo.h"
#include "margin.h"
#include <iostream>

void printLogo(){
    margin();
    std::cout << "██████  ███████ ██████  ██    ██ ██████   ██████  " << std::endl; margin();
    std::cout << "██   ██ ██      ██   ██ ██    ██ ██   ██ ██    ██ " << std::endl; margin();
    std::cout << "██████  █████   ██████  ██    ██ ██   ██ ██    ██ " << std::endl; margin();
    std::cout << "██   ██ ██      ██   ██ ██    ██ ██   ██ ██    ██ " << std::endl; margin();
    std::cout << "██████  ███████ ██████   ██████  ██████   ██████  " << std::endl; margin();
    std::cout << "" << std::endl;
}