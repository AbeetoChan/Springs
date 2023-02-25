#include "body.hpp"
#include "line.hpp"
#include "utils.hpp"

#include <random>
#include <iostream>

extern sf::RenderWindow g_Window;
extern float g_DeltaTime;


std::default_random_engine rng(time(0));

static sf::Vector2f generateRandomPosition()
{
    float windowWidth = g_Window.getSize().x;
    float windowHeight = g_Window.getSize().y;

    std::uniform_int_distribution<int> x(0, windowWidth);
    std::uniform_int_distribution<int> y(0, windowHeight);

    return sf::Vector2f(x(rng), y(rng));
}

static sf::Vector2f springForce(const Node& a, const Node& b, float targetLength, float bounce)
{
    sf::Vector2f distance = a.getPosition() - b.getPosition();
    sf::Vector2f force = normalize(distance) * (targetLength - calculateLength(distance));
    force *= bounce;
    return force;
}

Body::Body(int nodes, float targetLength, float bounce)
    :m_Nodes({}), m_TargetLength(targetLength), m_Bounce(bounce)
{
    for (int i = 0; i < nodes; i++)
    {
        sf::Vector2f position = generateRandomPosition();
        Node node(position, sf::Vector2f(0, 0));
        m_Nodes.push_back(node);
    }
}

void Body::update(float deltaTime)
{
    const sf::Vector2f gravity(0, 100);

    for (Node& node: m_Nodes)
    {
        sf::Vector2f force = gravity;
        
        for (Node& connectingNode: m_Nodes)
        {
            if (&node != &connectingNode)
            {
                force += springForce(node, connectingNode, m_TargetLength, m_Bounce);
            }
        }
        
        node.applyForce(force, deltaTime);
        node.update(deltaTime);
    }
}

void Body::draw()
{
    for (Node& node: m_Nodes)
    {        
        for (Node& connectingNode: m_Nodes)
        {
            if (&node != &connectingNode)
            {
                Line line(node.getPosition(), connectingNode.getPosition(), sf::Color::Black, 15);
                g_Window.draw(line);
            }
        }
    }

    for (Node& node: m_Nodes)
    {
        node.draw();
    }
}