#include <iostream>
#include<chrono>
#include <fstream>
#include "memory.hpp"
//#include<sdl.h>
using namespace std; 
using namespace C8E;
int main (int argc, char *argv[]) {
    if(argc < 2) {
        cout << "No Roms found. Please try again." << endl;
        exit(0);
    } else {
        Memory memory;         
        memory.readRom(argv[1]);
    }

}  