#include "SFMLRenderer.h"

SFMLRenderer::SFMLRenderer(Game& game) : game(game) {
    blockShape.setSize(sf::Vector2f(120.0f, 120.0f)); // Representación de 4x4 metros
    blockShape.setFillColor(sf::Color::Red);
    blockShape.setOrigin(60.0f, 60.0f); // Centrar el origen en el cuadrado

    groundShape.setSize(sf::Vector2f(400.0f, 20.0f));
    groundShape.setFillColor(sf::Color::Blue);
    groundShape.setPosition(200, 550); // Aseguramos que el suelo esté en su lugar
}

void SFMLRenderer::Render(sf::RenderWindow& window) {
    b2Vec2 blockPos = game.GetBlock()->GetPosition();

    float scale = 30.0f; // Factor de conversión de metros a píxeles

    blockShape.setPosition(blockPos.x * scale + 400, 550 - blockPos.y * scale); // Ajuste preciso
    groundShape.setPosition(200, 550); // Asegurar que el suelo esté bien ubicado

    window.draw(blockShape);
    window.draw(groundShape);
}
