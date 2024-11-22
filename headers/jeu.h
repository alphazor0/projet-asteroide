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
    // Constructeurs de classe
    Jeu(const std::string &textureFile);
    Jeu(const std::string &textureFile,
        sf::Texture texturebg,
        sf::Texture textureProjectile,
        sf::Texture &asteroidTexture,
        int numeroVague,
        bool jeuTermine,
        std::vector<std::unique_ptr<Projectile>> tirs,
        sf::Texture &textureVaisseau,
        sf::Vector2f positionVaisseau,
        sf::Vector2u windowSize);

    // Éléments du Jeu
    Vague vague;
    Vaisseau vaisseau;

    // Méthodes liées aux évènements
    void gererEvenements(sf::RenderWindow &fenetre); // Gère les évènements
    void tirerProjectile();                          // Gère la création des projectiles

    // Méthodes liées à l'affichage
    void dessiner(sf::RenderWindow &fenetre);                   // Dessine tous les éléments du jeu dans la fenêtre (vaisseau, projectiles, astéroïdes, etc.)
    void dessinerProjectiles(sf::RenderWindow &fenetre);        // Dessiner les projectiles
    void dessinerAsteroides(sf::RenderWindow &fenetre);         // Dessiner les astéroides
    void mettreAJourBackground(const sf::RenderWindow &window); // Ajuste la taille du fond pour correspondre à la taille de la fenêtre

    // Méthodes liées aux interactions
    void verifierPositionVaisseau(Vaisseau &vaisseau, const sf::RenderWindow &fenetre); // Vérifie si le vaisseau est dans la fenêtre et pas en dehors
    void gererCollisions();                                                             // Vérifie et gère les collisions
    void mettreAJourProjectiles();

    // Méthode pour gérer l'état du jeu
    void gameOver(sf::RenderWindow &fenetre); // Gère l'affichage du Game Over si la partie est terminée

protected:
    sf::Texture texturebg;
    sf::Texture textureProjectile; // Texture unique pour les projectiles
    sf::Sprite background;
    int numeroVague;
    bool jeuTermine;
    std::vector<std::unique_ptr<Projectile>> tirs;
};

#endif
