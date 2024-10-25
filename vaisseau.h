#ifndef VAISSEAU_H
#define VAISSEAU_H
#include "mobile.h"

class Vaisseau : public Mobile
{

public:
	Vaisseau(const std::string &textureFile);

protected:
	sf::Clock clock; // starts the clock
	float delay;
};
#endif
