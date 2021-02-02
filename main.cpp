#include "headers/SDL2Renderer.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FPS 60

int main(void)
{
    const int ticksPerFrame = 1000 / FPS;
    SDL2Renderer window({WINDOW_WIDTH, WINDOW_HEIGHT});
    std::list<const Entity *> entities;

    Entity rect = window.createRectangle({100, 100});
    entities.push_back(&rect);

    Entity sprite = window.createSprite("resources/img.png", {100, 100});
    entities.push_back(&sprite);

    // game loop

    SDL_Event event;

    Uint32 startTime = SDL_GetTicks();

    while (true) {
        startTime = SDL_GetTicks();

        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            break;

        window.drawEntities(entities);

        int frameTicks = SDL_GetTicks() - startTime;
        if (frameTicks < ticksPerFrame) {
            SDL_Delay(ticksPerFrame - frameTicks);
        }
    }

    return 0;
}
