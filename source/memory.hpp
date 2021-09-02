#include <stdint.h>
namespace C8E {
    class Memory {
        public:
            Memory();
            static const int MAX_MEMORY_ADDR = 4096;
            static const int RESERVED_MEMORY = 512;
            void readRom(char *);
        private:
            uint8_t mem[MAX_MEMORY_ADDR]{};
    };
}