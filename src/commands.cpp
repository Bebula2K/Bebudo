#include "commands.h"
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

void printLogo(){
    margin();
    std::cout << "██████  ███████ ██████  ██    ██ ██████   ██████  " << std::endl; margin();
    std::cout << "██   ██ ██      ██   ██ ██    ██ ██   ██ ██    ██ " << std::endl; margin();
    std::cout << "██████  █████   ██████  ██    ██ ██   ██ ██    ██ " << std::endl; margin();
    std::cout << "██   ██ ██      ██   ██ ██    ██ ██   ██ ██    ██ " << std::endl; margin();
    std::cout << "██████  ███████ ██████   ██████  ██████   ██████  " << std::endl; margin();
    std::cout << "" << std::endl;
}

void printStats(){
std::cout << std::endl;
std::cout << "Money > " << std::fixed << std::setprecision(10) << money << "$" << std::endl;
std::cout << "Level > " << level << std::endl;
}

void printCommandSheet(){
    std::cout << "\nCommands:" << std::endl;
    std::cout << "| [C] commands" << std::endl;
    std::cout << "| [E] exit" << std::endl;
    std::cout << "| [M] stats" << std::endl;
    std::cout << "| [Q] clear screen" << std::endl;
    std::cout << "| [R] scavenge" << std::endl;
    std::cout << "| [I] inventory" << std::endl;
    std::cout << "| [D] sell items" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "|" << std::endl;
    std::cout << "| [S] save game" << std::endl;
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

        std::string dustStr;
        std::getline(infile, dustStr);
        dust = std::stoi(dustStr); // Convert string to int
        
        infile.close();
    }
}

void saveGame(){
    std::ofstream outfile("save.txt");
    if (outfile.is_open()) {
        outfile << username << "\n";
        outfile << money << "\n";
        outfile << level << "\n";
        outfile << dust << "\n";
        outfile.close();
    }
    std::cout << "\n";
}

void scavenge(){
    std::srand(static_cast<unsigned int>(std::time(nullptr))); //Include this in ever random action or event !!!
    int random_number = std::rand() % 5;
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
        dust++;
        } else {
        std::cout << "Scavenge failed...\n";
        }
    }
}

void printInventory(){
    std::cout << "\nInventory:\n";
    std::cout << "{Dust} > " << dust << "\n";
}

void sellItems(){
    int sellIDshop;
    int sellAmount;
    std::cout << "Enter the item ID to sell (refer to itemIDs.txt) > ";
    std::cin >> sellIDshop;
    if(sellIDshop == 1){
        std::cout << "How many do you want to sell? > ";
        std::cin >> sellAmount;
        if(sellAmount <= dust){
            dust = dust - sellAmount;
            money += 0.0000000100 * sellAmount;
            std::cout << "Sold " << sellAmount << " Of item ID " << sellIDshop << std::endl;
        } else{
            std::cout << "Error selling item...\n";
        }
    } else {
        std::cout << "Args error...\n";
    }
}