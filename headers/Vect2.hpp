/*
** EPITECH PROJECT, 2021
** SDL2_lib
** File description:
** Vect2
*/

#ifndef VECT2_HPP_
#define VECT2_HPP_

template<class T>
struct Vect2
{
    T x, y;

    void operator+=(const Vect2<T> &vect)
    {
        x += vect.x;
        y += vect.y;
    }

    Vect2<T> operator+(const Vect2<T> &vect) const
    {
        return {x + vect.x, y + vect.y};
    }

    Vect2<T> operator*(const float &num) const
    {
        return {x * num, y * num};
    }
};

#endif /* !VECT2_HPP_ */
