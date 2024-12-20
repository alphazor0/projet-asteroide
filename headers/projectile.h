#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "mobile.h"

class Projectile : public Mobile
{

public:
    Projectile(const sf::Texture &texture, const sf::Vector2f &position, const sf::Vector2f &direction, float speed);
    void avancer();
    void destroy();
    sf::Vector2f positionDuTir();
    

protected:
    sf::Clock clock; // starts the clock
    sf::Vector2f direction;
};
#endif
