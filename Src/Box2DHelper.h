#ifndef BOX2DHELPER_H
#define BOX2DHELPER_H

#include <Box2D/Box2D.h>

namespace Box2DHelper {
    inline b2World* CreateWorld() {
        static b2Vec2 gravity(0.0f, -0.1f); // Gravedad reducida para caída lenta
        static b2World world(gravity);
        return &world;
    }

    inline b2Body* CreateStaticBox(b2World* world, float x, float y, float width, float height) {
        b2BodyDef bodyDef;
        bodyDef.position.Set(x, y);
        b2Body* body = world->CreateBody(&bodyDef);
        b2PolygonShape box;
        box.SetAsBox(width / 2.0f, height / 2.0f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &box;
        fixtureDef.density = 0.0f; // Suelo fijo, no debe moverse
        fixtureDef.restitution = 0.1f; // Evita rebote excesivo
        fixtureDef.friction = 0.8f; // Asegura más fricción
        body->CreateFixture(&fixtureDef);

        return body;
    }

    inline b2Body* CreateDynamicBox(b2World* world, float x, float y, float width, float height) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(x, y);
        b2Body* body = world->CreateBody(&bodyDef);
        b2PolygonShape box;
        box.SetAsBox(width / 2.0f, height / 2.0f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &box;
        fixtureDef.density = 1.0f; // Masa suficiente para una caída natural
        fixtureDef.friction = 0.3f;
        body->CreateFixture(&fixtureDef);

        return body;
    }
}

#endif
