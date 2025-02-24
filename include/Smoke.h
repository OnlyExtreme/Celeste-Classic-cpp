#ifndef SMOKE_H
#define SMOKE_H

#include "GameObject.h"

class Smoke : public GameObject {
public:
    Smoke();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;

private:
    const bool isSolid = false;

    float spr;
    sf::Vector2u flip;
};

#endif