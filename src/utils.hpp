#ifndef UTILS
#define UTILS

#include <cmath>
#include <SFML/System.hpp>

inline float calculateLength(const sf::Vector2f& vec)
{
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

inline sf::Vector2f normalize(sf::Vector2f vec)
{
    return vec / calculateLength(vec);
}

#endif