#include "main.hpp"

gameObject::gameObject() : pos{0, 0}, dir{0, 0}, speed(5), size(0.5), life_time(0)
{
    LOG("A projectile was created in a default way");
}

gameObject::gameObject(Vector2 pos, Vector2 dir, float speed, float size, int life_time) : pos(pos), dir(dir), speed(speed), size(size), life_time(life_time)
{
    LOG("A projectile was created with parameters");
}

void gameObject::draw_gameObject()
{
    DrawCircle(pos.x, pos.y, size, BLACK);
}

void gameObject::update_obj()
{
    pos.x += dir.x * speed;
    pos.y += dir.y * speed;
    life_time++;
}

gameObject::~gameObject()
{
    LOG("A projectile was destroyed");
}