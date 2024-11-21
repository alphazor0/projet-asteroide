#include "mobile.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructeur par défaut
Mobile::Mobile()
    : speed(5.0f), angle(0.0f), isAlive(true), direction(1.f, 0.f)
{
}

// Constructeur avec une texture
Mobile::Mobile(const sf::Texture &texture)
    : speed(50.0f), angle(0.0f), isAlive(true), direction(1.f, 0.f)
{
    sprite.setTexture(texture); // Associe la texture au sprite
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
    return angle;
}

void Mobile::setAngle(float angle)
{
    this->angle = angle;
    direction = sf::Vector2f(std::cos(angle), std::sin(angle));
}
