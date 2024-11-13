#include <iostream>
#include <SFML/Graphics.hpp>
#include "mobile.h"
#include "vaisseau.h"
#include "asteroide.h"
#include "jeu.h"

int main()
{
	// Créer la fenêtre
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Asteroidus");
	window.setVerticalSyncEnabled(true);

	// sf::Texture shiptexture;
	// shiptexture.loadFromFile("sprites/jul.png");
	// Mobile ship(shiptexture);
	// sf::Texture asteroidetexture;
	// asteroidetexture.loadFromFile("sprites/Asteroid.png");
	// Asteroide meteorite(asteroidetexture, PETIT);
	// sf::Vector2f position(800.f, 500.f);
	// ship.setPosition(position);

	// Créer une horloge pour le mouvement et une autre pour la rotation
	sf::Clock movementClock;
	sf::Clock rotationClock;

	// Créer une liste de projectiles
	sf::Texture textureProjectile;
	if (!textureProjectile.loadFromFile("sprites/bullet.png"))
	{
		throw std::runtime_error("Erreur de chargement de la texture des projectiles.");
	}

	std::vector<std::unique_ptr<Projectile>> tirs;
	tirs.emplace_back(std::make_unique<Projectile>(textureProjectile, sf::Vector2f(400, 500), sf::Vector2f(0, -1)));
	tirs.emplace_back(std::make_unique<Projectile>(textureProjectile, sf::Vector2f(450, 450), sf::Vector2f(0, -1)));

	// Charger la texture du vaisseau
	sf::Texture vaisseauTexture;
	if (!vaisseauTexture.loadFromFile("sprites/jul.png"))
	{
		throw std::runtime_error("Erreur de chargement de la texture du vaisseau");
	}

	// Position initiale du vaisseau
	sf::Vector2f positionVaisseau(400.0f, 500.0f);

	// Initialiser le jeu
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("sprites/bg.jpg");

	Jeu jeu("sprites/bg.jpg", backgroundTexture, 1, false, std::move(tirs), vaisseauTexture, positionVaisseau);
	jeu.mettreAJourBackground(window);

	// Créer une horloge pour le temps écoulé
	sf::Clock clock;

	// Boucle principale
	while (window.isOpen())
	{
		// Gérer les événements
		jeu.gererEvenements(window);

		// Mettre à jour le temps écoulé
		float deltaTime = clock.restart().asSeconds();

		// Mettre à jour les entités du jeu
		jeu.update(deltaTime);

		// Effacer la fenêtre
		window.clear();

		// Dessiner les éléments du jeu
		jeu.dessiner(window);

		// Afficher le contenu dessiné
		window.display();
	}

	return 0;
}
