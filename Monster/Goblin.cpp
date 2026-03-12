#include "Goblin.hpp"

Goblin::Goblin(std::string name) : Monster(name)
{
    monster_info.push_back(11); // 공격력
    monster_info.push_back(0);  // 방어력
    monster_info.push_back(10); //    HP
    monster_info.push_back(7);  // 스피드
    monster_info.push_back(1);  //   Exp
    monster_info.push_back(1);  // Level
};

void Goblin::attack()
{
    std::cout << monster_name << "이(가) 작은 도끼를 휘둘렀다." << std::endl;
}