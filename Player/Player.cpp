#include "Player.hpp"

// public
// 생성자
Player::Player(std::string name)
{
    set_player_name(name);
}

// 플레이어의 정보를 출력하는 함수
void Player::print_player_info()
{
    std::cout << "공격력: " << player_info[0] << std::endl;
    std::cout << "방어력: " << player_info[1] << std::endl;
    std::cout << " H P : " << player_info[2] << std::endl;
    std::cout << " M P : " << player_info[3] << std::endl;
    std::cout << "Speed: " << player_info[4] << std::endl;
    std::cout << "E x p: " << player_info[5] << std::endl;
    std::cout << "Level: " << player_info[6] << std::endl;
    std::cout << std::endl;
}

// 아이디를 얻을 수 있는 get 함수
std::string Player::get_player_name()
{
    return player_name;
}

// 플레이어의 정보를 얻을 수 있는 get 함수
int Player::get_player_info(int index)
{
    return player_info[index];
}

// 플레이어의 기본 스탯을 수정할 수 있는 함수(레벨업, 몬스터와 싸울때 사용)
void Player::set_player_info(int info_Index, int set_value)
{
    player_info[info_Index] = set_value;
}

// protected
// 플레이어 아이디를 설정하는 함수
void Player::set_player_name(std::string name)
{
    player_name = name;
}

