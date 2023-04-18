#pragma once

#include "Object.h"
#include "Exceptions.h"
#include <iostream>
#include <typeinfo>
using HitFunctionPtr = void (*)(Object&, Object&);
typedef void (*HitFunctionPtr)(Object&, Object&);
using Key = std::pair<std::string, std::string>;
using HitMap = std::map<Key, HitFunctionPtr>;

class ManageCollision{
public:
    static void processCollision(Object& object1, Object& object2);
    static bool collide(Object& a, Object& b);
    static HitFunctionPtr lookup(std::string first, std::string second);

    static HitMap initializeCollisionMap();


};

