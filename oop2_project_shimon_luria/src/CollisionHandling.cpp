#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "Demon.h"
#include "GiftLives.h"
#include "GiftPoints.h"
#include "GiftShots.h"
#include "Wall.h"
#include "Pack_shote.h"
#include "DemonShot.h"
#include "Pacman.h"


enum class GameObjectIndex
{
    Pacman,
    Wall,
    //Demon,
    //GiftShots,
    //GiftPoints,

    MAX
};


//#include "SpaceShip.h"
//#include "SpaceStation.h"
//#include "Asteroid.h"
//
namespace // anonymous namespace — the standard way to make function "static"
{

    // primary collision-processing functions
    void wallPac(Object& wall,        MoveObject& pac)
    {
        // To get the actual types and use them:
        // SpaceShip& ship = dynamic_cast<SpaceShip&>(spaceShip);
        // Asteroid&  ast  = dynamic_cast<Asteroid&>(asteroid);
        // or:
        // SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
        // Asteroid&  ast  = static_cast<Asteroid&>(asteroid);
        pac.back();
//      std::cout << "SpaceShip and Asteroid collision!" << std::endl;
    }
//
//    void shipStation(Object& spaceShip,
//        Object& spaceStation)
//    {
//        std::cout << "SpaceShip and SpaceStation collision!" << std::endl;
//    }
//
//    void asteroidStation(Object& asteroid,
//        Object& spaceStation)
//    {
//        std::cout << "Asteroid and SpaceStation collision!" << std::endl;
//    }
//
//    void shipShip(Object& spaceShip1,
//        Object& spaceShip2)
//    {
//        std::cout << "Two SpaceShips collision!" << std::endl;
//    }
//
//    //...
//
//    // secondary collision-processing functions that just
//    // implement symmetry: swap the parameters and call a
//    // primary function
//    void asteroidShip(Object& asteroid,
//        Object& spaceShip)
//    {
//        shipAsteroid(spaceShip, asteroid);
//    }
//    void stationShip(Object& spaceStation,
//        Object& spaceShip)
//    {
//        shipStation(spaceShip, spaceStation);
//    }
//    void stationAsteroid(Object& spaceStation,
//        Object& asteroid)
//    {
//        asteroidStation(asteroid, spaceStation);
//    }
//    //...
//
    using HitFunctionPtr = void (*)(Object&, MoveObject&);
     typedef void (*HitFunctionPtr)(Object&, MoveObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;
//
    HitMap initializeCollisionMap()
    {
        //**
        //**
        HitMap phm;
        phm[Key(typeid(Wall), typeid(Pacman))] = &wallPac;
//        phm[Key(typeid(SpaceShip), typeid(SpaceStation))] = &shipStation;
//        phm[Key(typeid(Asteroid), typeid(SpaceStation))] = &asteroidStation;
//        phm[Key(typeid(SpaceShip), typeid(SpaceShip))] = &shipShip;
//        phm[Key(typeid(Asteroid), typeid(SpaceShip))] = &asteroidShip;
//        phm[Key(typeid(SpaceStation), typeid(SpaceShip))] = &stationShip;
//        phm[Key(typeid(SpaceStation), typeid(Asteroid))] = &stationAsteroid;
//        //...
        return phm;
    }
//
HitFunctionPtr ManageCollision::lookup(std::string first, std::string second)
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
    if (mapEntry == collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}

} // end namespace
//
void processCollision(Object& object1, MoveObject& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}
