#include "main.hpp"

Player::Player() : pos{300, 300}, dir{100, 100}, health(400), speed(4), proj_speed(10), proj_counter(0), proj_delay(10), proj_delay_counter(0)
{
	LOG("A player was created in a default way");
}

Player::Player(float p_x, float p_y, float p_w, float p_h, float p_speed) : speed(p_speed)
{
	LOG("A player was created with preset parameters");
}

void Player::move_player()
{
	Vector2 direction = {0, 0};
	if (IsKeyDown(KEY_W))
		direction.y -= 1;
	if (IsKeyDown(KEY_A))
		direction.x -= 1;
	if (IsKeyDown(KEY_S))
		direction.y += 1;
	if (IsKeyDown(KEY_D))
		direction.x += 1;
	if (direction.x != 0 || direction.y != 0)
		direction = Vector2Normalize(direction);
	pos.x += direction.x * speed;
	pos.y += direction.y * speed;

	Vector2 newDir = Vector2Normalize(Vector2Subtract(GetMousePosition(), pos));
	Vector2 targetPos = {pos.x + newDir.x * 30, pos.y + newDir.y * 30};
	DrawCircle(pos.x, pos.y, 15, BLACK);
	DrawLineEx(pos, targetPos, 10, BLACK);
}

void Player::player_attack(std::vector<gameObject> &objects)
{
	if (IsMouseButtonPressed(0) && proj_delay_counter >= proj_delay)
	{
		Vector2 _dir = Vector2Normalize(Vector2Subtract(GetMousePosition(), pos));
		gameObject new_proj(pos, _dir, proj_speed, 6.0f, 0);
		objects.push_back(new_proj);
		proj_delay_counter = 0;
	}
	proj_delay_counter++;
}

/*if ((jump_diff >= 0) || (jump_diff < 0 && jump_diff >= -20))
				rec.y -= jump_diff--;
			else
				rec.y -= jump_diff;
*/
/*void Player::ground_collision(World &world)
{
	if (y >= obj.get_y() - 50)
	{
		grounded = true;
		jumping = false;
		jump_diff = jump_height;
	}
}*/

Player::~Player()
{
	LOG("A player was destroyed");
}