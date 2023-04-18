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
#include "PacShot.h"
#include "PacShot.h"
#include "Pacman.h"
#include "ManageCollision.h"

void ManageCollision::processCollision(Object& object1, Object& object2)
{
    auto phf = lookup(object1.name(), object2.name());
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);

}
bool ManageCollision::collide(Object& a, Object& b)
{
    sf::FloatRect rectResult;
    if(a.getBound().intersects(b.getBound(),rectResult) &&
        (rectResult.height >= 0.5 || rectResult.left >= 0.5))

        return true;
	else
		return false;
}
HitFunctionPtr ManageCollision::lookup(std::string first, std::string second)
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(std::make_pair(first,second));
    //    if not returned a function  change the order of keys and look up agian
    if (mapEntry == collisionMap.end())
        mapEntry = collisionMap.find(std::make_pair(second, first));

    if (mapEntry == collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}

    // primary collision-processing functions
void giftPoints_pacman(Object& g_p, Object& pac)
{
    g_p.kill();
    Pacman& p = static_cast<Pacman&>(pac);
    p.addPoints();
}


void stop(Object& wall, Object& _moveObgect)
{
    MoveObject& m = static_cast<MoveObject&> (_moveObgect);
    m.back();
}
void PacDemon(Object& Demon, Object& Pac)
{
    Pac.kill();
}


void bothKill(Object& a, Object& b)
{
    a.kill();
    b.kill();
}
void nothing(Object& a, Object& b)
{

}
void giftShots_pacman(Object& g_s, Object& pac)
{
    g_s.kill();
    Pacman& p = static_cast<Pacman&>(pac);
    p.addShots();
}

void kill_shot(Object& somthing, Object& d_sh)
{
    d_sh.kill();
}
void giftLives_pacman(Object& g_l, Object& pac)
{
    g_l.kill();
    Pacman& p = static_cast<Pacman&>(pac);
    p.addLives();
}
HitMap ManageCollision::initializeCollisionMap()
{
    HitMap phm;
    phm[Key("Wall", "Pacman")]  = &stop;
    phm[Key("GiftPoints", "Pacman")] = &giftPoints_pacman;
    phm[Key("GiftLives", "Pacman")] = &giftLives_pacman;
    phm[Key("GiftShots", "Pacman")] = &giftShots_pacman;
    phm[Key("PacShot", "Pacman")] = &nothing;
    phm[Key("Demon", "Pacman")] = &PacDemon;
    phm[Key("Pacman", "Pacman")] = &nothing;

    phm[Key("GiftShots", "Demon")] = &stop;
    phm[Key("GiftPoints", "Demon")] = &stop;
    phm[Key("GiftLives", "Demon")] = &stop;
    phm[Key("Wall", "Demon")] = &stop;
    phm[Key("Demon", "Demon")] = &nothing;
    phm[Key("PacShot", "Demon")] = &bothKill;

    phm[Key("Demon", "PacShot")] = &bothKill;
    phm[Key( "GiftPoints", "PacShot")] = &bothKill;
    phm[Key( "GiftShots", "PacShot")] = &bothKill;
    phm[Key( "GiftLives", "PacShot")] = &bothKill;
    phm[Key( "Wall", "PacShot")] = &bothKill;
    phm[Key( "DemonShot", "PacShot")] = &bothKill;
    phm[Key("Pacman","PacShot")] = &nothing;
    phm[Key("PacShot", "PacShot")] = &nothing;

    phm[Key("Demon", "DemonShot")] = &nothing;
    phm[Key("GiftPoints", "DemonShot")] = &kill_shot;
    phm[Key("GiftShots", "DemonShot")] = &kill_shot;
    phm[Key("GiftLives", "DemonShot")] = &kill_shot;
    phm[Key("Wall", "DemonShot")] = &kill_shot;
    phm[Key("DemonShot", "DemonShot")] = &nothing;
    phm[Key("Pacman", "DemonShot")] = &bothKill;
    phm[Key("DemonShot", "PacShot")] = &bothKill;



    return phm;
}
