#include <ctime>
#include <cstdlib>

#include "../headers/SDL2Renderer.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define GRAVITY 9.8
#define FPS 60

class Game {
    public:
        Game(Vect2<size_t> windowSize);
        ~Game();

        bool onStart();
        bool onUpdate();

    protected:
        bool onEvent();

    protected:
        SDL2Renderer _renderer;
        Vect2<size_t> _windowSize;
        std::list<const Entity *> _entities;

    private:
        SDL_Event _event;
        Uint32 _startTime;

        const int _ticksPerFrame = 1000 / FPS;

        Entity *_character;
};

Game::Game(Vect2<size_t> windowSize):
    _windowSize(windowSize), _renderer(SDL2Renderer(windowSize))
{
}

Game::~Game()
{
    _entities.clear();
}

bool Game::onStart()
{
    Vect2<float> characterSize = { 50, 50 };
    Vect2<float> characterPosition = {
        WINDOW_WIDTH / 2 - (characterSize.x / 2),
        WINDOW_HEIGHT / 2 - (characterSize.y / 2)
    };

    _character = _renderer.createRectangle(characterSize);
    _character->setPosition(characterPosition);
    _character->setColor({ 255, 255, 255 });
    _entities.push_back(_character);

    return true;
}

bool Game::onEvent()
{
    SDL_PollEvent(&_event);
    if (_event.type == SDL_QUIT)
        return false;

    return true;
}

bool Game::onUpdate()
{
    _startTime = SDL_GetTicks();

    if (!onEvent())
        return false;

    _renderer.drawEntities(_entities);

    int frameTicks = SDL_GetTicks() - _startTime;
    if (frameTicks < _ticksPerFrame) {
        SDL_Delay(_ticksPerFrame - frameTicks);
    }

    return true;
}

int main(void)
{
    Game game({ WINDOW_WIDTH, WINDOW_HEIGHT });

    // game loop

    game.onStart();
    while (game.onUpdate());

    return 0;
}
