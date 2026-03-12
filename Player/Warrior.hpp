#pragma once
#include "Player.hpp"

class Warrior : public Player
{
public:
    Warrior(std::string name);
    void attack() override;
};