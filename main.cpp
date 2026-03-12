#include "main.hpp"

/**************************게임 시작 전 세팅***************************/
// 아이디 생성
std::string make_id();
// 직업 선택
int choice_class();
// 선택한 직업의 정보(스탯)
void announce_class(int class_number, Player &player_ref);

/*****************************게임 시작*******************************/
// 게임 메뉴 출력
int print_game_menu();
// 게임 튜토리얼 출력
void print_game_info();

/*****************************몬스터사냥*******************************/
// 몬스터 사냥 메뉴
void print_monster_menu(Player &player_ref, std::vector<Monster *> &monster_ref);
// 몬스터 사냥 시작
void start_hunt_monster(Player &player_ref_ref, Monster *monster_ref_monster);
// 플레이어와 몬스터의 전투력 비교

int main()
{
    // 플레이어 객체 포인터 생성
    Player *player = nullptr;
    std::string player_id;
    int class_number;

    // 몬스터 생성(3마리)
    std::vector<Monster *> monster;
    monster.push_back(new Goblin("Goblin"));
    monster.push_back(new Troll("Troll"));
    monster.push_back(new Golem("Golem"));

    // 아이디 생성
    player_id = make_id();

    // 직업 선택 및 생성
    class_number = choice_class();
    switch (class_number)
    {
    case 1:
        player = new Warrior(player_id);
        break;
    case 2:
        player = new Magician(player_id);
        break;
    case 3:
        player = new Thief(player_id);
        break;
    case 4:
        player = new Archer(player_id);
        break;
    default:
        break;
    }

    // 선택한 직업의 정보(스탯)
    announce_class(class_number, *player);

    // 게임 메뉴
    while (1)
    {
        switch (print_game_menu())
        {
        case 1:
            print_game_info();
            break;
        case 2:
            announce_class(class_number, *player);
            break;
        case 3:
            print_monster_menu(*player, monster);
            break;
        case 4:
            delete player;
            return 0;
        default:
            std::cout << "잘못된 입력입니다. 다시 입력해주세요." << std::endl;
            break;
        }
    }

    delete monster[0];
    delete monster[1];
    delete monster[2];
    delete player;

    return 0;
}

/********************************************************************/
/**************************게임 시작 전 세팅***************************/
/********************************************************************/

// 아이디 생성
std::string make_id()
{
    std::string id;
    std::cout << "아이디를 입력하세요(최대 20자, 수정불가): ";
    std::cin >> id;
    std::cout << std::endl;

    return id;
}

// 직업 선택
int choice_class()
{
    bool check = true;
    int choice;

    while (check)
    {
        std::cout << "직업을 선택하세요.(1.전사 2.마법사 3.도적 4.궁수): ";
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            check = false;
            return 1;
        case 2:
            check = false;
            return 2;
        case 3:
            check = false;
            return 3;
        case 4:
            check = false;
            return 4;
        default:
            std::cout << "잘 못 입력하셨습니다. 다시 입력해주세요.\n"
                      << std::endl;
            break;
        }
    }

    return 0;
}

// 선택한 직업의 기본 정보(스탯)
void announce_class(int class_number, Player &player_ref)
{
    std::cout << player_ref.get_player_name() << "님의 직업은 ";
    switch (class_number)
    {
    case 1:
        std::cout << "전사입니다. 현재 스탯은 아래와 같습니다." << std::endl;
        break;
    case 2:
        std::cout << "마법사입니다. 현재 스탯은 아래와 같습니다." << std::endl;
        break;
    case 3:
        std::cout << "도적입니다. 현재 스탯은 아래와 같습니다." << std::endl;
        break;
    case 4:
        std::cout << "궁수입니다. 현재 스탯은 아래와 같습니다.\n"
                  << std::endl;
        break;
    default:
        break;
    }
    player_ref.print_player_info();
}

/********************************************************************/
/*****************************게임 시작*******************************/
/********************************************************************/

// 게임 메뉴 출력
int print_game_menu()
{
    int input_number;

    std::cout << "1. 게임설명" << std::endl;
    std::cout << "2. 캐릭터 스탯 확인" << std::endl;
    std::cout << "3. 몬스터 사냥" << std::endl;
    std::cout << "4. 게임종료" << std::endl;
    std::cout << "숫자를 입력하세요: ";
    std::cin >> input_number;
    std::cout << std::endl;

    return input_number;
}

// 게임 튜토리얼 출력
void print_game_info()
{
    std::cout << "***************************튜토리얼*****************************" << std::endl;
    std::cout << "나의 수준에 맞는 몬스터를 잡고 레벨업을 해서 더 강한 몬스터를 잡아보세요." << std::endl;
    std::cout << "Tip1: 1레벨업 당 모든 스탯이 5포인트 오릅니다." << std::endl;
    std::cout << "Tip2: 몬스터는 가장 약한 1레벨부터 가장 강한 3레벨까지 있습니다." << std::endl;
    std::cout << "Tip3: 몬스터를 잡는데 성공하거나 실패하면 HP와 MP가 모두 찹니다." << std::endl;
    std::cout << "행운을 빕니다." << std::endl;
    std::cout << "**************************************************************\n"
              << std::endl;
}

