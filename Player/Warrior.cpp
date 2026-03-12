#include "Warrior.hpp"

Warrior::Warrior(std::string name) : Player(name)
{
    player_info.push_back(5);  // 공격력
    player_info.push_back(10); // 방어력
    player_info.push_back(20); //    HP
    player_info.push_back(10); //    MP
    player_info.push_back(5);  // 스피드
    player_info.push_back(0);  //   Exp
    player_info.push_back(1);  // Level
};

void Warrior::attack()
{
    std::cout << player_name << "이(가) 검을 휘둘렀다." << std::endl;
}
