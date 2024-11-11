#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "mobile.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Définition de l'énumération pour la taille de l'astéroïde
enum TailleAsteroide
{
    PETIT, // Taille petite
    MOYEN, // Taille moyenne
    GRAND  // Taille grande
};

class Asteroide : public Mobile
{
public:
    Asteroide(const sf::Texture &textureFile, TailleAsteroide taille);
    TailleAsteroide getTaille() const;
    // sf::FloatRect getBounds() const; #test virtual
    const sf::Texture &getTexture() const;
    sf::Vector2f getPosition() const;

protected:
    TailleAsteroide tailleAsteroide; // Membre pour stocker la taille
    sf::Sprite sprite;
};

#endif
