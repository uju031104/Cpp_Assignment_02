#include "Golem.hpp"

Golem::Golem(std::string name) : Monster(name)
{
    monster_info.push_back(100); // 공격력
    monster_info.push_back(100);  // 방어력
    monster_info.push_back(500); //    HP
    monster_info.push_back(0);  // 스피드
    monster_info.push_back(100);  //   Exp
    monster_info.push_back(3);  // Level
};

void Golem::attack()
{
    std::cout << monster_name << "이(가) 육중 한 팔을 휘둘렀다." << std::endl;
}