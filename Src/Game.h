#ifndef GAME_H
#define GAME_H

#include "Box2DHelper.h"

class Game {
public:
    Game();
    void Update();
    b2Body* GetBlock();
    b2Body* GetGround();

private:
    b2World* world;
    b2Body* ground;
    b2Body* block;
};

#endif
