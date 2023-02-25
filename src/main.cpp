#include <SFML/Graphics.hpp>

#include <random>
#include <iostream>

#include "body.hpp"
#include "node.hpp"

sf::RenderWindow g_Window(
    sf::VideoMode(1200, 900), 
    "Spring Joints", 
    sf::Style::Titlebar | sf::Style::Close
);

int main()
{
    Body body(4);

    sf::Clock deltaClock;
    float deltaTime = 0;

    while (g_Window.isOpen())
    {
        sf::Event event;

        while (g_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                g_Window.close();
            
            if (event.type == sf::Event::KeyPressed)
            {
                // 29 - 35
                // 3 - 9
                
                if (!(event.key.code > 35 || event.key.code < 29))
                {
                    int n = 9 + event.key.code - 35;

                    body = Body(n);
                }
            }
        }

        g_Window.clear(sf::Color::Blue);

        Node::s_NodeSelected = false;

        body.draw();
        body.update(deltaTime);

        g_Window.display();

        deltaTime = deltaClock.restart().asSeconds();
        //std::cout << 1 / deltaTime << std::endl;
    }

    return 0;
}