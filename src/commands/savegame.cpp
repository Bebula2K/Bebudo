#include "savegame.h"
#include "inventory.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <sys/ioctl.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>

void saveGame(){
    std::ofstream outfile("save.txt");
    if (outfile.is_open()) {
        outfile << username << "\n";
        outfile << money << "\n";
        outfile << level << "\n";
        outfile << questsDone << "\n";
        outfile << dustItem << "\n";
        outfile << stringItem << "\n";
        outfile << clayItem << "\n";
        outfile << clayBowlItem << "\n";
        outfile.close();
    }
    std::cout << "\033[32mGame saved!\033[0m\n";
}
