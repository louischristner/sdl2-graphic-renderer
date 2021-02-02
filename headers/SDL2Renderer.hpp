/*
** EPITECH PROJECT, 2021
** SDL2_lib
** File description:
** SDL2Renderer
*/

#ifndef SDL2RENDERER_HPP_
#define SDL2RENDERER_HPP_

#include <SDL2/SDL_image.h>

#include "GraphicException.hpp"
#include "IGraphicRenderer.hpp"

class SDL2Renderer : public IGraphicRenderer
{
    public:
        SDL2Renderer(const Vect2<size_t> &size);
        ~SDL2Renderer() override;

        /**
         * Create a rectangle Entity
         *
         * @param size the Vect2<float> size
         * @param pos the Vect2<float> position
         * @return the new Entity
         */
        Entity createRectangle(const Vect2<float> &size, const Vect2<float> &pos = {0, 0}) override;

        /**
         * Create a sprite Entity
         *
         * @param filename the name of the image file
         * @param pos the Vect2<float> position
         * @return the new Entity
         */
        Entity createSprite(const std::string &filename, const Vect2<float> &pos = {0, 0}) override;

        /**
         * Draw a list of Entity on the window
         *
         * @param entities the list of Entity to render
         */
        void drawEntities(const std::list<const Entity *> &entities) override;

    protected:
    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
};

#endif /* !SDL2RENDERER_HPP_ */
