#include "jeu.h"
#include <iostream>

// Constructeur de la classe Jeu
Jeu::Jeu(const std::string &textureFile)
{
    // Charger la texture de fond
    if (!texturebg.loadFromFile(textureFile))
    {
        std::cerr << "Erreur de chargement de la texture de fond : " << textureFile << std::endl;
    }
    // Initialiser le sprite de fond
    background.setTexture(texturebg);
}

void Jeu::dessiner(sf::RenderWindow &fenetre)
{
    // Dessiner le fond
    fenetre.draw(background);

    // Dessiner le vaisseau
    fenetre.draw(vaisseau.getSprite());

    // Dessiner les astéroïdes via la vague
    for (const auto &asteroide : vague.getAsteroides())
    {
        fenetre.draw(asteroide.getSprite());
    }

    // Dessiner les projectiles
    for (const auto &tir : tirs)
    {
        fenetre.draw(tir->getSprite());
    }
}

void Jeu::gererCollisions()
{
    // Collision entre les projectiles et les astéroïdes
    auto &asteroides = vague.getAsteroides();
    for (auto &tir : tirs)
    {
        for (int i = 0; i < asteroides.size(); ++i)
        {
            if (tir->getBounds().intersects(asteroides[i].getBounds()))
            {
                // Diviser l'astéroïde ou le supprimer
                if (asteroides[i].getTaille() != PETIT)
                {
                    TailleAsteroide nouvelleTaille = static_cast<TailleAsteroide>(asteroides[i].getTaille() - 1);
                    asteroides.emplace_back(asteroides[i].getTexture(), nouvelleTaille, asteroides[i].getPosition());
                    asteroides.emplace_back(asteroides[i].getTexture(), nouvelleTaille, asteroides[i].getPosition());
                }
                vague.clearAsteroid(i); // Supprimer l'astéroïde touché
                break;
            }
        }
    }

    // Collision entre le vaisseau et les astéroïdes
    for (const auto &asteroide : vague.getAsteroides())
    {
        if (vaisseau.getBounds().intersects(asteroide.getBounds()))
        {
            jeuTermine = true; // Le jeu se termine si le vaisseau est touché
            break;
        }
    }
}