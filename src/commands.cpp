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
std::cout << "Quests complete: " << questsDone << std::endl;
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
    std::cout << "| [T] craft items" << std::endl;
    std::cout << "| [F] quests" << std::endl;
    std::cout << "| [G] shop" << std::endl;
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

        std::string questsDoneStr;
        std::getline(infile, questsDoneStr);
        questsDone = std::stoi(questsDoneStr); // Convert string to int

        std::string dustItemStr;
        std::getline(infile, dustItemStr);
        dustItem = std::stoi(dustItemStr); // Convert string to int

        std::string stringItemStr;
        std::getline(infile, stringItemStr);
        stringItem = std::stoi(stringItemStr); // Convert string to int
        
        infile.close();
    }
}

void saveGame(){
    std::ofstream outfile("save.txt");
    if (outfile.is_open()) {
        outfile << username << "\n";
        outfile << money << "\n";
        outfile << level << "\n";
        outfile << questsDone << "\n";
        outfile << dustItem << "\n";
        outfile << stringItem << "\n";
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
        dustItem++;
        } else {
        std::cout << "Scavenge failed...\n";
        }
    }
}

void printInventory(){
    std::cout << "\nInventory:\n";
    std::cout << "{Dust}   > " << dustItem << "\n";
    std::cout << "{String} > " << stringItem << "\n";
    std::cout << "{Gravel} > " << gravelItem << "\n";
}

void sellItems() {
    int sellIDshop;
    int sellAmount;

    std::cout << "Enter the item ID to sell (refer to itemIDs.txt) > ";
    if (!(std::cin >> sellIDshop)) {
        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear(); // Clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        return; // Exit the function
    }

    if (sellIDshop == 1) {
        std::cout << "How many do you want to sell? > ";
        if (!(std::cin >> sellAmount)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            return; // Exit the function
        }

        if (sellAmount <= dustItem) {
            dustItem -= sellAmount;
            money += 0.0000000001 * sellAmount;
            std::cout << "Sold " << sellAmount << " Of item ID " << sellIDshop << std::endl;
        } else {
            std::cout << "Error selling item...\n";
        }
    } else if (sellIDshop == 2) {
        std::cout << "How many do you want to sell? > ";
        if (!(std::cin >> sellAmount)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            return; // Exit the function
        }

        if (sellAmount <= stringItem) {
            stringItem -= sellAmount;
            money += 0.0000100000 * sellAmount;
            std::cout << "Sold " << sellAmount << " Of item ID " << sellIDshop << std::endl;
        } else {
            std::cout << "Error selling item...\n";
        }
    } else {
        std::cout << "Args error...\n";
    }
}

void craftItems() {
    int craftSelection;
    int craftAmount;

    std::cout << "\nCraft items:\n";
    std::cout << "[1] String > 10x {dust}\n";
    std::cout << "What would you like to craft? (refer to itemIDs.txt) > ";
    if (!(std::cin >> craftSelection)) {
        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear(); // Clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        return; // Exit the function
    }

    if (craftSelection == 1) {
        std::cout << "How many would you like to craft? > ";
        if (!(std::cin >> craftAmount)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            return; // Exit the function
        }

        if (dustItem >= 10 * craftAmount) {
            dustItem -= (10 * craftAmount);
            stringItem += craftAmount;
            std::cout << "Crafted " << craftAmount << " {string}!\n";
        } else {
            std::cout << "Error crafting items...\n";
        }
    } else {
        std::cout << "Args error...\n";
    }
}

void quests(){
    std::string completeQuestOption;
    std::cout << "\nQuests:";
    std::cout << "Quests complete: " << questsDone << ".\n";
    std::cout << "Current quest: Obtain 10 string\n";
    std::cout << "Complete quest? y/n > ";
    std::cin >> completeQuestOption;
    if(completeQuestOption == "y"){
        if(stringItem >= 10){
        questsDone++;
        stringItem -= 10;
        std::cout << "Quest complete!\n";
    } else {
        std::cout << "Insufficient materials...\n";
    }
    } else if (completeQuestOption == "n"){
        std::cout << "Exited...\n";
    } else {
        std::cout << "Quest error...\n";
    }
}

void shop() {
    int buyAmount;
    int buyItemID;

    std::cout << "Shop:\n";
    std::cout << "What would you like to buy? \n";
    std::cout << "[1] gravel\n";
    std::cout << "> ";

    // Read buyItemID
    if (!(std::cin >> buyItemID)) {
        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear(); // Clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        return; // Exit the function
    }

    // Process based on buyItemID
    if (buyItemID == 1) {
        std::cout << "How many would you like to buy? > ";

        // Read buyAmount
        if (!(std::cin >> buyAmount)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            return; // Exit the function
        }

        // Process the purchase
        if (buyAmount >= 0.0000000003) {
            // Implement your logic for purchasing here
            std::cout << "You have bought " << buyAmount << " gravel.\n";
        } else {
            std::cout << "Not enough money...\n";
        }
    } else {
        std::cout << "Args error...\n";
    }
}