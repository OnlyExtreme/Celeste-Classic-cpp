#include "Smoke.h"
#include "utils.h"
#include <random>

Smoke::Smoke() {
    spr = 29;
    velocity.x = 0.3 + 0.2 * rand() / RAND_MAX;
    velocity.y = -0.1;
    position.x += 2 * rand() / RAND_MAX - 1;
    position.y += 2 * rand() / RAND_MAX - 1;
    flip.x = maybe();
    flip.y = maybe();
}

void Smoke::update(float deltaTime) {
    spr += 0.2;
    if (spr >= 32) {
        // TODO: Destroy this object 
    }
}