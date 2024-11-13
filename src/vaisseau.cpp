#include "vaisseau.h"
#include <stdexcept>
#include <math.h>

// Constructeur par défaut
Vaisseau::Vaisseau()
    : Mobile(), delay(0.5f) // Initialisation avec valeurs par défaut
{
    // Ce constructeur peut être utile si vous voulez initialiser un vaisseau sans texture
    isAlive = true; // Le vaisseau est en vie par défaut
}

// Constructeur avec un fichier de texture
Vaisseau::Vaisseau(const sf::Texture &texture, const sf::Vector2f &position)
    : Mobile(texture) // Appel au constructeur de Mobile
{
    this->angle = 0.0f;   // Angle initial
    this->speed = 200.0f; // Vitesse initiale
    sprite.setPosition(position);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2); // Centre du vaisseau
}

// Getter pour deltaTime
float Vaisseau::getdeltaTime()
{
    return deltaTime;
}

// Getter pour delay
float Vaisseau::getdelay()
{
    return delay; // Assurez-vous que 'delay' est défini dans votre classe Jeu
}

// Getter pour clock
sf::Clock Vaisseau::getclock()
{
    return clock; // Retourne une copie de l'objet sf::Clock
}

void Vaisseau::tourner(float angleDelta)
{
    angle += angleDelta;       // Mettre à jour l'angle
    sprite.setRotation(angle); // Appliquer la rotation au sprite
}

void Vaisseau::update(float deltaTime)
{
    // Convertir l'angle en radians pour le calcul du mouvement
    float angleRadians = angle * 3.14159f / 180.0f;

    // Calculer le déplacement
    sf::Vector2f deplacement(
        std::cos(angleRadians) * speed * deltaTime,
        std::sin(angleRadians) * speed * deltaTime);

    // Déplacer le sprite
    sprite.move(deplacement);
}
