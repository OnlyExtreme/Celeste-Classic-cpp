#include "Hair.h"
#include "Player.h"
#include <algorithm>

void Hair::createHair(GameObject& obj) {
    hairGroup.clear();
    for (int i = 0; i < 5; i++) {
        float size = std::max(1.0f, std::min(2.9f, 3.0f - static_cast<float>(i)));
        hairGroup.emplace_back(HairUnit(obj.position.x, obj.position.y, size));
    }
}


void Hair::setHairColor() {
    // LUA: pal(...) Color Palette Choice in pico-8?
    // TODO: Implement this in SFML
}

void Hair::updateHair(GameObject& obj, int iniVal) {
    // Initial Position
    sf::Vector2f lastPosition = {obj.position.x + 4 - obj.direction * 2, obj.position.y + iniVal};
    for (auto &h : hairGroup) {
        // Iterate through hair objects and update depending on last object
        h.position.x += (lastPosition.x - h.position.x) / 1.5f;
        h.position.y += (lastPosition.y + 0.5f - h.position.y) / 1.5f;
        lastPosition = h.position;
    }
}

void Hair::drawHair() {
    // TODO: Draw hair with SFML
}

void Hair::unsetHairColor() {
    // LUA: pal(8, 8) pico-8 color palette
    // TODO: Implement this using SFML
}