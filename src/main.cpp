#include "main.hpp"

static void handle_collisions_proj(Player &player, std::vector<Enemy> &enemies, std::vector<gameObject> &objects)
{
    for (Enemy &enemy : enemies)
    {
        for (int i = objects.size() - 1; i >= 0; i--)
        {
            if (CheckCollisionCircles(objects[i].pos, objects[i].size, enemy.pos, enemy.size))
            {
                enemy.health -= 12;
                enemy.show_health = true;
                enemy.hit = true;
                objects.erase(objects.begin() + i);
            }
        }
    }
}

static void handle_collisions(Player &player, std::vector<Enemy> &enemies)
{
    for (Enemy &enemy : enemies)
    {
        if (CheckCollisionCircles(player.pos, player.size, enemy.pos, enemy.size))
        {
            // player.health -= 40;
            enemy.enemyConfused = true;
            player.hit = true;
            player.can_shoot = false;
        }
    }
}

static void handle_enemy(std::vector<Enemy> &enemies, Player &player)
{
    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
                       [&player](Enemy &enemy)
                       {
                           enemy.update_enemy(player);
                           enemy.draw_enemy();
                           return enemy.health < -15;
                       }),
        enemies.end());
}

static void handle_proj(std::vector<gameObject> &objects)
{
    for (int i = objects.size() - 1; i >= 0; i--)
    {
        objects[i].draw_gameObject();
        objects[i].update_obj();
        if (objects[i].life_time >= 200)
            objects.erase(objects.begin() + i);
    }
}

int main()
{
    std::vector<gameObject> objects;
    objects.reserve(200);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "!(Cub)2d");
    Player player;
    Camera2D camera;
    camera.offset = (Vector2){SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(TARGET_FPS);
    ToggleFullscreen();

    UI ui;

    std::vector<Enemy> enemies;
    enemies.reserve(50);
    for (int i = 0; i < 50; i++)
        enemies.emplace_back(Vector2{(float)GetRandomValue(0, 2300), (float)GetRandomValue(0, 1500)}, Vector2{0, 0}, 17, 17, 3, 0, false, 30, false, false, 20, 30);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        BeginMode2D(camera);
        camera.target = (Vector2){player.pos.x + 20.0f, player.pos.y + 20.0f};

        ClearBackground(WHITE);
        handle_enemy(enemies, player);
        handle_collisions(player, enemies);
        player.move_player(camera);
        player.player_attack(objects, camera);
        // ui.update_ui(player);
        handle_proj(objects);
        handle_collisions_proj(player, enemies, objects);

        EndDrawing();
    }

    CloseWindow();
    objects.clear();

    return 0;
}