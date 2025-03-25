#ifndef FACTORY_H
#define FACTORY_H


#include "GameObject.h"
#include <functional>

class GameObjectFactory {
public:
    using CreateFunc = std::function<GameObject::Ptr(ObjectType, int, int)>;

    // Register a ObjectType to an actual derived class of GameObject
    template <typename T>
    static void registerType(ObjectType _type) {
        // The ObjectType _type is linked to the instantiation function of type T
        creators()[_type] = [](ObjectType type, int x, int y) {
            auto obj = std::make_shared<T>(type, x, y);
            GameObject::objects.push_back(obj);
            return obj;
        }
    }

    static GameObject::Ptr create(ObjectType _type, int x, int y) {
        auto it = creators().find(_type);
        return (it != creators().end()) ? it->second(_type, x, y) : nullptr;
    }

private:
    // An unordered map from ObjectType to actual function of a derived GameObject class
    static std::unordered_map<ObjectType, CreateFunc>& creators() {
        static std::unordered_map<ObjectType, CreateFunc> instance;
        return instance;
    }
};

#endif