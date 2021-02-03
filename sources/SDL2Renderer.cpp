/*
** EPITECH PROJECT, 2021
** SDL2_lib
** File description:
** SDL2Renderer
*/

#include "../headers/SDL2Renderer.hpp"

SDL2Renderer::SDL2Renderer(const Vect2<size_t> &size):
    _window(NULL), _renderer(NULL)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw GraphicException(SDL_GetError());

    _window = SDL_CreateWindow(
        "SDL Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        size.x,
        size.y,
        SDL_WINDOW_SHOWN
    );

    if (_window == NULL)
        throw GraphicException(SDL_GetError());

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (_renderer == NULL)
        throw GraphicException(SDL_GetError());
}

SDL2Renderer::~SDL2Renderer()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

Entity SDL2Renderer::createRectangle(const Vect2<float> &size, const Vect2<float> &pos)
{
    Entity rectangle(pos);

    rectangle.setSize(size);
    return rectangle;
}

Entity SDL2Renderer::createSprite(const std::string &filename, const Vect2<float> &pos)
{
    Entity sprite(pos);
    SDL_Surface *surface = IMG_Load(filename.c_str());

    if (surface == NULL)
        throw GraphicException(IMG_GetError());

    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);

    if (texture == NULL)
        throw GraphicException(IMG_GetError());

    sprite.setTexture(texture);
    return sprite;
}

void SDL2Renderer::drawEntities(const std::list<const Entity *> &entities)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(_renderer);

    for (const Entity *entity : entities) {
        if (entity->getTexture() == NULL) {
            SDL_FRect dest = {
                entity->getPosition().x,
                entity->getPosition().y,
                entity->getSize().x,
                entity->getSize().y
            };

            SDL_SetRenderDrawColor(
                _renderer,
                entity->getColor().r,
                entity->getColor().g,
                entity->getColor().b,
                SDL_ALPHA_OPAQUE);
            SDL_RenderFillRectF(_renderer, &dest);
        } else {
            SDL_Rect dest = {
                (int) entity->getPosition().x,
                (int) entity->getPosition().y,
                (int) entity->getSize().x,
                (int) entity->getSize().y
            };

            SDL_QueryTexture(entity->getTexture(), NULL, NULL, &dest.w, &dest.h);
            SDL_RenderCopy(_renderer, entity->getTexture(), NULL, &dest);
        }
    }

    SDL_RenderPresent(_renderer);
}
