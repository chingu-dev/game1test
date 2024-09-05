#pragma once
#include <raylib.h>

extern const int worldWidth;
extern const int worldHeight;

class Projectile {
public:
    Projectile(Vector2 position, Vector2 speed);
    void Update();
    void Draw();
    bool active;
    Vector2 position;
    Vector2 speed;
};