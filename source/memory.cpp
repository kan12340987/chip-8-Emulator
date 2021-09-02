#include <iostream>
#include <fstream>
#include "memory.h"
namespace C8E {
    
    uint8_t spriteData[] = {
                0xF0, 0x90, 0x90, 0x90, 0x70, //0
                0x20, 0x60, 0x20, 0x20, 0x70, //1
                0xF0, 0x10, 0xF0, 0x80, 0xF0, //2
                0xF0, 0x10, 0xF0, 0x10, 0xF0, //3
                0x90, 0x90, 0xF0, 0x10, 0x10, //4
                0xF0, 0x80, 0xF0, 0x10, 0xF0, //5                                
                0xF0, 0x80, 0xF0, 0x90, 0xF0, //6
                0xF0, 0x10, 0x20, 0x40, 0x40, //7  
                0xF0, 0x90, 0xF0, 0x90, 0xF0, //8
                0xF0, 0x90, 0xF0, 0x10, 0xF0, //9
                0xF0, 0x90, 0xF0, 0x90, 0x90, //A  
                0xE0, 0x90, 0xE0, 0x90, 0xE0, //B
                0xF0, 0x80, 0x80, 0x80, 0xF0, //C
                0xE0, 0x90, 0x90, 0x90, 0xE0, //D
                0xF0, 0x80, 0xF0, 0x80, 0xF0, //E
                0xF0, 0x80, 0xF0, 0x80, 0x80, //F          

    };
    Memory:: Memory() {
        loadSprite();
    }
    void Memory::readRom(char *romfile) {
            try {
                std::ifstream f1 (romfile, std::ios::binary);
                if(!f1.is_open()) {
                    std::cout << "File cannot be opened" << std::endl;
                    exit(0);
                }
                int counter = 0;
                //int filesize = 0;
                char buf[1];
                while(!f1.eof()) {
                    f1.read(buf, 1);
                    //filesize = f1.gcount();
                    if(counter > MAX_MEMORY_ADDR) {
                        std::cout << "File is too big" << std::endl;
                        exit(0);
                    }
                    mem[RESERVED_MEMORY + counter] = buf[0];
                    //std::cout << mem[RESERVED_MEMORY + counter];
                    counter++;
                }
                        /*for(int i = 0; i < 80; i++) {
                        std::cout << mem[RESERVED_MEMORY + i];

                    }*/
                    //std::cout << "hello";
            } catch (char *romfile) {
                std::cout << "File can't be opened" << std::endl;
                exit(0);
           }
    }
    void Memory::loadSprite() {
        for(int i = 0; i < 80; i++) {
            mem[i] = spriteData[i];

        }
    }
}



