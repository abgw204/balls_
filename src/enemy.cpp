#include "enemy.hpp"

Enemy::Enemy() : pos{200, 200},
                 dir{200, 200},
                 size(17), health(17),
                 speed(3), life_t(0),
                 enemyConfused(false),
                 confused_time(30),
                 show_health(false),
                 hit(false),
                 hit_slow(30)
{
    LOG("An enemy was created with default parameters");
}

Enemy::Enemy(Vector2 pos,
             Vector2 dir,
             float size,
             float health,
             float speed,
             unsigned char life_t,
             bool enemyConfused,
             int confused_time,
             bool show_health,
             bool hit,
             int hit_slow)
    : pos(pos),
      dir(dir),
      size(size),
      health(health),
      speed(speed),
      life_t(life_t),
      enemyConfused(enemyConfused),
      confused_time(confused_time),
      show_health(show_health),
      hit(hit),
      hit_slow(hit_slow)
{
    LOG("An enemy was created with parameters");
}

void Enemy::draw_enemy()
{
    DrawCircle(pos.x, pos.y, size, RED);
    if (!show_health)
        return;

    if (show_health)
        DrawLineEx({pos.x - 19, pos.y - 25}, {pos.x + health, pos.y - 25}, 4, {0, 0, 0, life_t});
    if (life_t < 220)
        life_t += 10;
}

void Enemy::normalize_opossite_dir_e(Player &player)
{
    Vector2 newDir = Vector2Normalize(Vector2Subtract(pos, player.pos));
    pos.x += newDir.x * speed;
    pos.y += newDir.y * speed;
    confused_time--;
}

void Enemy::update_enemy(Player &player)
{
    if (hit && hit_slow == 30)
        speed -= 1;
    if (hit)
        hit_slow--;
    if (hit_slow == 0)
    {
        hit = false;
        speed += 1;
        hit_slow = 30;
    }
    if (!enemyConfused)
    {
        Vector2 newDir = Vector2Normalize(Vector2Subtract(player.pos, pos));
        pos.x += newDir.x * speed;
        pos.y += newDir.y * speed;
    }
    else
        normalize_opossite_dir_e(player);
    if (confused_time == 0)
    {
        enemyConfused = false;
        confused_time = 30;
    }
}

Enemy::~Enemy()
{
    LOG("An enemy was destroyed");
}