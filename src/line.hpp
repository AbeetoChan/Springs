#ifndef LINE_HPP
#define LINE_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class Line : public sf::Drawable
{
public:
    Line(const sf::Vector2f& start, const sf::Vector2f& end, sf::Color color, float thickness)
    {
        sf::Vector2f direction = end - start;
        sf::Vector2f unitDirection = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
        sf::Vector2f unitPerpendicular(-unitDirection.y, unitDirection.x);

        sf::Vector2f offset = (thickness / 2.f) * unitPerpendicular;

        m_Verticies[0].position = start + offset;
        m_Verticies[1].position = end + offset;
        m_Verticies[2].position = end - offset;
        m_Verticies[3].position = start - offset;

        for (int i = 0; i < 4; i++)
            m_Verticies[i].color = color;
    }

    void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_Verticies, 4, sf::Quads);
    }
private:
    sf::Vertex m_Verticies[4];
};

#endif