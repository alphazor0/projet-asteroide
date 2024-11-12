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

Jeu::Jeu(const std::string &textureFile,
         sf::Texture texturebg,
         int numeroVague,
         bool jeuTermine,
         std::vector<std::unique_ptr<Projectile>> tirs,
         sf::Texture textureVaisseau,
         sf::Vector2f positionVaisseau)
    : texturebg(texturebg),                       // Initialisation de la texture de fond
      numeroVague(numeroVague),                   // Initialisation du numéro de vague
      jeuTermine(jeuTermine),                     // Initialisation de l'état du jeu
      tirs(std::move(tirs)),                      // Initialisation des tirs
      vaisseau(textureVaisseau, positionVaisseau) // Initialisation du vaisseau
{
    // Charger la texture de fond
    if (!this->texturebg.loadFromFile(textureFile))
    {
        throw std::runtime_error("Erreur de chargement de la texture de fond : " + textureFile);
    }

    // Configurer le sprite de fond
    background.setTexture(this->texturebg);

    // Charger la texture du vaisseau
    if (!textureVaisseau.loadFromFile("sprites/jul.png"))
    {
        throw std::runtime_error("Erreur de chargement de la texture du vaisseau : sprites/ship.png");
    }

    // Configurer le sprite du vaisseau (déjà fait via son constructeur)
}

void Jeu::mettreAJourBackground(const sf::RenderWindow &window)
{
    background.setScale(
        static_cast<float>(window.getSize().x) / background.getTexture()->getSize().x,
        static_cast<float>(window.getSize().y) / background.getTexture()->getSize().y);
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

void Jeu::gererEvenements(sf::RenderWindow &fenetre)
{
    sf::Event event;
    while (fenetre.pollEvent(event))
    {
        // Gestion des événements de la fenêtre
        if (event.type == sf::Event::Closed)
        {
            fenetre.close();
        }
        else if (event.type == sf::Event::Resized)
        {
            // Mise à jour de la vue pour correspondre à la nouvelle taille de la fenêtre
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            fenetre.setView(sf::View(visibleArea));
        }
    }

    // Gestion des entrées clavier pour le vaisseau
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        vaisseau.tourner(-100.0f * vaisseau.getdeltaTime()); // Tourner à gauche
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        vaisseau.tourner(100.0f * vaisseau.getdeltaTime()); // Tourner à droite
    }
}
