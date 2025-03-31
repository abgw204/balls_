#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "main.hpp"

class Enemy
{
public:
    Vector2 pos;
    Vector2 dir;
    float size;
    float health;
    float speed;
    unsigned char life_t;
    bool enemyConfused;
    int confused_time;
    bool show_health;
    bool hit;
    int hit_slow;

public:
    Enemy();
    Enemy(Vector2 pos,
          Vector2 dir,
          float size,
          float health,
          float speed,
          unsigned char life_t,
          bool enemyConfused,
          int confused_time,
          bool show_health,
          bool hit,
          int hit_slow);
    void draw_enemy();
    void update_enemy(Player &player);
    void normalize_opossite_dir_e(Player &player);
    ~Enemy();
};

#endif