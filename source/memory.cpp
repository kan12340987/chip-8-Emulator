#include <iostream>
#include <fstream>
#include "memory.hpp"
namespace C8E {
    Memory::Memory() {

    }
    void Memory::readRom(char *romfile) {
        try {
            std::ifstream f1 (romfile, std::ios::binary);
        } catch (char *romfile) {
            std::cout << "File can't be opened" << std::endl;
            exit(0);
        }

    }
}