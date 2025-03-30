#include "UI.hpp"

UI::UI() : life_pos_start{150, 100}, life_pos_end{400, 100}, ammo_pos{500, 150}
{
    LOG("UI elements were constructed");
}

void UI::update_ui(Player &player)
{
    if (IsMouseButtonPressed(1))
    {
        player.health -= 40;
    }
    if (player.health < 150)
    {
        exit(1);
    }
    DrawLineEx(life_pos_start, life_pos_end, 30, BLACK);
    Vector2 life_amount = {player.health, life_pos_end.y};
    DrawLineEx(life_pos_start, life_amount, 30, MAROON);
}

UI::~UI()
{
    LOG("UI destroyed");
}