#include "item.hpp"

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
    // new surface is being created
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