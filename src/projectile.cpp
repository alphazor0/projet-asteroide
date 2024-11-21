// Projectile.cpp
#include "projectile.h"
#include <iostream>

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

void Projectile::update(float deltaTime)
{
    if (isAlive)
    {
        // Déplacer le projectile selon sa direction et sa vitesse
        sprite.move(direction.x * speed * deltaTime, direction.y * speed * deltaTime);

        // Vérifier si le projectile sort de l'écran
        sf::Vector2f position = sprite.getPosition();
        if (position.x < 0 || position.x > 1920 || position.y < 0 || position.y > 1080) // Exemple de limites
        {
            destroy();
        }
    }
}
