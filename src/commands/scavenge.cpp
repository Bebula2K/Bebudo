#include "scavenge.h"
#include "inventory.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <sys/ioctl.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <random> //Muahahahahahaha
#include <ctime>

void scavenge(){
    std::srand(static_cast<unsigned int>(std::time(nullptr))); //Include this in ever random action or event !!!
    int random_number = std::rand() % 3;
    int opt;
    std::cout << "Scavenge:\n";
    std::cout << "[1] Dust\n";
    //std::cout << ""
    std::cout << "Enter option > ";
    std::cin >> opt;
    if (level <= 1){
        std::cout << "Scavenging for dust...\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        if (random_number == 0) {
        std::cout << "Dust obtained!\n";
        dustItem++;
        } else {
        std::cout << "Scavenge failed...\n";
        }
    }
}