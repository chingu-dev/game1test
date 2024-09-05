#pragma once

#include "vault.h"
#include "characters.h"

extern const int worldWidth;
extern const int worldHeight;

class Game {
public:
    Vault vault;
    Player player;
    Enemy enemy;
    Pointer pointer;
    bool running;

    Game();
    ~Game(); // Destructor to ensure proper cleanup
    void Update();
    void Draw();
    void HandleFiring(Camera2D camera);
};

