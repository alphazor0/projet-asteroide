#ifndef JEU_H
#define JEU_H

#include "jeu.h"
#include <iostream>

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

Vaisseau Jeu::vaisseau()
{
    return Vaisseau("path/to/your/vaisseau_texture.png"); // Remplacez par le bon chemin
}

Asteroide Jeu::asteroide()
{
    return Asteroide("path/to/your/asteroide_texture.png", Asteroide::PETIT); // Remplacez par le bon chemin
}

void Jeu::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mon Jeu");

    // Mettre à l'échelle le sprite de fond pour qu'il couvre la fenêtre
    background.setScale(
        static_cast<float>(window.getSize().x) / texturebg.getSize().x,
        static_cast<float>(window.getSize().y) / texturebg.getSize().y);

    // Créer un vaisseau et un astéroïde
    Vaisseau monVaisseau = vaisseau();
    Asteroide monAsteroide = asteroide();

    // Boucle principale du jeu
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Dessiner l'arrière-plan
        window.draw(background);

        // Dessiner le vaisseau et l'astéroïde ici (ajustez selon votre implémentation)
        // window.draw(monVaisseau.getSprite());
        // window.draw(monAsteroide.getSprite());

        window.display();
    }
}

#endif