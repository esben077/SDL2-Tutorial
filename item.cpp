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
    pos.x = 60;
    pos.y = 60;
    image = NULL;
    pos.w = 100;
    pos.h = 200;
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

void item::setRenderer(SDL_Renderer *dest)
{
    ren = dest;
}

void item::setSize(int w, int h)
{
    pos.w = w;
    pos.h = h;
}

void item::setPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}

void item::draw(double angle)
{
    if(image != NULL)
    {   
        // SDL_Point pt; // point to orbit around
        // pt.x = pos.w/2;
        // pt.y = pos.h/2;
        // pt.x += pos.x;
        // pt.y += pos.y;
        SDL_Point *pt = NULL;
        SDL_RenderCopyEx(ren, image, NULL, &pos, angle, pt, SDL_FLIP_NONE); // NULL indicates that we are drawing the whole image
    }
    else
    {
        std::cout << "image is NULL at draw" << std::endl;
    }
}

void item::draw()
{
    if(image != NULL)
    {
        SDL_RenderCopy(ren, image, NULL, &pos); // NULL indicates that we are drawing the whole image
    }
    else
    {
        std::cout << "image is NULL at draw" << std::endl;
    }
}