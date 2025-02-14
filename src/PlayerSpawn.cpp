#include "PlayerSpawn.h"

extern int MAX_D_JUMP;

PlayerSpawn::PlayerSpawn(float x, float y) {
    // TODO: Play sound effect
    position = {x, 128};
    target = {x, y};
    velocity = {0, -4};
    spr = 3;
    state = 0;
    delay = 0;
    hair.createHair(*this);
}

void PlayerSpawn::update(float deltaTime) {
    // Jumping Up
    if (state == 0) {
        if (position.y < target.y + 16) {
            state = 1;
            delay = 3;
        }
    }
    // Falling
    else if (state == 1) {
        velocity.y += 0.5;
        if (velocity.y > 0 && delay > 0) {
            velocity.y = 0;
            delay -= 1;
        }
        if (velocity.y > 0 && position.y > target.y) {
            position.y = target.y;
            velocity = {0, 0};
            state = 2;
            delay = 5;
            // TODO: Generate Shake and smoke
            // TODO: Play sound effect
        }
    }
    // Landing
    else if (state == 2) {
        delay -= 1;
        spr = 6;
        if (delay < 0) {
            // TODO: Delete the spawn object, create player object
            // Maybe use signals?
            // Destroy this object
            // Create Player Object
        }
    }
}

void PlayerSpawn::draw(sf::RenderWindow& window) {
    hair.setHairColor(MAX_D_JUMP);
    hair.drawHair();
    // Draw Sprite
    hair.unsetHairColor();
}


/*
2.14 Special~
  ##### #####  
 #############
###############
###############
 #############
   #########
     #####
       #
*/