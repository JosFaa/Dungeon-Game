#include "raylib.h"
#include <cmath>
#include <algorithm>

void playerMovement(Vector2& playerPosition, const Rectangle room,const float playerRadius) {
    constexpr float playerSpeed = 300.0;
    float directionX=0.0;
    float directionY=0.0;
    
    if (IsKeyDown(KEY_W)) {directionY -= 1;}
    if (IsKeyDown(KEY_A)) {directionX -= 1;}
    if (IsKeyDown(KEY_S)) {directionY += 1;}
    if (IsKeyDown(KEY_D)) {directionX += 1;}

    const float directionLength = std::sqrt(directionX * directionX + directionY * directionY);
    if (directionLength > 0.0) { // normalize movement speed
        directionX /= directionLength;
        directionY /= directionLength;
    }

    const float deltaTime = GetFrameTime(); // making movement independent of frame rate

    // update players Position
    playerPosition.x += directionX * playerSpeed * deltaTime; 
    playerPosition.y += directionY * playerSpeed * deltaTime;

    playerPosition.x =std::clamp( // keep player bounded in the room (x)
        playerPosition.x,
        room.x + playerRadius,
        room.x + room.width - playerRadius
    );

    playerPosition.y = std::clamp( // keep player bounded in the room (y)
        playerPosition.y, 
        room.y + playerRadius,
        room.y + room.height - playerRadius
    );
};

int main(){
    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 720;
    constexpr int roomWidth = 1000;
    constexpr int roomHeight = 600;
    const float playerRadius = 25.0;

    const Rectangle room {
        screenWidth/2 - roomWidth/2,
        screenHeight/2 - roomHeight/2,
        roomWidth,
        roomHeight
    };

    Vector2 playerPosition {
        screenWidth/2,
        screenHeight/2
    }; 


    

    InitWindow(screenWidth, screenHeight, "Dungeon Game");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        playerMovement(playerPosition, room, playerRadius);
        BeginDrawing();
            ClearBackground(Color{25, 25, 30, 255});
            DrawRectangleRec(room, RAYWHITE);
            DrawCircleV(playerPosition, playerRadius, BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

