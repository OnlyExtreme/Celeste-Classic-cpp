#include "FallFloor.h"

FallFloor::FallFloor() {
    state = 0;
}

void FallFloor::update(float deltaTime) {
    // Idling
    if (state == 0) {
        // TODO: Implement check()
        // if (check(0, -1) || check(1, 0) || check(-1, 0))
            breakFallFloor();
    }
    // Shaking
    else if (state == 1) {
        delay -= 1;
        if (delay <= 0) {
            state = 2;  // Go into invisible state
            delay = 60; // Hides for 60 ticks
            collidable = false;     // Disable collision
        }        
    }
    // Invisible, waiting to reset
    else if (state == 2) {
        delay -= 1;
        if (delay <= 0 /*&& check(player, 0, 0)*/) {
            // TODO: Play sound effect
            state = 0;
            collidable = true;
            // TODO: Generate smoke effect
        }
    }
}

void FallFloor::draw(sf::RenderWindow& window) {
    if (state != 2) {
        if (state != 1) {
            // TODO: Draw sprite
        }
        else {
            // TODO: Draw sprite
        }
    }
}

void FallFloor::breakFallFloor() {
    if (state == 0) {
        // TODO: Play sound effect
        state = 1;
        delay = 15;
        // TODO: Generate smoke effect
        // TODO: Hit object
    }
}