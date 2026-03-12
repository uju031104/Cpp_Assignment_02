#include "Archer.hpp"

Archer::Archer(std::string name) : Player(name)
{
    player_info.push_back(7);  // 공격력
    player_info.push_back(8);  // 방어력
    player_info.push_back(15); //    HP
    player_info.push_back(15); //    MP
    player_info.push_back(10); // 스피드
    player_info.push_back(0);  //   Exp
    player_info.push_back(1);  // Level
};

void Archer::attack()
{
    std::cout << player_name << "이(가) 활을 쐈다." << std::endl;
}

