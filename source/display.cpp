#include<iostream>
#include "display.hpp"
namespace C8E {
    Display::Display(int SCREEN_WIDTH, int SCREEN_HEIGHT, int scale) {

        pixelWidth = SCREEN_WIDTH/ ACTUAL_WIDTH;
        pixelHeight = SCREEN_HEIGHT/ ACTUAL_HEIGHT;
        if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
            printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
            exit(0);
        }
        
        window = SDL_CreateWindow("Emulator",  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if(window == NULL) {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            exit(0);
        }
        screenSurface = SDL_GetWindowSurface(window);
        renderer = SDL_CreateRenderer(window, 0, 0);
        texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, 64, 32);
        quit = false;


    }
    void Display::clear() {
        std::fill(pixelArray, pixelArray + ACTUAL_WIDTH*ACTUAL_HEIGHT, 0);

 		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer); 
    }  
    void Display::setPixels(int x, int y, uint8_t bit) {
        //std::cout << "hello";
        int pixel_no = x + y * ACTUAL_WIDTH;
        pixelArray[pixel_no] = bit & 1;
        uint8_t color = (bit & 1) * 255;
        SDL_Rect rect;
        rect.x = x * pixelWidth;
        rect.y = y * pixelHeight;  
        rect.w = pixelWidth;
        rect.h = pixelHeight;
		SDL_SetRenderDrawColor(renderer, color, color, color, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);    
    }
} 