#include "printcommandsheet.h"
#include <iostream>

void printCommandSheet(){
    std::cout << "\nCommands:" << std::endl;
    std::cout << "| [\033[32mC\033[0m] \033[33mcommands\033[0m" << std::endl;
    std::cout << "| [\033[32mM\033[0m] \033[33mstats\033[0m" << std::endl;
    std::cout << "| [\033[32mF\033[0m] \033[33mquests\033[0m" << std::endl;
    std::cout << "| [\033[32mI\033[0m] \033[33minventory\033[0m" << std::endl;
    std::cout << "| [\033[32mG\033[0m] \033[33mbuy items\033[0m" << std::endl;
    std::cout << "| [\033[32mD\033[0m] \033[33msell items\033[0m" << std::endl;
    std::cout << "| [\033[32mT\033[0m] \033[33mcraft items\033[0m" << std::endl;
    std::cout << "| [\033[32mR\033[0m] \033[33mscavenge\033[0m" << std::endl;
    std::cout << "| [\033[32mQ\033[0m] \033[33mclear screen\033[0m" << std::endl;
    std::cout << "| [\033[32mS\033[0m] \033[33msave game\033[0m" << std::endl;
    std::cout << "| [\033[32mE\033[0m] \033[33mexit\033[0m" << std::endl;
}
