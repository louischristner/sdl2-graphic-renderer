#include <ctime>
#include <cstdlib>

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
    rect.setColor({255, 255, 255});
    entities.push_back(&rect);

    // game loop

    std::srand(std::time(nullptr));

    Vect2<float> entitySpeed = {10, 10};

    SDL_Event event;
    Uint32 startTime =
        SDL_GetTicks();

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

        Color color = {
            (uint8_t) (std::rand() % 255),
            (uint8_t) (std::rand() % 255),
            (uint8_t) (std::rand() % 255)
        };

        if (rect.getPosition().x < 0) {
            entitySpeed.x = -entitySpeed.x;
            rect.setColor(color);
        } else if (rect.getPosition().y < 0) {
            entitySpeed.y = -entitySpeed.y;
            rect.setColor(color);
        } else if (rect.getPosition().x + rect.getSize().x > WINDOW_WIDTH) {
            entitySpeed.x = -entitySpeed.x;
            rect.setColor(color);
        } else if (rect.getPosition().y + rect.getSize().y > WINDOW_HEIGHT) {
            entitySpeed.y = -entitySpeed.y;
            rect.setColor(color);
        }

        rect.translate(entitySpeed * ((float) ticksPerFrame / FPS));
    }

    return 0;
}
