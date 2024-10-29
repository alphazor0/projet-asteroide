#ifndef MOBILE_H
#define MOBILE_H

#include <SFML/Graphics.hpp>

class Mobile
{
public:
    Mobile();
    Mobile(const sf::Texture &textureFile);
    void setPosition(sf::Vector2f);
    void move(float offsetX, float offsetY);
    void draw(sf::RenderWindow &window);
    void rotate(float angle);
    float angle;

protected:
    float speed;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
