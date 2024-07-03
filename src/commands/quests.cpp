#include "quests.h"
#include "inventory.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <sys/ioctl.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <ctime>

void quests(){
    std::string completeQuestOption;
    std::cout << "\nQuests:";
    std::cout << "Quests complete: " << questsDone << ".\n";
    std::cout << "Current quest: Obtain 10 string\n";
    std::cout << "Complete quest? y/n > ";
    std::cin >> completeQuestOption;
    if(completeQuestOption == "y"){
        if(stringItem >= 10 && questsDone == 0){
        questsDone++;
        stringItem -= 10;
        money += 0.0000000010;
        std::cout << "Quest complete!\n";
    } else {
        std::cout << "Insufficient materials...\n";
    }
    } else if(completeQuestOption == "y"){
        if(clayBowlItem >= 1 && questsDone == 1){
        questsDone++;
        clayBowlItem -= 1;
        money += 0.0000000050;
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