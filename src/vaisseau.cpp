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
    this->angle = 0.0f; // Angle initial
    this->speed = 5.0f; // Vitesse initiale
    this->delay = 0.5f;
    sprite.setPosition(position);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2); // Centre du vaisseau
    sprite.setScale(0.1f, 0.1f);
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

void Vaisseau::tourner(float angle)
{
    sprite.rotate(angle); // Appliquer la rotation au sprite
}

void Vaisseau::avancer()
{
    // Convertir l'angle en radians
    float angleRadians = sprite.getRotation() * M_PI / 180.0f;

    // Calculer les déplacements sur X et Y
    float dx = std::cos(angleRadians) * speed;
    float dy = std::sin(angleRadians) * speed;

    // Mettre à jour la position
    sprite.move(dx, dy);
}
