// Projectile.cpp
#include "projectile.h"
#include <iostream>

Projectile::Projectile(const sf::Texture &textureFile)
    : Mobile(textureFile), delay(0.0f) // Initialise le delay à 0.0
{
}