/********************************************************************/
/*****************************몬스터사냥*******************************/
/********************************************************************/

void print_monster_menu(Player &player_ref, std::vector<Monster *> &monster_ref)
{
    int num;
    std::cout << "도전할 몬스터를 선택하세요." << std::endl;
    std::cout << "1. 고블린(하급)\n2. 트롤(중급)\n3. 골렘(상급)\n4. 뒤로가기\n입력: ";
    std::cin >> num;
    std::cout << std::endl;

    switch (num)
    {
    case 1:
        start_hunt_monster(player_ref, monster_ref[num - 1]);
        break;
    case 2:
        start_hunt_monster(player_ref, monster_ref[num - 1]);
        break;
    case 3:
        start_hunt_monster(player_ref, monster_ref[num - 1]);
        break;
    case 4:
        return;
    default:
        break;
    }
}

void start_hunt_monster(Player &player_ref_ref, Monster *monster_ref_monster)
{
    int player_damage = player_ref_ref.get_player_info(0) - monster_ref_monster->get_monster_info(1);
    if (player_damage < 0)
    {
        player_damage = 0;
    }
    int player_atk = player_ref_ref.get_player_info(0);
    int player_def = player_ref_ref.get_player_info(1);
    int player_hp = player_ref_ref.get_player_info(2);
    int player_mp = player_ref_ref.get_player_info(3);
    int player_spd = player_ref_ref.get_player_info(4);
    int player_exp = player_ref_ref.get_player_info(5);
    int player_lv = player_ref_ref.get_player_info(6);
    std::string player_name = player_ref_ref.get_player_name();

    int monster_damage = monster_ref_monster->get_monster_info(0) - player_ref_ref.get_player_info(1);
    if (monster_damage < 0)
    {
        monster_damage = 0;
    }
    int monster_hp = monster_ref_monster->get_monster_info(2);
    int monster_spd = monster_ref_monster->get_monster_info(3);
    int monster_exp = monster_ref_monster->get_monster_info(4);
    std::string monster_name = monster_ref_monster->get_monster_name();

    int tmp_exp;
    int tmp_lv;

    bool toggle; // 플레이어와 몬스터의 공격이 번갈아가게 하기위해 쓰는 변수

    std::cout << "######야생의 " << monster_name << "이 나타났다!!!######\n" << std::endl;

    // 플레이어의 스피드가 몬스터보다 크거나 같다면
    if (player_spd >= monster_spd)
    {
        toggle = true; // 플레이어가 선공
    }
    else
    {
        toggle = false; // 몬스터가 선공
    }
    while (1)
    {
        if (toggle)
        {
            player_ref_ref.attack();
            if (player_damage != 0)
            {
                std::cout << player_name << "이(가) " << monster_name << "에게 " << player_damage << "의 피해를 줬다!" << std::endl;
                monster_hp -= player_damage;
                if (monster_hp <= 0) // 몬스터 피가 0일때
                {
                    std::cout << monster_name << "이 쓰러졌다!\n" << std::endl;
                    player_exp += monster_exp;
                    player_ref_ref.set_player_info(5, player_exp);

                    if (player_exp >= 10) // 경험치가 꽉 찼을 때
                    {
                        tmp_lv = player_exp / 10;
                        player_lv += tmp_lv;
                        tmp_exp = player_exp % 10;

                        std::cout << "*********************** 레 벨 업! ***********************" << std::endl;
                        std::cout << player_name << "의 레벨이 " << tmp_lv << "만큼 올랐습니다!" << std::endl;
                        std::cout << player_name << "의 현재 레벨: " << player_lv << ", 현재 경험치: " << tmp_exp << std::endl;
                        std::cout << "********************************************************\n" << std::endl;

                        player_atk += 5;
                        player_def += 5;
                        player_hp = player_ref_ref.get_player_info(2);
                        player_hp += 5;
                        player_mp += 5;
                        player_spd += 5;

                        player_ref_ref.set_player_info(0, player_atk);
                        player_ref_ref.set_player_info(1, player_def);
                        player_ref_ref.set_player_info(2, player_hp);
                        player_ref_ref.set_player_info(3, player_mp);
                        player_ref_ref.set_player_info(4, player_spd);
                        player_ref_ref.set_player_info(5, tmp_exp);
                        player_ref_ref.set_player_info(6, player_lv);
                    }

                    return;
                }
            }
            else
            {
                std::cout << "Miss!!!!" << std::endl;
            }
            std::cout << monster_name << "의 남은 HP: " << monster_hp << std::endl;
            std::cout << std::endl;
            toggle = false;
        }
        else
        {
            monster_ref_monster->attack();
            if (monster_damage != 0)
            {
                std::cout << monster_name << "이 " << player_name << "에게 " << monster_damage << "의 피해를 줬다!" << std::endl;
                player_hp -= monster_damage;
                if (player_hp <= 0) // 플레이어 피가 0일때
                {
                    std::cout << "You Died..." << std::endl;
                    return;
                }
            }
            else
            {
                std::cout << "Miss!!!!" << std::endl;
            }

            std::cout << player_name << "의 남은 HP: " << player_hp << std::endl;
            std::cout << std::endl;
            toggle = true;
        }
    }
}
