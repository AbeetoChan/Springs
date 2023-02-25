#ifndef BODY_HPP
#define BODY_HPP

#include <vector>

#include "node.hpp"

class Body
{
public:
    Body(int nodes, float targetLength = 150, float bounce = 5.0f);

    void update(float deltaTime);
    void draw();
private:
    std::vector<Node> m_Nodes;
    float m_TargetLength;
    float m_Bounce;
};


#endif