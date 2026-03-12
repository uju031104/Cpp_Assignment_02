#include "Monster.hpp"

Monster::Monster(std::string name)
{
    set_monster_name(name);
}

std::string Monster::get_monster_name()
{
    return monster_name;
}

int Monster::get_monster_info(int index)
{
    return monster_info[index];
}

void Monster::set_monster_name(std::string name)
{
    monster_name = name;
}
