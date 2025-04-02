#include "UI.hpp"

UI::UI() : life_pos_start{150, 100}, life_pos_end{400, 100}, ammo_pos{500, 150}, main_menu(true)
{
    LOG("UI elements were constructed");
}

void UI::update_ui(Player &player)
{
    Vector2 pos = {player.pos.x - 300, player.pos.y - 300};
    Vector2 end = {pos.x + 250, pos.y};
    DrawLineEx(pos, end, 30, BLACK);
    // health issue
    DrawLineEx(pos, end, 30, RED);
}

UI::~UI()
{
    LOG("UI destroyed");
}