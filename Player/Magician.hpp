#pragma once
#include "Player.hpp"

class Magician : public Player
{
public:
    Magician(std::string name);
    void attack() override;
};