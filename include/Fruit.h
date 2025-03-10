#ifndef FRUIT_H
#define FRUIT_H

#include "GameObject.h"

class Fruit : public GameObject {
public:
    Fruit();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;

private:
    int tile = 26;
    bool ifNotFruit = true;

    int start;
    int off;
};

#endif