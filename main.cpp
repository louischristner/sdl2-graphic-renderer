#include <ctime>
#include <cstdlib>

#include "headers/SDL2Renderer.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FPS 60

class Game {
    public:
        Game(Vect2<size_t> windowSize);
        ~Game();

        bool onStart();
        bool onUpdate();

    protected:
        SDL2Renderer _window;
        Vect2<size_t> _windowSize;
        std::list<const Entity *> _entities;

    private:
        SDL_Event _event;
        Uint32 _startTime;

        const int _ticksPerFrame = 1000 / FPS;
};

Game::Game(Vect2<size_t> windowSize):
    _windowSize(windowSize), _window(SDL2Renderer(windowSize))
{
}

Game::~Game()
{
    _entities.clear();
}

bool Game::onStart()
{
    Entity *obj = _window.createSprite("resources/img.png");
    _entities.push_back(obj);

    // Entity *obj = _window.createRectangle({100, 100});
    // obj.setColor({255, 255, 255});
    // _entities.push_back(obj);

    return true;
}

bool Game::onUpdate()
{
    _startTime = SDL_GetTicks();

    SDL_PollEvent(&_event);
    if (_event.type == SDL_QUIT)
        return false;

    _window.drawEntities(_entities);

    int frameTicks = SDL_GetTicks() - _startTime;
    if (frameTicks < _ticksPerFrame) {
        SDL_Delay(_ticksPerFrame - frameTicks);
    }

    return true;
}

int main(void)
{
    Game game({WINDOW_WIDTH, WINDOW_HEIGHT});

    // game loop

    std::srand(std::time(nullptr));

    game.onStart();
    while (game.onUpdate());

    return 0;
}
