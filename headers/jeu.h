#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>
#include "mobile.h"
#include "vaisseau.h"
#include "asteroide.h"
#include "vague.h"
#include "projectile.h"
#include <memory>

class Jeu
{
public:
    Jeu(const std::string &textureFile);
    Jeu(const std::string &textureFile,
        sf::Texture texturebg,
        int numeroVague,
        bool jeuTermine,
        std::vector<std::unique_ptr<Projectile>> tirs,
        sf::Texture &textureVaisseau,
        sf::Vector2f positionVaisseau);

    Vague vague;
    Vaisseau vaisseau;

    void dessiner(sf::RenderWindow &fenetre);
    void gererCollisions();                          // Vérifie et gère les collisions
    void gererEvenements(sf::RenderWindow &fenetre); // Gère les évènements
    void tirerProjectile();                          // Ajoute un projectile au vecteur `tirs`
    void mettreAJourBackground(const sf::RenderWindow &window);
    void verifierPositionVaisseau(Vaisseau &vaisseau, const sf::RenderWindow &fenetre);
    void gameOver(sf::RenderWindow &fenetre);

protected:
    sf::Texture texturebg;
    sf::Sprite background;
    int numeroVague;
    bool jeuTermine;
    std::vector<std::unique_ptr<Projectile>> tirs;
};

#endif
