#ifndef FALL_FLOOR_H
#define FALL_FLOOR_H

#include "GameObject.h"

class FallFloor : public GameObject {
public:
    FallFloor();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    void breakFallFloor();
    

private:
    const bool isSolid = 0;

    int state;
    int delay;
    bool collidable;
};

#endif