#ifndef NODE_HPP
#define NODE_HPP

#include <SFML/Graphics.hpp>

class Node
{
public:
    static bool s_NodeSelected;

    Node(const sf::Vector2f& position, const sf::Vector2f& velocity = sf::Vector2f(0, 0), float radius = 30.0f);

    void applyForce(const sf::Vector2f& forces, float deltaTime);
    void update(float deltaTime);
    void draw();

    sf::Vector2f getPosition() const {return m_Position;}
private:
    void clampPosition();

    float m_Radius;
    sf::Vector2f m_Position;
    sf::Vector2f m_Velocity;
    bool m_Selected;
};

#endif