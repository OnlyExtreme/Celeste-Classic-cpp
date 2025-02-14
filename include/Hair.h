#ifndef HAIR_H
#define HAIR_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class HairUnit {
public:
    sf::Vector2f position;
    float size;

    HairUnit(float x, float y, float size)
        : position({x, y}), size(size) {}
};

class Hair {
public:
    void createHair(GameObject& obj);      // Create hair object?
    void setHairColor(int djump);    // Set hair color based on dJump
    void updateHair(GameObject& obj, int iniVal);  // Update hair
    void drawHair();    // Draw the hair of the player depending on the direction
    void unsetHairColor();      // Don't know wtf does this do...

private:
    std::vector<HairUnit> hairGroup;
};

#endif