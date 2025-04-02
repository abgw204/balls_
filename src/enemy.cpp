#include "enemy.hpp"

Enemy::Enemy() : pos{200, 200},
                 dir{200, 200},
                 size(17), health(17),
                 speed(3), life_t(0),
                 enemyConfused(false),
                 confused_time(30),
                 show_health(false),
                 hit(false),
                 hit_slow(30),
                 walking_diff(30)
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
             int hit_slow,
             float walking_diff)
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
      hit_slow(hit_slow),
      walking_diff(walking_diff)
{
    LOG("An enemy was created with parameters");
}

void Enemy::draw_enemy()
{
    DrawCircle(pos.x, pos.y, size, RED);
    if (!show_health)
        return;

    DrawLineEx({pos.x - 19, pos.y - 25}, {pos.x + health, pos.y - 25}, 4, {0, 0, 0, life_t});
    if (life_t < 220)
        life_t += 10;
}

void Enemy::normalize_opossite_dir_e(Player &player, float current_speed)
{
    Vector2 newDir = Vector2Normalize(Vector2Subtract(pos, player.pos));
    pos.x += newDir.x * current_speed;
    pos.y += newDir.y * current_speed;
    confused_time--;
}

void Enemy::update_enemy(Player &player)
{
    float current_speed = speed;

    if (hit)
    {
        current_speed *= 0.5f;
        hit_slow--;
        if (hit_slow <= 0)
        {
            hit = false;
            hit_slow = 30;
        }
    }
    if (!enemyConfused)
    {
        current_speed -= walking_diff > 0 ? walking_diff / 10 : 0;
        walking_diff--;
        Vector2 newDir = Vector2Normalize(Vector2Subtract(player.pos, pos));
        pos.x += newDir.x * current_speed;
        pos.y += newDir.y * current_speed;
    }
    else
    {
        walking_diff = 30;
        current_speed += confused_time / 10;
        normalize_opossite_dir_e(player, current_speed);
    }
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