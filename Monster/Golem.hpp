#pragma once
#include "Monster.hpp"

class Golem : public Monster
{
public:
    Golem(std::string name);
    void attack() override;
};