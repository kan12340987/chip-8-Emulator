#pragma once
#include <SDL2/SDL.h>
namespace C8E {
    static const int ACTUAL_WIDTH = 64;
    static const int ACTUAL_HEIGHT = 32;
    class Display {
        public:
            static const int scale;
            int pixelWidth;
            int pixelHeight;
            bool quit;
            SDL_Event e;
        Display(int , int , int );
        void clear();
        void render();
        void gameLoop();
        void setPixels(int, int, uint8_t);
        void rendering();
        private:
            SDL_Window *window = NULL;
            SDL_Surface *screenSurface = NULL;
            SDL_Renderer *renderer;
            SDL_Texture *texture;
            uint8_t pixelArray[ACTUAL_WIDTH*ACTUAL_HEIGHT]{};

    };
}