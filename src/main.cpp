#include "main.hpp"

static void handle_collisions_proj(Player &player, std::vector<Enemy> &enemies, std::vector<gameObject> &objects)
{
    int i;
    for (Enemy &enemy : enemies)
    {
        i = 0;
        for (gameObject &proj : objects)
        {
            if (CheckCollisionCircles(proj.pos, proj.size, enemy.pos, enemy.size))
            {
                enemy.health -= 12;
                enemy.show_health = true;
                enemy.hit = true;
                objects.erase(objects.begin() + i);
            }
            i++;
        }
    }
}

static void handle_collisions(Player &player, std::vector<Enemy> &enemies)
{
    for (Enemy &enemy : enemies)
    {
        if (CheckCollisionCircles(player.pos, player.size, enemy.pos, enemy.size))
        {
            player.health -= 40;
            enemy.enemyConfused = true;
            player.hit = true;
            player.can_shoot = false;
        }
    }
}

static void handle_enemy(std::vector<Enemy> &enemies, Player &player)
{
    int i = 0;
    for (Enemy &enemy : enemies)
    {
        enemy.update_enemy(player);
        enemy.draw_enemy();
        if (enemy.health < -15) // place for a death animation
            enemies.erase(enemies.begin() + i);
        i++;
    }
}
static void handle_proj(std::vector<gameObject> &objects)
{
    for (gameObject &obj : objects)
    {
        obj.draw_gameObject();
        obj.update_obj();
    }
    int i = 0;
    for (gameObject &obj : objects)
    {
        if (obj.life_time >= 200)
            objects.erase(objects.begin() + i);
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
    std::vector<Enemy> enemies;

    Enemy enemy({800, 300}, {0, 0}, 17, 17, 3, 0, false, 30, false, false, 20);
    enemies.push_back(enemy);
    enemies.emplace_back();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        handle_enemy(enemies, player);
        handle_collisions(player, enemies);
        player.move_player();
        player.player_attack(objects);
        ui.update_ui(player);
        handle_proj(objects);
        handle_collisions_proj(player, enemies, objects);
        ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow();
    objects.clear();

    return 0;
}