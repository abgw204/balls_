#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "main.hpp"
#include "../raylib/src/raylib.h"
#include <vector>

class gameObject;
class Enemy;

class Player
{
public:
	Vector2 pos;
	Vector2 dir;
	float health;
	float speed;
	float proj_speed;
	int proj_delay;
	int proj_delay_counter;
	float size;
	bool hit;
	int confused_time;
	bool can_shoot;
	Player();
	void move_player(Camera2D camera);
	void normalize_opossite_dir_p(Enemy &enemy);
	void player_attack(std::vector<gameObject> &object, Camera2D camera);
	~Player();
};

#endif
