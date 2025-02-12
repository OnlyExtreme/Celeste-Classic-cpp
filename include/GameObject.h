#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject {
public:
    GameObject();
    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    sf::Vector2f position;
    sf::Vector2f velocity;

    bool isSolid = true;
    bool collideable = true;
};

#endif