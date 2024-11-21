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

	// Charger la texture du vaisseau
	sf::Texture vaisseauTexture;
	if (!vaisseauTexture.loadFromFile("sprites/ship.png"))
	{
		throw std::runtime_error("Erreur de chargement de la texture du vaisseau");
	}

	// Position initiale du vaisseau
	sf::Vector2f positionVaisseau(960.0f, 570.0f);

	std::vector<std::unique_ptr<Projectile>> tirs;
	tirs.emplace_back(std::make_unique<Projectile>(textureProjectile, sf::Vector2f(400, 500), sf::Vector2f(0, -1)));
	tirs.emplace_back(std::make_unique<Projectile>(textureProjectile, sf::Vector2f(450, 450), sf::Vector2f(0, -1)));

	// Initialiser le jeu
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("sprites/bg.jpg");

	Jeu jeu("sprites/bg.jpg", backgroundTexture, 1, false, std::move(tirs), vaisseauTexture, positionVaisseau);
	jeu.mettreAJourBackground(window);

	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;

		// Gérer les événements
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Obtenir le temps écoulé depuis la dernière frame pour les mouvements
		sf::Time deltaTime = movementClock.restart();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close(); // Quitter l'application
		}

		// Rotation chaque seconde
		// sf::Time elapsedTimeForRotation = rotationClock.getElapsedTime();
		// if (elapsedTimeForRotation.asSeconds() >= 0.001f)
		// {
		// 	ship.rotate(0.036f);	 // Tourner de 36 degrés
		// 	rotationClock.restart(); // Réinitialiser l'horloge de rotation
		// }

		// Afficher le temps écoulé pour le debug
		// std::cout << "Elapsed time for rotation: " << elapsedTimeForRotation.asSeconds() << " seconds" << std::endl;

		// Effacer la fenêtre
		window.clear();

		jeu.dessiner(window);
		jeu.gererCollisions();
		jeu.gererEvenements(window);

		// Afficher le contenu dessiné
		window.display();
	}

	return 0;
}
