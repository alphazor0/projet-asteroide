#ifndef MOBILE_H
#define MOBILE_H

#include <SFML/Graphics.hpp>

class Mobile
{
public:
    Mobile();                           // Constructeur par défaut
    Mobile(const sf::Texture &texture); // Constructeur avec texture

    // Méthodes principales
    void setPosition(sf::Vector2f position); // Définit la position
    void move(float offsetX, float offsetY); // Déplace le mobile
    void draw(sf::RenderWindow &window);     // Dessine le mobile
    void rotate(float angle);                // Effectue une rotation

    // Getters
    sf::FloatRect getBounds() const;     // Retourne les limites du sprite
    const sf::Sprite &getSprite() const; // Retourne une référence au sprite
    float getAngle();

    // Setters
    void setAngle(float angle); // Modifie l'angle

    bool isAlive; // Statut de vie du mobile

protected:
    float speed;       // Vitesse du mobile
    float angle;       // Angle actuel
    sf::Sprite sprite; // Sprite associé au mobile
    sf::Vector2f direction;
};

#endif
