#include "node.hpp"
#include "utils.hpp"
#include <iostream>

extern sf::RenderWindow g_Window;
extern float g_DeltaTime;

bool Node::s_NodeSelected = false;

Node::Node(const sf::Vector2f& position, const sf::Vector2f& velocity, float radius)
    : m_Position(position), m_Velocity(velocity), m_Radius(radius), m_Selected(false)
{
    
}

void Node::clampPosition()
{
    float windowWidth = g_Window.getSize().x;
    float windowHeight = g_Window.getSize().y;

    if (m_Position.x < m_Radius)
    {
        m_Position.x = m_Radius;
        m_Velocity.x *= -1;
    }

    if (m_Position.x > windowWidth - m_Radius)
    {
        m_Position.x = windowWidth - m_Radius;
        m_Velocity.x *= -1;
    }

    if (m_Position.y < m_Radius)
    {
        m_Position.y = m_Radius;
        m_Velocity.y *= -1;
    }

    if (m_Position.y > windowHeight - m_Radius)
    {
        m_Position.y = windowHeight - m_Radius;
        m_Velocity.y *= -1;
    }
}

void Node::applyForce(const sf::Vector2f& force, float deltaTime)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(g_Window);
    sf::Vector2f mousePositionFloat = sf::Vector2f((float) mousePosition.x, (float) mousePosition.y);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !s_NodeSelected)
    {
        if (calculateLength(mousePositionFloat - m_Position) < m_Radius)
        {
            m_Selected = true;
        }

        if (m_Selected)
        {
            clampPosition();
            m_Position = mousePositionFloat;
            s_NodeSelected = true;
        }
    } 
    else
    {
        m_Selected = false;
    }

    m_Velocity += 0.45f * force * deltaTime;
    clampPosition();
}

void Node::update(float deltaTime)
{
    m_Position += m_Velocity * deltaTime;
    clampPosition();
}

void Node::draw()
{
    sf::CircleShape circle(m_Radius);
    circle.setFillColor(sf::Color::Green);
    circle.setOutlineThickness(10);
    circle.setOutlineColor(sf::Color(0, 0, 0));
    circle.setOrigin(sf::Vector2f(m_Radius, m_Radius));
    circle.setPosition(m_Position);

    g_Window.draw(circle);
}