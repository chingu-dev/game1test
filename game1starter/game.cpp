#include "game.h"


Game::Game() : running(true) {
    // Initialize the pointer
    pointer.width = 55;
    pointer.height = 40;
    pointer.color = WHITE;
    pointer.LoadTexture("graphics/arrow.png"); // Load texture

    TraceLog(LOG_INFO, "Game initialized and texture loaded for pointer");
}



Game::~Game() {
    pointer.UnloadArrow(); // Cleanup texture
}

void Game::Update() {
    vault.Update();
    enemy.Update();
    player.Update();
    pointer.Update(player, vault);
    for(auto& projectile: player.projectiles) {
        projectile.Update();
    }
}

void Game::Draw() {
    vault.Draw();
    enemy.Draw();
    player.Draw();
    pointer.Draw();
    for(auto& projectile: player.projectiles) {
        projectile.Draw();
    }
}

void Game::HandleFiring(Camera2D camera) {
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        player.FireProjectile(camera);
    }
}
