/*
** EPITECH PROJECT, 2021
** SDL2_lib
** File description:
** Entity
*/

#include "../headers/Entity.hpp"

Entity::Entity(const Vect2<float> pos):
    _size({0, 0}), _pos(pos), _texture(NULL)
{
}

Entity::~Entity()
{
    SDL_DestroyTexture(_texture);
}

void Entity::setSize(const Vect2<float> &size)
{
    _size = size;
}

void Entity::setPosition(const Vect2<float> &pos)
{
    _pos = pos;
}

void Entity::setTexture(SDL_Texture *texture)
{
    _texture = texture;
}

void Entity::translate(const Vect2<float> &vec)
{
    _pos += vec;
}

Vect2<float> Entity::getSize() const
{
    return _size;
}

Vect2<float> Entity::getPosition() const
{
    return _pos;
}

SDL_Texture *Entity::getTexture() const
{
    return _texture;
}
