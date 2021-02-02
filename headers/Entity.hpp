/*
** EPITECH PROJECT, 2021
** SDL2_lib
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "Vect2.hpp"

#include <SDL2/SDL.h>

class Entity
{
    public:
        Entity(const Vect2<float> pos = {0, 0});
        ~Entity();

        /**
         * Set Entity size
         *
         * @param size the Vect2<float> size
         */
        void setSize(const Vect2<float> &size);

        /**
         * Set Entity position
         *
         * @param pos the Vect2<float> position
         */
        void setPosition(const Vect2<float> &pos);

        /**
         * Set Entity texture
         *
         * @param texture the SDL_Texture texture
         */
        void setTexture(SDL_Texture *texture);

        /**
         * Get Entity size
         *
         * @return the Vect2<float> size
         */
        Vect2<float> getSize() const;

        /**
         * Get Entity position
         *
         * @return the Vect2<float> position
         */
        Vect2<float> getPosition() const;

        /**
         * Get Entity texture
         *
         * @return the SDL_Texture texture
         */
        SDL_Texture *getTexture() const;

    protected:
    private:
        Vect2<float> _pos;
        Vect2<float> _size;
        SDL_Texture *_texture;
};

#endif /* !ENTITY_HPP_ */
