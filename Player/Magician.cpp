#include "Magician.hpp"

Magician::Magician(std::string name) : Player(name)
{
    player_info.push_back(10); // 공격력
    player_info.push_back(5);  // 방어력
    player_info.push_back(10); //    HP
    player_info.push_back(20); //    MP
    player_info.push_back(5);  // 스피드
    player_info.push_back(0);  //   Exp
    player_info.push_back(1);  // Level
};

void Magician::attack()
{
    std::cout << player_name << "이(가) 파이어볼을 날렸다." << std::endl;
}
