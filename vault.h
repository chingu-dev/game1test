#pragma once
#include <raylib.h>

class Vault {
public:
    Vector2 position;
    int width, height;
    int hitPoints;

    void Update();
    void Draw();
};

