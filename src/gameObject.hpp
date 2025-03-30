#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "../raylib/src/raylib.h"

class Vector2;

class gameObject
{
public:
    Vector2 pos;
    Vector2 dir;
    float speed;
    float size;
    int life_time;

public:
    gameObject();
    gameObject(Vector2 pos, Vector2 dir, float speed, float size, int life_time);
    void draw_gameObject();
    void update_obj();
    ~gameObject();
};

#endif