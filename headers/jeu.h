#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>
#include "mobile.h"
#include "vaisseau.h"
#include "asteroide.h"
#include "vague.h"
#include <memory>

class Jeu
{
public:
    Jeu(const std::string &textureFile);
    Vague vague;
    Vaisseau vaisseau;
    void run();
    void gererCollisions(); // Vérifie et gère les collisions
    void tirerProjectile(); // Ajoute un projectile au vecteur `tirs`
    

protected:
    sf::Texture texturebg;
    sf::Sprite background;
    int numeroVague;
    bool jeuTermine;
    std::vector<std::unique_ptr<Projectile>> tirs;
};

#endif
