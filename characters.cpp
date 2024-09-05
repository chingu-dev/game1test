#include "characters.h"
#include <raylib.h>
#include <math.h>
#include <raymath.h>
#include "game.h"

class Projectile;
Game game;

// Player methods
void Player::Update() {
    // Movement control with WASD keys
    if (IsKeyDown(KEY_W)) position.y -= speed_y; // Move up
    if (IsKeyDown(KEY_S)) position.y += speed_y; // Move down
    if (IsKeyDown(KEY_A)) position.x -= speed_x; // Move left
    if (IsKeyDown(KEY_D)) position.x += speed_x; // Move right

    // Boundary checks to ensure player stays within the world limits
    if (position.y - radius < 0) position.y = radius;                       // Top boundary
    if (position.y + radius > worldHeight) position.y = worldHeight - radius; // Bottom boundary
    if (position.x - radius < 0) position.x = radius;                        // Left boundary
    if (position.x + radius > worldWidth) position.x = worldWidth - radius;   // Right boundary
}


Vector2 NormalizeVector(Vector2 v) {
    float length = sqrt(v.x * v.x + v.y * v.y);
    if (length != 0) {
        v.x /= length;
        v.y /= length;
    }
    return v;
}

void Player::Draw() {
    DrawCircle(position.x, position.y, radius, BLUE);  // Using position.x and position.y
}


void Player::FireProjectile(Camera2D camera) {
    // Create a projectile at the player's position
    Vector2 mousePos = GetScreenToWorld2D(GetMousePosition(), camera);
    Vector2 direction = {mousePos.x - position.x, mousePos.y - position.y};
    direction = NormalizeVector(direction);
    float projectileSpeed = 5.0f;
    direction.x *= projectileSpeed;
    direction.y *= projectileSpeed;
    Projectile newProjectile(position, direction);
    projectiles.push_back(newProjectile);

}

void Pointer::Update(const Player& player, const Vault& vault) {
    // Get the player's position
    Vector2 playerPos = player.position; // Use player's updated Vector2 position

    // Get the vault's position (assuming Vault has a Vector2 position)
    Vector2 vaultPos = vault.position; // Use vault's Vector2 position

    // Calculate the direction vector from the player to the vault
    Vector2 direction = {vaultPos.x - playerPos.x, vaultPos.y - playerPos.y};

    // Calculate the angle to rotate the pointer towards the vault
    angle = atan2(direction.y, direction.x) * (180.0f / PI); // Convert to degrees

    // Update the pointer's position to match the player's position
    x = playerPos.x; // Match pointer's position to player's X
    y = playerPos.y; // Match pointer's position to player's Y
}


void Pointer::LoadTexture(const char* path) {
    Image arrowImage = LoadImage(path);
if (arrowImage.data == NULL) {
    TraceLog(LOG_ERROR, "Failed to load image data");
} else {
    TraceLog(LOG_INFO, "Image loaded successfully");
}

// Convert image to texture
texture = LoadTextureFromImage(arrowImage);
if (texture.id == 0) {
    TraceLog(LOG_ERROR, "Failed to convert image to texture");
}
UnloadImage(arrowImage);  // Unload image data once texture is created

}


void Pointer::Draw() const {
    if (texture.id != 0) {
        Rectangle sourceRect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };  // Full texture
        Rectangle destRect = { (float)x, (float)y, (float)width, (float)height };  // Draw at position with width/height
        Vector2 origin = { width / 2.0f, height / 2.0f };  // Center of rotation
        DrawTexturePro(texture, sourceRect, destRect, origin, 0.0f, WHITE);
    } else {
        TraceLog(LOG_ERROR, "Texture ID is invalid, skipping draw");
    }
}



void Pointer::UnloadArrow() {
    UnloadTexture(texture);
}

// Enemy methods
void Enemy::Update() {
    // Add pathfinding logic for the enemy here
}

void Enemy::Draw() {
    DrawCircle(x, y, radius, RED);
}
