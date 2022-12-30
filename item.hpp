#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// loose function not in class
void itemInit();
void itemQuit();

class item
{
public:
    item();
    virtual ~item();
    bool loadImage(std::string filename);
    void draw(SDL_Surface *dest );

private:
    SDL_Surface *image;
    SDL_Rect pos;

};

#endif