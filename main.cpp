// #include <iostream>
//#include <SDL2/SDL.h>
#include <ctime>
// #include <cstdlib>s
#include <vector>
#include "item.hpp"
//mingw32-make
const int WIDTH = 600, HEIGHT = 500;

int main ( int arcg, char *argv[])
{
    srand(time(NULL));
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

    // make vector with stone items
    std::vector <item *> diamonds;
    int maxDiamonds = 10;
    for(int i = 0; i < maxDiamonds; i++)
    {
        diamonds.push_back(new item());
        diamonds[i]->setRenderer(screen);
        diamonds[i]->loadImage("graphics/diamond.png");
        diamonds[i]->setPos(rand() % 550, rand() % 450);
        diamonds[i]->setSize(50, 50);
    }



    double angle = 0;
    int speedX = 0;
    int speedY = 0;

    bool run = true;
                        //(renderer, R, G, B, alpha)
    SDL_SetRenderDrawColor(screen, 30, 180, 20, 255);
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

        SDL_RenderClear(screen);

        bob.draw(); // draw the player
        //draw the diamonds
        for(int i = 0; i < maxDiamonds; i++)
        {
            if( SDL_HasIntersection(bob.getPos(), diamonds[i]->getPos()) )
            {
                diamonds.erase(diamonds.begin()+i); // remove item from vector
                maxDiamonds--;
            }
            else
            {
            diamonds[i]->draw(angle);
            }
        }
        SDL_RenderPresent(screen);

        SDL_Delay(30);
        angle++;

    }

    SDL_DestroyWindow ( window );
    SDL_Quit();

    return EXIT_SUCCESS;
}