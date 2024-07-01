//Bebudo
//Created Jul 1st 2024

#include <iostream>
#include <fstream>
#include "engine.h"
#include "inventory.h"

std::string username = "";

void loadUsername() {
    std::ifstream infile("save.txt");
    if (infile.is_open()) {
        std::getline(infile, username);
        infile.close();
    }
}

void saveUsername() {
    std::ofstream outfile("save.txt");
    if (outfile.is_open()) {
        outfile << username;
        outfile.close();
    }
}

int main(){
    system("clear");
    loadUsername();
    if (username.empty()) {
        std::cout << "Enter a username: ";
        std::cin >> username;
        saveUsername();
    } else {
        system("clear");
        std::cout << "\n";
    }
    Engine engine;
    engine.waitForInput();
    return 0;
}