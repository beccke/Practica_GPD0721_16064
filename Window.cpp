#include "Window.h"
#include <iostream>



Window* Window::ptr = nullptr;

Window::Window()
{

}
Window* Window::GetPtr()
{
    if (ptr == nullptr)
    {
        ptr = new Window();
    }
    return ptr;
}

void Window::Init()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Buscaminas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    canvas = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Window::Clear()
{
    SDL_SetRenderDrawColor(canvas, 0, 0, 0, 255);
    SDL_RenderClear(canvas);
}
void Window::Render()
{
    SDL_RenderPresent(canvas);
}
void Window::Input(int& directionX, int& directionY, bool& click, int& mouseX, int& mouseY, int& velocidadx, int& velocidady, int& aceleracionx, int& aceleraciony)
{

    const Uint8* keys = SDL_GetKeyboardState(NULL);
    directionX = 0;
    directionY = 0;
    velocidadx = 0;
    velocidady = 0;
    if (keys[SDL_SCANCODE_UP])
    {
        /*velocidady += aceleraciony * (1 / 60);
        directionY = velocidady * (1 / 60);*/
        directionY = 1;
        //std::cout << "Se presiono arriba";
    }
    else if (keys[SDL_SCANCODE_DOWN])
    {
        /*velocidady += aceleraciony * (1 / 60);
        directionY = -velocidady * (1 / 60);*/
        directionY = -1;
        //std::cout << "Se presiono abajo";
    }
    if (keys[SDL_SCANCODE_RIGHT])
    {
        /*velocidadx += aceleracionx * (1 / 60);
        directionX = velocidadx * (1 / 60);*/
        directionX = 1;

    }
    else if (keys[SDL_SCANCODE_LEFT])
    {
        /*velocidadx += aceleracionx * (1 / 60);
        directionX = -velocidadx * (1 / 60);*/
        directionX = -1;

    }

    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        mouseX = e.motion.x;
        mouseY = e.motion.y;
        if (e.button.type == SDL_MOUSEBUTTONDOWN)
        {
            click = true;
            std::cout << e.button.x << std::endl;
            std::cout << e.button.y << std::endl;
        }
        else
        {
            click = false;
        }
    }
}

SDL_Renderer* Window::GetCanvas()
{
    return canvas;
}

void Window::RenderTexture(Image* image, int x, int y, float angle)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = image->GetWidth();
    dest.h = image->GetHeight();
    SDL_RenderCopyEx(canvas, image->GetTexture(), NULL, &dest, angle, NULL, SDL_FLIP_NONE);
}
