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
    // default values for the image
    // TODO: change the default values for pos
    pos.x = 30;
    pos.y = 60;
    image = NULL;
    pos.w = 8;
    pos.h = 16;
}

item::~item()
{
    if(image != NULL)
    {
        SDL:SDL_DestroyTexture(image);
        image = NULL;
    }
}
bool item::loadImage(std::string filename)
{
    // remove old surface if present. (Surface was made in constructor)
    if(image != NULL)
    {
        SDL:SDL_DestroyTexture(image);
        image = NULL;
    }
    // load the image to a temporary surface
    SDL_Surface *temp = IMG_Load(filename.c_str());
    if(temp != NULL)
    {
        image = SDL_CreateTextureFromSurface(ren, temp);
        SDL_FreeSurface(temp);
        if(image != NULL)
        {
            return true;
        }
    }
        return false;
}
void item::set_renderer(SDL_Renderer *dest)
{
    ren = dest;
}

void item::draw()
{
    if(image != NULL)
    {
        SDL_RenderCopy(ren, image, NULL, &pos);
    }
    else
    {
        std::cout << "image is NULL at draw" << std::endl;
    }
}