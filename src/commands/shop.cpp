#include "shop.h"
#include "inventory.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <sys/ioctl.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>

void shop() {
    int buyAmount;
    int buyItemID;

    std::cout << "Shop:\n";
    std::cout << "What would you like to buy? \n";
    std::cout << "[1] gravel\n";
    std::cout << "[2] clay\n";
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
        if (buyAmount >= 0.0000000003 && money >= (buyAmount * 0.0000000003)) {
            gravelItem += buyAmount;
            money -= 0.0000000003 * buyAmount;
            std::cout << "You have bought " << buyAmount << " gravel.\n";
        } else {
            std::cout << "Not enough money...\n";
        }
    } else if (buyItemID == 2) {
        std::cout << "How many would you like to buy? > ";

        // Read buyAmount
        if (!(std::cin >> buyAmount)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            return; // Exit the function
        }

        // Process the purchase
        if (buyAmount >= 0.0000000010 && money >= (buyAmount * 0.0000000010)) {
            clayItem += buyAmount;
            money -= 0.0000000010 * buyAmount;
            std::cout << "You have bought " << buyAmount << " clay.\n";
        } else {
            std::cout << "Not enough money...\n";
        }
    } else {
        std::cout << "Args error...\n";
    }
}
