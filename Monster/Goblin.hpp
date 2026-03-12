#pragma once
#include "Monster.hpp"

class Goblin : public Monster
{
public:
    Goblin(std::string name);
    void attack() override;
};