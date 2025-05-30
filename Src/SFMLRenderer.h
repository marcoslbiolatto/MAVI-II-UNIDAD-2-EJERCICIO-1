#ifndef SFMLRENDERER_H
#define SFMLRENDERER_H

#include <SFML/Graphics.hpp>
#include "Game.h"

class SFMLRenderer {
public:
    SFMLRenderer(Game& game);
    void Render(sf::RenderWindow& window);

private:
    Game& game;
    sf::RectangleShape blockShape;
    sf::RectangleShape groundShape;
};

#endif
