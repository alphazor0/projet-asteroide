// Projectile.cpp
#include "projectile.h"
#include <iostream>
#include <math.h>

Projectile::Projectile(const sf::Texture &texture, const sf::Vector2f &position, const sf::Vector2f &direction, float speed)
    : Mobile(texture), direction(direction)
{
    isAlive = true;
    setPosition(position); // Position initiale du projectile
    clock.restart();       // Démarre l'horloge pour suivre le temps écoulé
    this->speed = speed;
    sprite.setScale(0.5f, 0.5f); // Ajuster l'échelle pour la visibilité
    // std::cout << "Projectile créé avec texture : " << &texture << "\n";
}

void Projectile::destroy()
{
    this->isAlive = false; // Marque le projectile comme inactif
}

void Projectile::avancer()
{
    if (isAlive)
    {
        // Déplacer selon la direction
        sprite.move(direction.x * speed, direction.y * speed);

        // Vérifier si le projectile sort de l'écran
        sf::Vector2f position = sprite.getPosition();
        if (position.x < 0 || position.x > 1920 || position.y < 0 || position.y > 1080)
        {
            destroy();
        }
    }
}
