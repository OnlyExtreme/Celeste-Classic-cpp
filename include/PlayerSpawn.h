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
    const int tile = 1;     // Index of tile in tilemap

    int spr;    // Index of sprite animation
    sf::Vector2f target;    // Target spawn position
    int state;  // State of spawn animation
    int delay;  // Delay of spawn animation
    Hair hair;
};


#endif