#include "mobile.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructeur par défaut
Mobile::Mobile()
    : speed(0.2f), angle(0.0f), isAlive(true), direction(1.f, 0.f)
{
}

// Constructeur avec une texture
Mobile::Mobile(const sf::Texture &texture)
    : speed(0.20f), angle(0.0f), isAlive(true), direction(1.f, 0.f)
{
    sprite.setTexture(texture);                                                                    // Associe la texture au sprite
    sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f); // Origine au centre du sprite
}

// Récupère la position du centre du Mobile
sf::Vector2f Mobile::getCenter()
{
    return sprite.getPosition();
}

// Définit la position du mobile
void Mobile::setPosition(sf::Vector2f position)
{
    sprite.setPosition(position);
}

// Dessine le sprite dans la fenêtre
void Mobile::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

// Effectue une rotation
void Mobile::rotate(float angle)
{
    sprite.rotate(angle);
}

// Retourne les limites globales du sprite
sf::FloatRect Mobile::getBounds() const
{
    return sprite.getGlobalBounds();
}

// Retourne une référence constante au sprite
const sf::Sprite &Mobile::getSprite() const
{
    return sprite;
}

float Mobile::getAngle()
{
    return sprite.getRotation();
}

void Mobile::setAngle(float angle)
{
    this->angle = angle;
    direction = sf::Vector2f(std::cos(angle), std::sin(angle));
}
