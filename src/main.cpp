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
	window.setVerticalSyncEnabled(false);

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

	// Charger la texture du vaisseau
	sf::Texture vaisseauTexture;
	if (!vaisseauTexture.loadFromFile("sprites/ship.png"))
	{
		throw std::runtime_error("Erreur de chargement de la texture du vaisseau");
	}

	// Position initiale du vaisseau
	sf::Vector2f positionVaisseau(960.0f, 570.0f);

	std::vector<std::unique_ptr<Projectile>> tirs;

	// Passer cette texture lors de l'appel à tirerProjectile

	// Initialiser le jeu
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("sprites/bg.png");

	sf::Texture textureProjectile;
	textureProjectile.loadFromFile("sprites/bullet.png");

	Jeu jeu("sprites/bg.png", backgroundTexture, textureProjectile, 1, false, std::move(tirs), vaisseauTexture, positionVaisseau);
	jeu.mettreAJourBackground(window);

	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close(); // Quitter l'application
		}

		// Mettre à jour le jeu avant de dessiner
		jeu.gererEvenements(window);
		jeu.gererCollisions();

		// Effacer la fenêtre
		window.clear();

		// Dessiner le jeu
		jeu.dessiner(window);

		// Afficher le contenu dessiné
		window.display();
	}

	return 0;
}
