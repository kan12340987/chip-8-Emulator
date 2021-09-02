#pragma once
#include <SDL2/SDL.h>
#include "memory.h"
#include "display.hpp"
namespace C8E {
    class Cpu{
        public:
            Cpu(Memory*, Display*, double);
            void cpuGameLoop(const int);
            void Cycle();
            bool quit;
            float unitTime;
            SDL_Event e;
            //int total = 0;
        private:
            Memory* memory;
            Display* display;

            void getInstruction();
            void executeInstruction();
            int pc = 512;
            uint8_t Registers[16];
            uint16_t RegiI;
            uint16_t Stack[16]{};
            uint16_t opcode;
            uint8_t RegiX;
            uint8_t RegiY;

            clock_t diff;
            clock_t current;
            clock_t previous;
    };

}