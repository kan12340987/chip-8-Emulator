#include <iostream>
#include "memory.h"
#include<chrono>
#include "display.hpp"
#include "CPU.hpp"
using namespace std; 
static const int SCREEN_WIDTH = 1280;
static const int SCREEN_HEIGHT = 640;
static const double INSTRUCTION_PER_SECOND = 70;
int main (int argc, char *argv[]) {
    if(argc < 2) {
        cout << "No Roms found. Please try again." << endl;
        exit(0);
    } else {
        //std::cout << "hello" << endl;
        C8E::Memory memory = C8E::Memory();         
        memory.readRom(argv[1]);
        C8E::Display display = C8E::Display(SCREEN_WIDTH, SCREEN_HEIGHT, 10);
        C8E::Cpu cpu = C8E::Cpu(&memory, &display, INSTRUCTION_PER_SECOND);
        //cpu.cpuGameLoop(INSTRUCTION_PER_SECOND);
        display.setPixels(60,0, 1);
        SDL_Delay(2000);
        //display.setPixels(60,61, 1);
        //display.setPixels(100,0, 1);
        SDL_Delay(2000);
    }


}  
