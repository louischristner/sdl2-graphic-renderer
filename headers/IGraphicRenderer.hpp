/*
** EPITECH PROJECT, 2021
** SDL2_lib
** File description:
** IGraphicRenderer
*/

#ifndef IGRAPHICRENDERER_HPP_
#define IGRAPHICRENDERER_HPP_

#include <list>

#include "Vect2.hpp"
#include "Entity.hpp"

class IGraphicRenderer
{
    public:
        virtual ~IGraphicRenderer() = default;

        /**
         * Create a rectangle Entity
         *
         * @param size the Vect2<float> size
         * @param pos the Vect2<float> position
         * @return the new Entity
         */
        virtual Entity createRectangle(const Vect2<float> &size, const Vect2<float> &pos = {0, 0}) = 0;

        /**
         * Create a sprite Entity
         *
         * @param filename the name of the image file
         * @param pos the Vect2<float> position
         * @return the new Entity
         */
        virtual Entity createSprite(const std::string &filename, const Vect2<float> &pos = {0, 0}) = 0;

        /**
         * Draw a list of Entity on the window
         *
         * @param entities the list of Entity to render
         */
        virtual void drawEntities(const std::list<const Entity *> &entities) = 0;
};

#endif /* !IGRAPHICRENDERER_HPP_ */
