#include "asteroide.h"

// Constructeur
Asteroide::Asteroide(const std::string &textureFile, TailleAsteroide taille)
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
    case ENORME:
        sprite.setScale(2.0f, 2.0f); // Échelle pour énorme
        break;
    default:
        std::cerr << "Taille inconnue pour l'astéroïde.\n";
        break;
    }
}
