#include "main.hpp"

static void handle_proj(std::vector<gameObject> &objects)
{
    for (gameObject &obj : objects)
    {
        obj.draw_gameObject();
    }
    for (gameObject &obj : objects)
    {
        obj.update_obj();
    }
    int i = 0;
    for (gameObject &obj : objects)
    {
        if (obj.life_time >= 150)
        {
            objects.erase(objects.begin() + i);
        }
    }
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "!(Cub)2d");

    SetTargetFPS(TARGET_FPS);
    // ToggleFullscreen();

    Player player;

    UI ui;

    std::vector<gameObject> objects;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        LOG(objects.size());
        player.move_player();
        player.player_attack(objects);
        ui.update_ui(player);
        handle_proj(objects);
        ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow();
    objects.clear();

    return 0;
}