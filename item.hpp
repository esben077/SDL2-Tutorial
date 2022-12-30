#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>
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
    void set_renderer(SDL_Renderer *renderer);
    bool loadImage(std::string filename);
    void draw();

private:
    SDL_Renderer *ren;
    SDL_Texture *image;
    SDL_Rect pos;

};

#endif