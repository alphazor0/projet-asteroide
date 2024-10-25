#ifndef MOBILE_H
#define MOBILE_H

#include <SFML/Graphics.hpp>

class Mobile
{
public:
    Mobile();
    Mobile(const std::string &textureFile);
    void setPosition(float x, float y);
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
