// Projectile.cpp
#include "projectile.h"
#include <iostream>


Projectile::Projectile(const sf::Texture &texture, const sf::Vector2f &position, const sf::Vector2f &direction)
    : Mobile(texture), direction(direction)
{
    setPosition(position); // Position initiale du projectile
    clock.restart();       // Démarre l'horloge pour suivre le temps écoulé
}

void Projectile::update(float deltaTime)
{
    // Met à jour la position en fonction de la direction et de la vitesse du projectile
    move(direction.x * speed * deltaTime, direction.y * speed * deltaTime); // 500.0f représente la vitesse en pixels par seconde
}