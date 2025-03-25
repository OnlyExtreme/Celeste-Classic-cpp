#include "GameObject.h"
#include "utils.h"
#include <math.h>

extern std::vector<GameObject::Ptr> GameObject::objects;

bool GameObject::isSolid(float ox, float oy) {
    if (oy > 0 && !check(ObjectType::Platform, ox, 0) && check(ObjectType::Platform, ox, oy))
        return true;
    if (solidAt(position.x + hitboxCenter.x + ox, position.y + hitboxCenter.y + oy, hitboxSize.x, hitboxSize.y))
        return true;
    if (check(ObjectType::FallFloor, ox, oy))
        return true;
    if (check(ObjectType::FakeWall, ox, oy))
        return true; 
    return false;
}


bool GameObject::isIce(float ox, float oy) {
    return iceAt(position.x + hitboxCenter.x + ox, position.y + hitboxCenter.y + oy, hitboxSize.x, hitboxSize.y);
}

std::shared_ptr<GameObject> GameObject::collide(ObjectType _type, float ox, float oy) {
    for (const auto& obj : GameObject::objects) {
        auto other = obj;
        if (!other || other.get() == this || !other->collideable || other->type != _type) {
            continue;
        }

        bool collision = 
            (other->position.x + other->hitboxCenter.x + other->hitboxSize.x > this->position.x + this->hitboxCenter.x + ox) &&
            (other->position.y + other->hitboxCenter.y + other->hitboxSize.y > this->position.y + this->hitboxCenter.y + oy) &&
            (other->position.x + other->hitboxCenter.x < this->position.x + this->hitboxCenter.x + ox) &&
            (other->position.y + other->hitboxCenter.y < this->position.y + this->hitboxCenter.y + oy);
        
        if (collision)
            return other;
    }
    return nullptr;
}

bool GameObject::check(ObjectType _type, float ox, float oy) {
    std::shared_ptr<GameObject> collision = this->collide(_type, ox, oy);
    return collision != nullptr;
}

void GameObject::move(float ox, float oy) {
    float amount = 0;
    rem.x += ox;
    amount += floor(rem.x + 0.5);
    rem.x -= amount;
    this->moveX(amount, 0);

    rem.y += oy;
    amount = floor(rem.y + 0.5);
    rem.y -= amount;
    this->moveY(amount);
}

void GameObject::moveX(float amount, float start) {
    if (solids) {
        int step = sign(amount);
        for (int i = start; i < fabs(amount); i++) {
            if (!isSolid(step, 0))
                position.x += step;
            else {
                velocity.x = 0;
                rem.x = 0;
                break;
            }
        }
    }
    else
        position.x += amount;
}

void GameObject::moveY(float amount) {
    if (solids) {
        int step = sign(amount);
        for (int i = 0; i < fabs(amount); i++) {
            if (!isSolid(0, step))
                position.y += step;
            else {
                velocity.y = 0;
                rem.y = 0;
                break;
            }
        }
    }
    else
        position.y += amount;
}