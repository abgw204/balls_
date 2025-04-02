#ifndef UI_HPP
#define UI_HPP
#include "main.hpp"

class UI
{
private:
    Vector2 life_pos_start;
    Vector2 life_pos_end;
    Vector2 ammo_pos;
    bool main_menu;

public:
    UI();
    void update_ui(Player &player);
    ~UI();
};

#endif