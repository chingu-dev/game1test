#include "projectile.h"
#include <raymath.h>

const int worldWidth = 50000;
const int worldHeight = 50000;

Projectile::Projectile(Vector2 position, Vector2 speed)
{
    this -> position = position;
    this -> speed = speed;
    active = true;
}

void Projectile::Draw() {
    if(active)
        DrawRectangle(position.x, position.y, 15, 15, WHITE);
}

void Projectile::Update() {
    position.x += speed.x;
    position.y += speed.y;
    if(active)
    {
        if((position.y > worldHeight || position.y < 0) && (position.x > worldWidth || position.x < 0)) 
        {
            active = false;
        }    
    }
}