#include "item.hpp"

void itemInit()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    // IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | ...); // for multiple typyes
}
void itemQuit()
{
    SDL_Quit();
    IMG_Quit();
}

item::item()
{
    pos.x = 30;
    pos.y = 60;
    //empty surface with height=100 and width=200
    image = SDL_CreateRGBSurface(0, 100, 200, 32, 0,0,0,0);
    //extracting width and height from image
    pos.w = image->clip_rect.w;
    pos.h = image->clip_rect.h;
    SDL_FillRect(image, NULL, 0xffff00);
}

item::~item()
{
    if(image != NULL)
    {
        SDL:SDL_FreeSurface(image);
    }
}
bool item::loadImage(std::string filename)
{
    // remove old surface if present. (Surface was made in constructor)
    if(image != NULL)
    {
        SDL:SDL_FreeSurface(image);
    }
    image = IMG_Load(filename.c_str());
    if(image != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void item::draw(SDL_Surface *dest)
{
    if(image != NULL)
    {
        SDL_BlitSurface(image, NULL, dest, &pos);
    }
}