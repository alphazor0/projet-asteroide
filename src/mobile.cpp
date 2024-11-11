#include "mobile.h"
#include <iostream>

// Constructeur par défaut
Mobile::Mobile()
    : speed(5.0f), angle(0.0f), isAlive(true)
{
}

// Constructeur avec une texture
Mobile::Mobile(const sf::Texture &texture)
    : speed(5.0f), angle(0.0f), isAlive(true)
{
    sprite.setTexture(texture); // Associe la texture au sprite
}

// Définit la position du mobile
void Mobile::setPosition(sf::Vector2f position)
{
    sprite.setPosition(position);
}

// Déplace le mobile en fonction des offsets
void Mobile::move(float offsetX, float offsetY)
{
    sprite.move(offsetX, offsetY);
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
