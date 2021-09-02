#include <iostream>
#include "CPU.hpp"

#include <chrono>
#include <ctime>
namespace C8E {
    Cpu::Cpu(Memory* memory, Display* display, double instructionPerSec) {
        this-> memory = memory;
        this->display = display;
        quit = false;
        unitTime = (1.0 * 1000000)/ instructionPerSec;
    }
    void Cpu::cpuGameLoop(const int instructionPerSec) {
        previous = std::clock();
        
        while(!quit) {
            while (SDL_PollEvent( &e ) != 0)
            {
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
            }
            Cycle();
        }
    }
    void Cpu::Cycle() {
        current = std::clock();
        diff = current - previous;
        if(diff >= unitTime) {
            getInstruction();
            //executeInstruction();
            previous = current;
            //total++;
        }

    }
    void Cpu::getInstruction() {
        opcode = (memory -> mem[pc] << 8) | (memory -> mem[pc+1]);
        pc += 2;
        //std::cout << opcode<<std::endl;
    }
    //******Incomplete Implementation
    void Cpu::executeInstruction() {
        switch(opcode & 0xF000) {
            case 0x0000:
                switch (opcode & 0x0FFF)
                {
                case 0x00E0:
                    display->clear();
                    break;
                } 
                break;
            case 0xD000:
                RegiX = (opcode & 0x0F00);
                RegiY = (opcode & 0x00F0);
                uint16_t spriteLength = (opcode & 0x000F);
                for(int i = 0; i < spriteLength; i++) {
                    
                }
                break;  
        }
        
    }
}