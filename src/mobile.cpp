#include "mobile.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::FloatRect Mobile::getBounds() const
{
    return sprite.getGlobalBounds(); // Retourne les limites globales du sprite
}

Mobile::Mobile()
{
    speed = 5.0f;
}

Mobile::Mobile(const sf::Texture &textureFile) // constructeur de mobile
{
    sprite.setTexture(textureFile);
}

void Mobile::setPosition(sf::Vector2f position) // méthode pour modifier la position des mobiles
{
    sprite.setPosition(position);
}

void Mobile::move(float offsetX, float offsetY) // méthode pour déplacer les mobiles
{
    sprite.move(offsetX, offsetY);
}

void Mobile::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Mobile::rotate(float angle) // méthode pour effectuer une rotation de mobile
{
    sprite.rotate(angle);
}

