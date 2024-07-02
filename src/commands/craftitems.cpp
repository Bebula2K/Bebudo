#include "craftitems.h"
#include "inventory.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <sys/ioctl.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>


void craftItems() {
    int craftSelection;
    int craftAmount;

    std::cout << "\nCraft items:\n";
    std::cout << "[1] String    > 10x {dust}\n";
    std::cout << "[2] Clay bowl > 10x {clay}\n";
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
    } else {
        std::cout << "Args error...\n";
    }
}