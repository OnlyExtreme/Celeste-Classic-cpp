#ifndef BALLOON_H
#define BALLOON_H

#include "GameObject.h"

class Balloon : public GameObject {
public:
    Balloon();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;

private:
    const int tile = 22;

    float offset;
    int start;
    int timer;
    sf::Vector2f hitboxOffset;
    sf::Vector2f hitboxSize;
    int spr;
};

#endif