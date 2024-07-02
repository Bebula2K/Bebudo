#include "margin.h"
#include <iostream>
#include <iomanip>
#include <sys/ioctl.h>
#include <thread>
#include <chrono>
#include <ctime>

void margin(){
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    //Minus the length of text in cols divide by 2 again
    int leftMargin = w.ws_col / 2 - 25;
    for (int i=0;i<leftMargin;i++){
        std::cout << ' ';
    }

}