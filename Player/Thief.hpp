#pragma once
#include "Player.hpp"

class Thief : public Player
{
public:
    Thief(std::string name);
    void attack() override;
};