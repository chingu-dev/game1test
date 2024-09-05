#include "vault.h"
#include <raylib.h>

void Vault::Update() {
    // Update logic for Vault (currently empty)
}

void Vault::Draw() {
    DrawRectangle(position.x - width/2, position.y - height/2, width, height, BLUE);
}
