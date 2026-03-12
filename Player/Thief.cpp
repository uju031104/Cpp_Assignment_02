#include "Thief.hpp"

Thief::Thief(std::string name) : Player(name)
{
    player_info.push_back(8);  // 공격력
    player_info.push_back(7);  // 방어력
    player_info.push_back(15); //    HP
    player_info.push_back(15); //    MP
    player_info.push_back(10); // 스피드
    player_info.push_back(0);  //   Exp
    player_info.push_back(1);  // Level
};

void Thief::attack()
{
    std::cout << player_name << "이(가) 단검을 휘둘렀다." << std::endl;
}
