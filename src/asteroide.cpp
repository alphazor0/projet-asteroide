#include "asteroide.h"


// Getters

const sf::Texture &Asteroide::getTexture() const
{
    if (sprite.getTexture())
    {
        return *sprite.getTexture(); // Retourne la texture liée au sprite
    }
    else
    {
        throw std::runtime_error("Aucune texture associée à ce sprite !");
    }
}

sf::Vector2f Asteroide::getPosition() const
{
    return sprite.getPosition(); // Utilise la méthode SFML pour retourner la position actuelle
}


// Constructeur
Asteroide::Asteroide(const sf::Texture &textureFile, TailleAsteroide taille, const sf::Vector2f &position)
    : Mobile(textureFile),    // Appel au constructeur de Mobile
      tailleAsteroide(taille) // Initialisation de la taille
{
    // Associe la texture au sprite (hérité de Mobile)
    sprite.setTexture(textureFile);

    // Définir la position initiale
    sprite.setPosition(position);

    // Ajuster l'échelle en fonction de la taille
    switch (taille)
    {
    case PETIT:
        sprite.setScale(0.5f, 0.5f);
        break;
    case MOYEN:
        sprite.setScale(1.0f, 1.0f);
        break;
    case GRAND:
        sprite.setScale(1.5f, 1.5f);
        break;
    default:
        std::cerr << "Erreur : Taille inconnue pour l'astéroïde." << std::endl;
        break;
    }
}

TailleAsteroide Asteroide::getTaille() const
{
    return tailleAsteroide;
}

