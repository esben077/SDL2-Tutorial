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
    bob.set_renderer(screen);
    bob.loadImage("graphics/player_front.png");

    bool run = true;
    while ( run )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if( SDL_QUIT == windowEvent.type )
            {
                run = false;;
                std::cout << "exit and closing window" << std::endl;
            }
        }

        bob.draw();

        
        SDL_RenderPresent(screen);
    }

    SDL_DestroyWindow ( window );
    SDL_Quit();

    return EXIT_SUCCESS;
}