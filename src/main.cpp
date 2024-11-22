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

	// Charger les textures
	sf::Texture backgroundTexture, textureProjectile, textureVaisseau, asteroidTexture;

	if (!backgroundTexture.loadFromFile("sprites/bg.png") ||
		!textureProjectile.loadFromFile("sprites/bullet1.png") ||
		!textureVaisseau.loadFromFile("sprites/ship.png") ||
		!asteroidTexture.loadFromFile("sprites/asterolienne.png"))
	{
		std::cerr << "Erreur de chargement des textures" << std::endl;
		return -1;
	}

	// Initialiser le jeu
	sf::Vector2f positionVaisseau(960.0f, 540.0f);
	std::vector<Projectile> tirs;
	Jeu jeu("sprites/bg.png", backgroundTexture, textureProjectile, asteroidTexture, 1, false, tirs, textureVaisseau, positionVaisseau, window.getSize());

	sf::Sprite testSprite;
	testSprite.setTexture(textureProjectile);
	testSprite.setPosition(400.f, 300.f); // Example position

	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(testSprite);
		jeu.gererEvenements(window);
		jeu.gererCollisions();
		jeu.dessiner(window);
		window.display();
	}

	return 0;
}
