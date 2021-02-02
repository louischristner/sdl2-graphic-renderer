#include <chrono>

#include "headers/SDL2Renderer.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(void)
{
    SDL2Renderer window({WINDOW_WIDTH, WINDOW_HEIGHT});
    std::list<const Entity *> entities;

    Entity rect = window.createRectangle({100, 100});
    entities.push_back(&rect);

    Entity sprite = window.createSprite("resources/img.png", {100, 100});
    entities.push_back(&sprite);

    // game loop

    SDL_Event event;

    while (true) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            break;

        window.drawEntities(entities);
    }

    return 0;
}
