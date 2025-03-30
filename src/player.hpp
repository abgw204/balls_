#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "main.hpp"
#include "../raylib/src/raylib.h"
#include <vector>

class gameObject;

class Player
{
public:
	Vector2 pos;
	Vector2 dir;
	float health;
	float speed;
	float proj_speed;
	float proj_counter;
	int proj_delay;
	int proj_delay_counter;
	Player();
	Player(float x, float y, float w, float h, float s);
	void move_player();
	void player_attack(std::vector<gameObject> &object);
	~Player();
};

#endif
