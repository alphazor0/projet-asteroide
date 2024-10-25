#include "mobile.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Mobile::Mobile()
{
    speed = 5.0f;
}

Mobile::Mobile(const std::string &textureFile) // constructeur de mobile
{
    if (!texture.loadFromFile(textureFile))
    {
        std::cerr << "Failed to load texture!" << std::endl;
    }
    sprite.setTexture(texture);
}

void Mobile::setPosition(float x, float y) // méthode pour modifier la position des mobiles
{
    sprite.setPosition(x, y);
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