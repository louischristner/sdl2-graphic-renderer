#include <ctime>
#include <cstdlib>

#include "headers/SDL2Renderer.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define FPS 60

class Game {
    public:
        Game(Vect2<size_t> windowSize);
        ~Game() = default;

        bool onStart();
        bool onUpdate();

    protected:
        SDL2Renderer _window;
        Vect2<size_t> _windowSize;
        std::list<const Entity *> _entities;

    private:
        Entity _obj;
        Vect2<float> _objSpeed;

        SDL_Event _event;
        Uint32 _startTime;

        const int _ticksPerFrame = 1000 / FPS;
};

Game::Game(Vect2<size_t> windowSize):
    _windowSize(windowSize), _window(SDL2Renderer(windowSize))
{
}

bool Game::onStart()
{
    _obj = _window.createRectangle({100, 100});
    _obj.setColor({255, 255, 255});
    _entities.push_back(&_obj);
    _objSpeed = {10, 10};

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

    Color color = {
        (uint8_t) (std::rand() % 255),
        (uint8_t) (std::rand() % 255),
        (uint8_t) (std::rand() % 255)
    };

    if (_obj.getPosition().x < 0) {
        _objSpeed.x = -_objSpeed.x;
        _obj.setColor(color);
    } else if (_obj.getPosition().y < 0) {
        _objSpeed.y = -_objSpeed.y;
        _obj.setColor(color);
    } else if (_obj.getPosition().x + _obj.getSize().x > _windowSize.x) {
        _objSpeed.x = -_objSpeed.x;
        _obj.setColor(color);
    } else if (_obj.getPosition().y + _obj.getSize().y > _windowSize.y) {
        _objSpeed.y = -_objSpeed.y;
        _obj.setColor(color);
    }

    _obj.translate(_objSpeed * ((float) _ticksPerFrame / FPS));

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
