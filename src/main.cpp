#include <iostream>
#include <SFML/Graphics.hpp>
#include "../headers/mobile.h"
#include "../headers/vaisseau.h"
#include "../headers/asteroide.h"
#include "../headers/jeu.h"

int main()
{
	// Créer la fenêtre
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Asteroidus");

	Mobile ship("sprites/jul.png");
	Asteroide meteorite("sprites/Asteroid.png", PETIT);
	ship.setPosition(800.f, 500.f);

	// Créer une horloge pour le mouvement et une autre pour la rotation
	sf::Clock movementClock;
	sf::Clock rotationClock;
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("sprites/bg.jpg");
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(
		static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x,
		static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y);
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

		// Déplacer le vaisseau en fonction des touches pressées
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			ship.move(-100.f * deltaTime.asSeconds(), 0.f); // Se déplacer vers la gauche
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			ship.move(100.f * deltaTime.asSeconds(), 0.f); // Se déplacer vers la droite
		}

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
		// Dessin du background
		window.draw(backgroundSprite);

		// Dessiner le vaisseau dans la fenêtre
		ship.draw(window);
		meteorite.draw(window);

		// Afficher le contenu dessiné
		window.display();
	}

	return 0;
}
