#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "mobile.h"
#include "projectile.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Vaisseau : public Mobile
{
public:
	// Constructeurs
	Vaisseau();															// Constructeur par défaut
	Vaisseau(const sf::Texture &texture, const sf::Vector2f &position); // Constructeur avec texture

	// Méthodes principales
	void tirer(std::vector<Projectile> &projectiles, const sf::Texture &textureProjectile); // Créer un projectile
	void mettreAJour();																		// Mettre à jour le vaisseau, par exemple pour la gestion du délai entre les tirs
	void tourner(float angleDelta);
	void avancer();
	void restartClock();

	// Getters
	float getdeltaTime();		// Permet d'accéder à l'attribut deltaTime encapsulé
	float getdelay();			// Permet d'accéder à l'attribut delay encapsulé
	sf::Clock getclock();		// Permet d'accéder à l'attribut encapsulé clock
	

protected:
	sf::Clock clock; // Gestion du temps pour limiter la fréquence des tirs
	float delay;	 // Temps minimum entre les tirs (en secondes)
	float deltaTime; // Permet de calculer le temps écoulé entre 2 frames
};

#endif
