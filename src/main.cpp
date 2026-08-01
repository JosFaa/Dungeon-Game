#include "raylib.h"

int main(){
    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 720;
    constexpr int roomWidth = 1000;
    constexpr int roomHeight = 600;
    constexpr float playerRadius = 25;

    const Rectangle room {
        screenWidth/2 - roomWidth/2,
        screenHeight/2 - roomHeight/2,
        roomWidth,
        roomHeight
    };

    const Vector2 player {
        screenWidth/2,
        screenHeight/2
    }; 

    

    InitWindow(screenWidth, screenHeight, "Dungeon Game");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(Color{25, 25, 30, 255});
            DrawRectangleRec(room, RAYWHITE);
            DrawCircleV(player, playerRadius, BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}