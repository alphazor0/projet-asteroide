#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "mobile.h"

class Projectile : public Mobile
{

public:
    Projectile(const sf::Texture &textureFile);

protected:
    sf::Clock clock; // starts the clock
    float delay;
};
#endif
