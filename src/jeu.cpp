#include "jeu.h"
#include <iostream>
#include <math.h>

sf::Texture asteroidTBis;

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
         sf::Texture textureProjectile,
         sf::Texture &asteroidTexture,
         int numeroVague,
         bool jeuTermine,
         std::vector<Projectile> tirs,
         sf::Texture &textureVaisseau,
         sf::Vector2f positionVaisseau,
         sf::Vector2u windowSize)
    : texturebg(texturebg),                        // Initialisation de la texture de fond
      numeroVague(numeroVague),                    // Initialisation du numéro de vague
      jeuTermine(jeuTermine),                      // Initialisation de l'état du jeu
      tirs(tirs),                                  // Initialisation des tirs
      vaisseau(textureVaisseau, positionVaisseau), // Initialisation du vaisseau
      windowSize(windowSize),
      vague(numeroVague, asteroidTexture, windowSize)

{

    // Charger la texture de fond
    if (!this->texturebg.loadFromFile(textureFile))
    {
        throw std::runtime_error("Erreur de chargement de la texture de fond : " + textureFile);
    }

    // Configurer le sprite de fond
    background.setTexture(this->texturebg);

    asteroidTBis.loadFromFile("sprites/asteroid.png");

    // Charger la texture du vaisseau
    if (!textureVaisseau.loadFromFile("sprites/ship.png"))
    {
        throw std::runtime_error("Erreur de chargement de la texture du vaisseau : sprites/ship.png");
    }

    // Charger la texture des projectiles
    if (!textureProjectile.loadFromFile("sprites/bullet1.png"))
    {
        std::cerr << "Erreur de chargement de la texture des projectiles" << std::endl;
        throw std::runtime_error("Erreur de chargement de la texture des projectiles");
    }
    else
    {
        std::cout << "Texture des projectiles chargée avec succès" << std::endl;
    }
}

void Jeu::mettreAJourBackground(const sf::RenderWindow &window)
{
    background.setScale(
        static_cast<float>(window.getSize().x) / background.getTexture()->getSize().x,
        static_cast<float>(window.getSize().y) / background.getTexture()->getSize().y);
}

void Jeu::dessinerProjectiles(sf::RenderWindow &fenetre)
{

    for (const auto &tir : tirs)
    {
        if (tir.isAlive) // Vérifier si le projectile est actif
        {
            /*std::cout << "Dessiner projectile à : (" << tir.getSprite().getPosition().x
                      << ", " << tir.getSprite().getPosition().y << ")" << std::endl;*/
            fenetre.draw(tir.getSprite());
        }
    }

    for (const auto &tir : tirs)
    {
        if (tir.isAlive)
        {
            sf::RectangleShape debugShape;
            debugShape.setSize(sf::Vector2f(10.f, 5.f)); // Set rectangle size
            debugShape.setFillColor(sf::Color::Red);     // Set rectangle color
            debugShape.setPosition(tir.getSprite().getPosition());
            debugShape.setOrigin(debugShape.getSize().x / 2, debugShape.getSize().y / 2); // Center the rectangle
            fenetre.draw(debugShape);
        }
    }
}
void Jeu::dessinerAsteroides(sf::RenderWindow &fenetre)
{
    for (const auto &asteroide : vague.getAsteroides())
    {
        fenetre.draw(asteroide.getSprite());
    }
}

void Jeu::dessinerBackground(sf::RenderWindow &fenetre)
{
    fenetre.draw(background);
}

void Jeu::dessinerVaisseau(sf::RenderWindow &fenetre)
{
    fenetre.draw(vaisseau.getSprite());
}

void Jeu::dessiner(sf::RenderWindow &fenetre)
{
    // Dessiner le fond
    dessinerBackground(fenetre);

    // Dessiner les projectiles
    dessinerProjectiles(fenetre);

    // Dessiner les astéroïdes via la vague
    dessinerAsteroides(fenetre);

    // Dessiner le vaisseau
    dessinerVaisseau(fenetre);
}

void Jeu::tirerProjectile()
{
    if (!vaisseau.isAlive)
        return;

    // Vérifier si l'intervalle entre les tirs est écoulé
    if (vaisseau.getclock().getElapsedTime().asSeconds() < vaisseau.getdelay())
        return;

    vaisseau.getclock().restart(); // Redémarrer le timer des tirs

    // Obtenir la position centrale du vaisseau
    sf::Vector2f positionCentre = vaisseau.getCenter();

    // Calculer la direction en fonction de l'orientation du vaisseau
    float angleRadians = vaisseau.getAngle() * M_PI / 180.0f;
    sf::Vector2f direction(std::cos(angleRadians), std::sin(angleRadians));

    // Ajouter un nouveau projectile
    tirs.emplace_back(textureProjectile, positionCentre, direction, 10.f);

    //     // Debug : Vérifier le nombre de tirs
    //                   std::cout
    //         << "Projectile créé : position (" << positionCentre.x << ", " << positionCentre.y
    //         << "), direction (" << direction.x << ", " << direction.y << ")" << std::endl;
}

