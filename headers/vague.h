#ifndef VAGUE_H
#define VAGUE_H

#include "asteroide.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Vague
{
public:
    // Constructeur qui initialise la vague en fonction de son numéro
    Vague(int numVague, sf::Texture &asteroidTexture, sf::Vector2u windowSize);
    void genererVague(int numVague, sf::Texture &asteroidTexture, sf::Vector2u windowSize);
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);

    // Vérifie si la vague est terminée (si tous les astéroïdes sont détruits)
    bool isCleared() const;

    void clearAsteroid(int index);

private:
    std::vector<Asteroide> asteroides; // Liste d'astéroïdes dans cette vague
};

#endif
