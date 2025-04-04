#include "main.hpp"

Player::Player() : pos{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f},
				   dir{100, 100},
				   health(400),
				   speed(4),
				   proj_speed(12),
				   proj_delay(5),
				   proj_delay_counter(0),
				   size(20),
				   hit(false),
				   confused_time(30),
				   can_shoot(true)
{
	LOG("A player was created in a default way");
}

void Player::move_player(Camera2D camera)
{
	if (health < 150) // player death UI
		exit(1);

	Vector2 direction = {0, 0};
	if (!hit)
	{
		can_shoot = true;
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
	}
	else
		confused_time--;
	if (confused_time == 0)
	{
		hit = false;
		confused_time = 30;
	}
	pos.x += direction.x * speed;
	pos.y += direction.y * speed;

	Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
	Vector2 newDir = Vector2Normalize(Vector2Subtract(mouseWorldPos, pos));
	Vector2 targetPos = {pos.x + newDir.x * 35, pos.y + newDir.y * 35};
	if (hit)
	{
		DrawCircle(pos.x, pos.y, size, RED);
		DrawLineEx(pos, targetPos, 14, RED);
	}
	else
	{
		DrawCircle(pos.x, pos.y, size, BLACK);
		DrawLineEx(pos, targetPos, 14, BLACK);
	}
}

void Player::player_attack(std::vector<gameObject> &objects, Camera2D camera)
{

	if (IsMouseButtonDown(0) && proj_delay_counter >= proj_delay && can_shoot)
	{
		Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
		Vector2 _dir = Vector2Normalize(Vector2Subtract(mouseWorldPos, pos));
		objects.emplace_back(pos, _dir, proj_speed, 5.0f, 0);
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