void Jeu::mettreAJourProjectiles()
{
    for (auto &tir : tirs)
    {
        tir.avancer();
    }

    // Supprimer les projectiles inactifs
    tirs.erase(std::remove_if(tirs.begin(), tirs.end(),
                              [](const Projectile &tir)
                              { return !tir.isAlive; }),
               tirs.end());
}

void Jeu::mettreAJourAsteroides()
{
    vague.update();
}

void Jeu::gererCollisions()
{

    // Collision entre les projectiles et les astéroïdes
    auto &asteroides = vague.getAsteroides();
    for (auto &tir : tirs)
    {
        for (int i = 0; i < asteroides.size(); ++i)
        {
            if (asteroides[i].getBounds().contains(tir.positionDuTir()))
            {

                // Diviser l'astéroïde ou le supprimer
                if (asteroides[i].getTaille() != PETIT)
                {
                    TailleAsteroide nouvelleTaille = static_cast<TailleAsteroide>(asteroides[i].getTaille() - 1);
                    asteroides.emplace_back(asteroides[i].getTexture(), nouvelleTaille, asteroides[i].getPosition());
                    asteroides.emplace_back(asteroides[i].getTexture(), nouvelleTaille, asteroides[i].getPosition());
                }
                vague.clearAsteroid(i); // Supprimer l'astéroïde touché

                if (vague.isCleared())
                {
                    std::cout << "Prochaine vague" << std::endl;
                    nouvelleVague(); // https://www.youtube.com/watch?v=QLkcDtdlKkk
                }
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

void Jeu::nouvelleVague()
{
    numeroVague = numeroVague + 1;
    vague.genererVague(numeroVague, asteroidTBis, windowSize);
    std::cout << numeroVague << std::endl;
}

void Jeu::verifierPositionVaisseau(Vaisseau &vaisseau, const sf::RenderWindow &fenetre)
{
    sf::Vector2f position = vaisseau.getSprite().getPosition();
    sf::Vector2u windowSize = fenetre.getSize();

    // Si le vaisseau sort de la fenêtre, il "meurt" ou explose ou se perd dans l'espace et c'est gameover
    if (position.x < 0)
    {
        vaisseau.isAlive = false;
        jeuTermine = true;
    }
    else if (position.x > windowSize.x)
    {
        vaisseau.isAlive = false;
        jeuTermine = true;
    }

    if (position.y < 0)
    {
        vaisseau.isAlive = false;
        jeuTermine = true;
    }
    else if (position.y > windowSize.y)
    {
        vaisseau.isAlive = false;
        jeuTermine = true;
    }
}

void Jeu::gererEvenements(sf::RenderWindow &fenetre)
{
    if (!vaisseau.isAlive || jeuTermine) // si le vaisseau est mort ou si le jeu est terminé on gameover
    {
        gameOver(fenetre);
    }
    sf::Event event;

    // Appel de tirerProjectile pour tirer en continu
    tirerProjectile();
    mettreAJourProjectiles();
    mettreAJourAsteroides();

    // Vérifiez que le vaisseau reste dans les limites de l'écran
    verifierPositionVaisseau(vaisseau, fenetre);

    // Déplacer le vaisseau en continu
    vaisseau.avancer();

    // Boucle pour détecter les évènements
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
        // Gestion des entrées clavier pour le vaisseau
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        fenetre.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        vaisseau.tourner(-2.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        vaisseau.tourner(2.f);
    }
}

void Jeu::gameOver(sf::RenderWindow &fenetre)
{
    // Effacer la fenêtre
    fenetre.clear();

    // Charger une police pour afficher un message
    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf")) // Remplacez par le chemin de votre police
    {
        throw std::runtime_error("Erreur de chargement de la police.");
    }

    // Créer un texte pour afficher "Game Over"
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(64);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Bold);

    // Centrer le texte dans la fenêtre
    gameOverText.setPosition(
        fenetre.getSize().x / 2.f - gameOverText.getGlobalBounds().width / 2.f,
        fenetre.getSize().y / 3.f);

    // Créer un texte pour afficher les instructions
    sf::Text restartText;
    restartText.setFont(font);
    restartText.setString("Appuyez sur R pour redemarrer ou ESC pour quitter");
    restartText.setCharacterSize(32);
    restartText.setFillColor(sf::Color::White);
    restartText.setPosition(
        fenetre.getSize().x / 2.f - restartText.getGlobalBounds().width / 2.f,
        fenetre.getSize().y / 2.f);

    // Afficher les messages
    fenetre.draw(gameOverText);
    fenetre.draw(restartText);
    fenetre.display();

    // Boucle pour gérer les événements pendant l'écran de fin
    sf::Event event;
    while (fenetre.waitEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            fenetre.close(); // Quitter le jeu
            break;
        }

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        // {
        //     restart(); //
        //     break;
        // }
    }
}
