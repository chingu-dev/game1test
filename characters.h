#pragma once

#include <raylib.h>
#include "projectile.h"
#include "vault.h"
#include <vector>

class Projectile;

class Player {
public:
    Vector2 position;
    int speed_x, speed_y;
    int radius;
    int hitPoints;

    void Update();
    void Draw();
    void FireProjectile(Camera2D camera);
    std::vector<Projectile> projectiles;

};

class Enemy {
public:
    float x, y;
    int speed_x, speed_y;
    int radius;
    int hitPoints;
    int count;
    int type;

    void Update();
    void Draw();
};

class Pointer {
public:
    int x, y;
    int width, height;
    Color color;
    Texture2D texture; // Ensure Texture2D is used

    void Update(const Player& player, const Vault& vault);
    void Draw() const;
    void LoadTexture(const char* path);
    void UnloadArrow();
    
private:
    float angle; // Added to keep track of the rotation angle
};
