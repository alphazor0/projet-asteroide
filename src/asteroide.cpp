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
Asteroide::Asteroide(const sf::Texture &textureFile, TailleAsteroide taille)
    : Mobile(textureFile), // Appel au constructeur de Mobile avec un argument
      tailleAsteroide(taille)
{
    tailleAsteroide = taille;
    // Définir l'échelle en fonction de la taille
    switch (taille)
    {
    case PETIT:
        sprite.setScale(0.5f, 0.5f); // Échelle pour petit
        break;
    case MOYEN:
        sprite.setScale(1.0f, 1.0f); // Échelle pour moyen
        break;
    case GRAND:
        sprite.setScale(1.5f, 1.5f); // Échelle pour grand
        break;
    default:
        std::cerr << "Taille inconnue pour l'astéroïde.\n";
        break;
    }
}

TailleAsteroide Asteroide::getTaille() const
{
    return tailleAsteroide;
}

// sf::FloatRect Asteroide::getBounds() const
// {
//     return sprite.getGlobalBounds(); // Retourne les limites globales du sprite
// }
