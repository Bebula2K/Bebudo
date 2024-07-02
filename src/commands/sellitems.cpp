#include "sellitems.h"
#include "inventory.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <sys/ioctl.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>

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

    if (sellIDshop == 1) { //Sell Dust
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
    } else if (sellIDshop == 2) { //Sell String
        std::cout << "How many do you want to sell? > ";
        if (!(std::cin >> sellAmount)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            return; // Exit the function
        }

        if (sellAmount <= stringItem) {
            stringItem -= sellAmount;
            money += 0.0000000005 * sellAmount;
            std::cout << "Sold " << sellAmount << " Of item ID " << sellIDshop << std::endl;
        } else {
            std::cout << "Error selling item...\n";
        }
    } else if (sellIDshop == 3) { //Sell gravel
        std::cout << "How many do you want to sell? > ";
        if (!(std::cin >> sellAmount)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            return; // Exit the function
        }

        if (sellAmount <= gravelItem) {
            gravelItem -= sellAmount;
            money += 0.0000000002 * sellAmount;
            std::cout << "Sold " << sellAmount << " Of item ID " << sellIDshop << std::endl;
        } else {
            std::cout << "Error selling item...\n";
        }
    } else if (sellIDshop == 4) { //Sell clay
        std::cout << "How many do you want to sell? > ";
        if (!(std::cin >> sellAmount)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            return; // Exit the function
        }

        if (sellAmount <= clayItem) {
            clayItem -= sellAmount;
            money += 0.0000000007 * sellAmount;
            std::cout << "Sold " << sellAmount << " Of item ID " << sellIDshop << std::endl;
        } else {
            std::cout << "Error selling item...\n";
        }
    } else if (sellIDshop == 4) { //Sell clay bowls
        std::cout << "How many do you want to sell? > ";
        if (!(std::cin >> sellAmount)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            return; // Exit the function
        }

        if (sellAmount <= clayBowlItem) {
            clayBowlItem -= sellAmount;
            money += 0.0000000105 * sellAmount;
            std::cout << "Sold " << sellAmount << " Of item ID " << sellIDshop << std::endl;
        } else {
            std::cout << "Error selling item...\n";
        }
    } else {
        std::cout << "Args error...\n";
    }
}