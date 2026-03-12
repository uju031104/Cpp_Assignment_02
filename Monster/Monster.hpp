#pragma once

#include <iostream>
#include <vector>
#include <string>

// Player 클래스 정의
class Monster
{
public:
    Monster(std::string name);

    std::string get_monster_name();
    int get_monster_info(int index);

    virtual void attack() = 0;

    ~Monster() {}

protected:
    std::string monster_name;
    std::vector<int> monster_info;

    void set_monster_name(std::string name);
};