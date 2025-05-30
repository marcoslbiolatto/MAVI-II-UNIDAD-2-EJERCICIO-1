#include "SFMLRenderer.h"

SFMLRenderer::SFMLRenderer(Game& game) : game(game) {
    blockShape.setSize(sf::Vector2f(120.0f, 120.0f)); // Representaci�n de 4x4 metros
    blockShape.setFillColor(sf::Color::Red);
    blockShape.setOrigin(60.0f, 60.0f); // Centrar el origen en el cuadrado

    groundShape.setSize(sf::Vector2f(400.0f, 20.0f));
    groundShape.setFillColor(sf::Color::Blue);
    groundShape.setPosition(200, 550); // Aseguramos que el suelo est� en su lugar
}

void SFMLRenderer::Render(sf::RenderWindow& window) {
    b2Vec2 blockPos = game.GetBlock()->GetPosition();

    float scale = 30.0f; // Factor de conversi�n de metros a p�xeles

    blockShape.setPosition(blockPos.x * scale + 400, 550 - blockPos.y * scale); // Ajuste preciso
    groundShape.setPosition(200, 550); // Asegurar que el suelo est� bien ubicado

    window.draw(blockShape);
    window.draw(groundShape);
}
