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
        sf::Vector2f position;

        // Déterminer si l'astéroïde commence sur un bord vertical ou horizontal
        int side = rand() % 4; // 0 = gauche, 1 = droite, 2 = haut, 3 = bas

        switch (side)
        {
        case 0: // Bord gauche
            position.x = 0.0f;
            position.y = static_cast<float>(rand() % windowSize.y);
            break;
        case 1: // Bord droit
            position.x = static_cast<float>(windowSize.x);
            position.y = static_cast<float>(rand() % windowSize.y);
            break;
        case 2: // Bord haut
            position.x = static_cast<float>(rand() % windowSize.x);
            position.y = 0.0f;
            break;
        case 3: // Bord bas
            position.x = static_cast<float>(rand() % windowSize.x);
            position.y = static_cast<float>(windowSize.y);
            break;
        }

        // Choisir une taille aléatoire d'astéroïde (PETIT, MOYEN, GRAND)
        TailleAsteroide taille = PETIT;
        int r = rand() % 3; // Générer un entier entre 0 et 2
        if (r == 0)
        {
            taille = PETIT;
        }
        else if (r == 1)
        {
            taille = MOYEN;
        }
        else
        {
            taille = GRAND;
        }

        // Afficher pour débogage
        std::cout << "Asteroide créé : Taille = " << r
                  << ", Position = (" << position.x << ", " << position.y << "), "
                  << "Côté : " << side << std::endl;

        // Créer et ajouter un astéroïde avec la texture, la taille et la position
        asteroides.emplace_back(asteroidTexture, taille, position);
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

void Vague::update()
{
    for (auto &asteroide : asteroides)
    {
        asteroide.avancer();
    }
}
