#pragma once

#include <iostream>
#include <vector>
#include <string>

// Player 클래스 정의
class Player
{
public:
    // 생성과 동시에 아이디를 입력
    Player(std::string name);

    //플레이어의 정보를 출력하는 함수
    void print_player_info();

    // 아이디를 얻을 수 있는 get 함수
    std::string get_player_name();
    // 플레이어의 정보를 얻을 수 있는 get 함수
    int get_player_info(int index);

    // 플레이어의 기본 스탯을 수정할 수 있는 함수(레벨업, 몬스터와 싸울때 사용)
    void set_player_info(int info_Index, int set_value);

    // 직업마다 다른 공격을 출력하는 가상 함수
    virtual void attack() = 0;

    virtual ~Player() {}

protected:
    std::string player_name;
    std::vector<int> player_info;

    // 플레이어 아이디를 설정하는 함수
    void set_player_name(std::string name);
};