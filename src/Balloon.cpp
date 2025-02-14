#include "Balloon.h"
#include <math.h>

extern int MAX_D_JUMP;

Balloon::Balloon() {
    offset = static_cast<float>(rand());
    start = position.y;
    timer = 0;
    hitboxOffset = {-1, -1};
    hitboxSize = {10, 10};
}

void Balloon::update(float deltaTime) {
    if (spr == 22) {
        offset += 0.01;
        position.y = start + sinf(offset) * 2;
        // TODO: Hit object
    }
    else if (timer > 0) {
        timer -= 1;
    }
    else {
        // TODO: Sound Effect
        // TODO: Generate Smoke
        spr = 22;
    }
}

void Balloon::draw(sf::RenderWindow& window) {
    if (spr == 2) {
        // TODO: Draw
    }
}