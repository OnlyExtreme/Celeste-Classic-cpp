#ifndef SPRING_H
#define SPRING_H

#include "GameObject.h"

class Spring : public GameObject {
public:
    Spring();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    void breakSpring();

private:
    const int tile = 18;
    int hideIn;
    int hideFor;
    int delay;
    int spr;
};

#endif