/*
** EPITECH PROJECT, 2021
** SDL2_lib
** File description:
** GraphicException
*/

#ifndef GRAPHICEXCEPTION_HPP_
#define GRAPHICEXCEPTION_HPP_

#include <string>
#include <exception>

class GraphicException : public std::exception {
    public:
        GraphicException(const std::string &msg) noexcept;
        const char *what() const noexcept override;

    protected:
    private:
        std::string _msg;
};

#endif /* !GRAPHICEXCEPTION_HPP_ */
