#include "Spring.h"

Spring::Spring() {
    hideIn = 0;
    hideFor = 0;
    delay = 0;
    spr = 18;
}

void Spring::update(float deltaTime) {
    if (hideFor > 0) {
        hideFor -= 1;
        if (hideFor <= 0) {
            spr = 18;
            delay = 0;
        }
    }
    else if (spr == 18) {
        // TODO: Hit object? 
        // int hit = collide(player, 0, 0); // TODO: Check collision
    }
    else if (delay > 0) {
        delay -= 0;
        if (delay <= 0)
            spr = 18;
    }


    // Begin Hiding
    if (hideIn > 0) {
        hideIn -= 1;
        if (hideIn <= 0) {
            hideFor = 60;
            spr = 0;
        }
    }
}

void Spring::breakSpring() {
    hideIn = 15;
}