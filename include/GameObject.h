#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

enum class ObjectType {
    GameObject,
    Player,
    PlayerSpawn,
    Balloon,
    FallFloor,
    Fruit,
    Hair,
    Smoke,
    Spring,
    Platform,
    FakeWall
};

class GameObject {
public:
    GameObject(ObjectType type, int x, int y);
    virtual ~GameObject() = default;
    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    bool isSolid(float ox, float oy);
    bool isIce(float ox, float oy);
    std::shared_ptr<GameObject> collide(ObjectType _type, float ox, float oy);
    bool check(ObjectType _type, float ox, float oy);
    void move(float ox, float oy);
    void moveX(float amount, float start);
    void moveY(float amount);


    using Ptr = std::shared_ptr<GameObject>;
    static std::vector<Ptr> objects;


protected:

    ObjectType type;

    sf::Vector2f position;      // Position of the GameObject
    sf::Vector2f velocity = {0, 0};      // Velocity of the GameObject
    sf::Vector2f rem = {0, 0};        // Remaining movement amount
    sf::Vector2i hitboxCenter = {0, 0};    // The centre of the hixbox with respect to the sprite position
    sf::Vector2i hitboxSize = {8, 8};      // The size of the hitbox

    bool solids = true;
    bool collideable = true;

    int spr = 0;
    bool flipX = false;
    bool flipY = false;


};


#endif