#ifndef PLAYERSPAWN_H
#define PLAYERSPAWN_H

#include "GameObject.h"
#include "Hair.h"

class PlayerSpawn : public GameObject {
public:
    PlayerSpawn(float x, float y);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;

private:
    const bool solids = false;    // Is this object solid?

    int spr;    // Index of sprite animation
    sf::Vector2f target;    // wtf
    int state;
    int delay;
    Hair hair;
};


#endif