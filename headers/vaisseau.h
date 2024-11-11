#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "mobile.h"
#include "projectile.h"

class Vaisseau : public Mobile
{

public:
	Vaisseau();
	Vaisseau(const std::string &textureFile);

protected:
	sf::Clock clock; // starts the clock
	float delay;
};
#endif
