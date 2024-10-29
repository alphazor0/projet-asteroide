#ifndef JEU_H
#define JEU_H

#include <SFML/Graphics.hpp>
#include "mobile.h"
#include "vaisseau.h"
#include "asteroide.h"
#include "vague.h"

class Jeu
{
public:
    Jeu(const std::string &textureFile);
    Vague vague();
    Vaisseau vaisseau();
    void run();

protected:
    sf::Texture texturebg;
    sf::Sprite background;
};

#endif
