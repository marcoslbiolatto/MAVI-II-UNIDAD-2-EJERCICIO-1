#include <SFML/Graphics.hpp>
#include "Game.h"
#include "SFMLRenderer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "caida de bloque");
    Game game;
    SFMLRenderer renderer(game);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        game.Update();
        window.clear();
        renderer.Render(window);
        window.display();
    }
    return 0;
}
