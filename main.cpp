// #include <iostream>
//#include <SDL2/SDL.h>
#include "item.hpp"
//mingw32-make
const int WIDTH = 1200, HEIGHT = 1200;

int main ( int arcg, char *argv[])
{
    // SDL_Init( SDL_INIT_EVERYTHING );
    itemInit();

    SDL_Window *window = SDL_CreateWindow( "Hello SDL world!",  
                                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                            WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI  );

    if (window == NULL)
    {
        std::cout << "Could not create window: " << SDL_GetError( ) << std::endl;
        return 1;
    }

    SDL_Renderer *screen = SDL_CreateRenderer(window, -1, 0);

    SDL_Event windowEvent;

    item bob;
    bob.setRenderer(screen);
    bob.loadImage("graphics/player_front.png");
    bob.setPos(30, 30);
    bob.setSize(100, 200);

    int speedX = 0;
    int speedY = 0;

    bool run = true;
    while ( run )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            switch(windowEvent.type)
            {
            case SDL_QUIT:
                run = false;
                std::cout << "exit and closing window" << std::endl;
                break;
            case SDL_KEYDOWN:
                    // check which key is pressed down
                    switch (windowEvent.key.keysym.sym)
                    {
                    case SDLK_UP:
                        speedY = -5;
                        break;
                    case SDLK_DOWN:
                        speedY = 5;
                        break;
                    case SDLK_LEFT:
                        speedX = -5;
                        break;
                    case SDLK_RIGHT:
                        speedX = 5;
                        break;
                    }
                break;
            case SDL_KEYUP:
                    switch (windowEvent.key.keysym.sym)
                    {
                    case SDLK_UP:
                        speedY = 0;
                        break;
                    case SDLK_DOWN:
                        speedY = 0;
                        break;
                    case SDLK_LEFT:
                        speedX = 0;
                        break;
                    case SDLK_RIGHT:
                        speedX = 0;
                        break;
                    }
                break;
            }

        }
        bob.move(speedX, speedY);

        bob.draw();
        SDL_RenderPresent(screen);

        SDL_Delay(30);
        SDL_RenderClear(screen);
    }

    SDL_DestroyWindow ( window );
    SDL_Quit();

    return EXIT_SUCCESS;
}