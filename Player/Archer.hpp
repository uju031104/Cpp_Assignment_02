#pragma once
#include "Player.hpp"

class Archer : public Player
{
public:
    Archer(std::string name);
    void attack() override;
};