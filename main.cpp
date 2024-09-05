#include <raylib.h>
#include "game.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Game1");
    SetTargetFPS(60);

    Game game;

    // Initialize game objects
    game.vault.position = {screenWidth/2.0f, screenHeight/2.0f};
    game.vault.width = 20;
    game.vault.height = 20;

    // Initialize player's position as a Vector2
    game.player.position = {screenWidth / 2.0f + 60.0f, screenHeight / 2.0f + 60.0f};
    game.player.radius = 10;
    game.player.speed_x = 3;
    game.player.speed_y = game.player.speed_x;

    game.enemy.x = screenWidth / 2.0f - 90.0f;
    game.enemy.y = screenHeight / 2.0f - 90.0f;
    game.enemy.radius = 7;
    game.enemy.speed_x = 3;
    game.enemy.speed_y = game.enemy.speed_x;

    Camera2D camera = {0};
    camera.target = game.player.position; // Initialize target
    camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;


    while (!WindowShouldClose()) 
    {
        TraceLog(LOG_INFO, "Game Loop Running"); 
        // Update camera to follow the player using the Vector2 position
        camera.target = game.player.position;

        // Clamp the camera to stop tracking outside of the world's boundaries
        if (game.player.position.x < screenWidth / 2.0f) {
            camera.target.x = screenWidth / 2.0f;
        }
        if (game.player.position.x > worldWidth - screenWidth / 2.0f) {
            camera.target.x = worldWidth - screenWidth / 2.0f;
        }
        if (game.player.position.y < screenHeight / 2.0f) {
            camera.target.y = screenHeight / 2.0f;
        }
        if (game.player.position.y > worldHeight - screenHeight / 2.0f) {
            camera.target.y = worldHeight - screenHeight / 2.0f;
        }

        // Ensure camera offset centers the player (but keep boundaries in mind)
        camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};

        TraceLog(LOG_INFO, "Starting drawing cycle");
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);

        game.Update();
        game.Draw();
        game.HandleFiring(camera);
        TraceLog(LOG_INFO, "Drawing cycle completed");

        EndMode2D();
        EndDrawing();
    }


    CloseWindow();
    return 0;
}
