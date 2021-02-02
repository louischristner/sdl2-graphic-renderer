/*
** EPITECH PROJECT, 2021
** SDL2_lib
** File description:
** GraphicException
*/

#include "../headers/GraphicException.hpp"

GraphicException::GraphicException(const std::string &msg) noexcept :
    _msg(msg)
{
}

const char *GraphicException::what() const noexcept
{
    return _msg.data();
}
