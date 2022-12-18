#include <iostream>
#include <SDL2/SDL.h>
//mingw32-make
const int WIDTH = 1200, HEIGHT = 1200;

int main ( int arcg, char *argv[])
{
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow( "Hello SDL world!",  
                                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                            WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI  );

    if ( NULL == window )
    {
        std::cout << "Could not create window: " << SDL_GetError( ) << std::endl;
        return 1;
    }

    //SDL_Surface *screen = SDL_GetWindowSurface(window);

    SDL_Event windowEvent;

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
    }

    SDL_DestroyWindow ( window );
    SDL_Quit( );

    return EXIT_SUCCESS;
}