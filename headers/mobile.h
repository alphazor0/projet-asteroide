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
    virtual sf::FloatRect getBounds() const;
    float angle;
    bool isAlive;

protected:
    float speed;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
