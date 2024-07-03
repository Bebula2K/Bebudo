#include "craftitems.h"
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


void craftItems() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int random_number = std::rand() % 2;
    int craftSelection;
    int craftAmount;

    std::cout << "\nCraft items:\n";
    std::cout << "[1] String    > 10x {dust}\n";
    std::cout << "[2] Clay bowl > 10x {clay}\n";
    std::cout << "[3] Flint     > 1x  {gravel} (50% chance of success)\n";
    std::cout << "What would you like to craft? > ";
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
    } else if (craftSelection == 2) {
        std::cout << "How many would you like to craft? > ";
        if (!(std::cin >> craftAmount)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            return; // Exit the function
        }

        if (clayItem >= 10 * craftAmount) {
            clayItem -= (10 * craftAmount);
            clayBowlItem += craftAmount;
            std::cout << "Crafted " << craftAmount << " {clay bowl('s)}!\n";
        } else {
            std::cout << "Error crafting items...\n";
        }
    } else if (craftSelection == 3) {
        std::cout << "How many would you like to craft? > ";
        if (!(std::cin >> craftAmount)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            return; // Exit the function
        }

        if (gravelItem >= 1 * craftAmount && random_number == 0 && craftAmount <= 1 && craftAmount != 0) {
            gravelItem -= (1 * craftAmount );
            flintItem += craftAmount;
            std::cout << "Crafted " << craftAmount << " {flint}!\n";
        } else if (random_number != 0) {
            std::cout << "Crafting failed!\n";
            gravelItem--;
        } else{
            std::cout << "Error crafting items... (You can only craft 1 at a time!)\n";
        }
    } else {
        std::cout << "Args error...\n";
    }
}
