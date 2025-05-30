#include "Game.h"

Game::Game() {
    world = Box2DHelper::CreateWorld();

    // Ajustamos el suelo a la posici�n correcta
    ground = Box2DHelper::CreateStaticBox(world, 0.0f, -1.0f, 20.0f, 1.0f);

    // Posicionamos el bloque justo encima del suelo
    block = Box2DHelper::CreateDynamicBox(world, 0.0f, 9.5f, 4.0f, 4.0f);
    block->SetBullet(true); // Asegura una mejor detecci�n de colisi�n

    // Aseguramos que el bloque tenga una densidad adecuada
    b2Fixture* fixture = block->GetFixtureList();
    if (fixture) {
        fixture->SetDensity(1.0f);
    }
}

void Game::Update() {
    world->Step(1.0f / 240.0f, 20, 10); // M�s precisi�n en la simulaci�n
}

b2Body* Game::GetBlock() { return block; }
b2Body* Game::GetGround() { return ground; }
