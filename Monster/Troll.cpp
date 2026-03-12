#include "Troll.hpp"

Troll::Troll(std::string name) : Monster(name)
{
    monster_info.push_back(30); // 공격력
    monster_info.push_back(30);  // 방어력
    monster_info.push_back(100); //    HP
    monster_info.push_back(30);  // 스피드
    monster_info.push_back(10);  //   Exp
    monster_info.push_back(2);  // Level
};

void Troll::attack()
{
    std::cout << monster_name << "이(가) 거대한 몽둥이를 휘둘렀다." << std::endl;
}