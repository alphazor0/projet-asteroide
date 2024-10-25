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
    GRAND, // Taille grande
    ENORME // Taille énorme
};

class Asteroide : public Mobile
{
public:
    Asteroide(const std::string &textureFile, TailleAsteroide taille);

protected:
    TailleAsteroide tailleAsteroide; // Membre pour stocker la taille
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
