#include "vaisseau.h"
#include <stdexcept>

// Constructeur par défaut
Vaisseau::Vaisseau()
    : Mobile(), delay(0.5f) // Initialisation avec valeurs par défaut
{
    // Ce constructeur peut être utile si vous voulez initialiser un vaisseau sans texture
    isAlive = true; // Le vaisseau est en vie par défaut
}

// Constructeur avec un fichier de texture
Vaisseau::Vaisseau(const sf::Texture &texture)
    : Mobile(texture), delay(0.5f) // Appel au constructeur de Mobile
{
    // Positionner le vaisseau au bas de l'écran (centre horizontal)
    sprite.setPosition(400.0f, 500.0f); // Exemple de position par défaut
    isAlive = true;                     // Le vaisseau commence en vie
}
