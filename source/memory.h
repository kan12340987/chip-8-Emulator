#pragma once
#include <stdint.h>
namespace C8E {
    class Memory {
    public:
            Memory();
            static const int MAX_MEMORY_ADDR = 4096;
            static const int RESERVED_MEMORY = 512;
            int SPRITE_LENGTH;
            void readRom(char *);
            void loadSprite();
            uint8_t mem[MAX_MEMORY_ADDR]{};
        private:
            //uint8_t spriteData[]{};
};
}

