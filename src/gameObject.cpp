#include "main.hpp"

gameObject::gameObject() : pos{0, 0}, dir{0, 0}, size(0.5)
{
    LOG("A gameObject was created in a default way");
}

gameObject::gameObject(Vector2 pos, Vector2 dir, float speed, float size, int life_time) : pos(pos), dir(dir), speed(speed), size(size), life_time(life_time)
{
    LOG("A gameObject was created in a parameters way");
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
    LOG("A gameObject was destroyed");
}