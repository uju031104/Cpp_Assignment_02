#pragma once
#include "Monster.hpp"

class Troll : public Monster
{
public:
    Troll(std::string name);
    void attack() override;
};