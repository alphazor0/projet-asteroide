#include "vague.h"
#include <cstdlib>

Vague::Vague()
{
    // Initialisation par défaut
}

// Constructeur qui initialise la vague en fonction de son numéro
Vague::Vague(int numVague, sf::Texture &asteroidTexture, sf::Vector2u windowSize)
{
    genererVague(numVague, asteroidTexture, windowSize);
}

// Méthode pour générer une nouvelle vague d'astéroïdes
void Vague::genererVague(int numVague, sf::Texture &asteroidTexture, sf::Vector2u windowSize)
{
    asteroides.clear(); // Vider la liste d'astéroïdes de la vague précédente

    // Crée autant d'astéroïdes que le numéro de la vague
    for (int i = 0; i < numVague; ++i)
    {

        sf::Vector2f position(rand() % windowSize.x, rand() % windowSize.y);

        // Choisir une taille aléatoire d'astéroïde (PETIT, MOYEN, GRAND)
        TailleAsteroide taille = static_cast<TailleAsteroide>(rand() % 3);

        // Créer et ajouter un astéroïde avec la texture, la taille et la position aléatoires
        Asteroide asteroid(asteroidTexture, taille);
        asteroid.setPosition(position);
        asteroides.push_back(asteroid);
    }
}

// Dessine chaque astéroïde de la vague
void Vague::draw(sf::RenderWindow &window)
{
    for (auto &asteroid : asteroides)
    {
        asteroid.draw(window);
    }
}

// Vérifie si la vague est terminée (si tous les astéroïdes sont détruits)
bool Vague::isCleared() const
{
    return asteroides.empty();
}

// Supprime un astéroïde à un indice donné
void Vague::clearAsteroid(int index)
{
    if (index >= 0 && index < asteroides.size())
    {
        asteroides.erase(asteroides.begin() + index);
    }
}

std::vector<Asteroide> &Vague::getAsteroides()
{
    return asteroides;
}