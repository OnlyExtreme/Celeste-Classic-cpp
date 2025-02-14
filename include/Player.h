#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Hair.h"
#include <SFML/Graphics.hpp>


class Player : public GameObject {
public:
    Player();
    void update(float deltaTime) override;      // Update function called every tick
    void draw(sf::RenderWindow& window) override;   // Draw function called every tick
    bool isSolid(int dx, int dy);    // Get the property of the map at (x+dx, y+dy)
    bool isIce(int dx, int dy);

private:
    bool pJump;     // Jump pressed
    bool pDash;     // Dash pressed
    int grace;      // Coyote Time, decrease from initial value after leaving the ground
    int jBuffer;    // Jump input buffer 
    int dJump;      // Current dashes left
    float dashTime;     // The time the dash lasts
    float dashEffectTime;   // The time the sfx of the dash lasts
    sf::Vector2f dashTarget;    // Target velocity of the dash
    sf::Vector2f dashAccel;     // Acceleration of the dash
    sf::Vector2i hitboxCenter;  // The centre of the hixbox with respect to the sprite position
    sf::Vector2i hitboxSize;    // The size of the hitbox
    float sprOff;     // Animation frames offset
    int spr;    // Index of sprite in sprite sheet
    bool wasOnGround;   // On ground last tick?
    Hair hair;
};

#endif