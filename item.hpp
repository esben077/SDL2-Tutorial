#ifndef ITEM_HPP
#define ITEM_HPP

#include <SDL2/SDL.h>

class item
{
public:
    item();
    virtual ~item();
    void draw(SDL_Surface *dest );

private:
    SDL_Surface *image;
    SDL_Rect pos;

};

#endif