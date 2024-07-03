#include "loadgame.h"
#include "inventory.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <sys/ioctl.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>

void loadGame() {
    std::ifstream infile("save.txt");
    if (infile.is_open()) {
        std::getline(infile, username);
        
        std::string moneyStr;
        std::getline(infile, moneyStr);
        money = std::stod(moneyStr); // Convert string to double
        
        std::string levelStr;
        std::getline(infile, levelStr);
        level = std::stoi(levelStr); // Convert string to int

        std::string questsDoneStr;
        std::getline(infile, questsDoneStr);
        questsDone = std::stoi(questsDoneStr); // Convert string to int

        std::string dustItemStr;
        std::getline(infile, dustItemStr);
        dustItem = std::stoi(dustItemStr); // Convert string to int

        std::string stringItemStr;
        std::getline(infile, stringItemStr);
        stringItem = std::stoi(stringItemStr); // Convert string to int

        std::string clayItemStr;
        std::getline(infile, clayItemStr);
        clayItem = std::stoi(clayItemStr); // Convert string to int

        std::string clayBowlItemStr;
        std::getline(infile, clayBowlItemStr);
        clayBowlItem = std::stoi(clayBowlItemStr); // Convert string to int

        std::string flintItemStr;
        std::getline(infile, flintItemStr);
        flintItem = std::stoi(flintItemStr); // Convert string to int
        
        infile.close();
    }
}
