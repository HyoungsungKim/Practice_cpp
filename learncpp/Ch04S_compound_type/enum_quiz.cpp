#include <iostream>
#include <string>

enum MonsterType
{
    MONSTER_ORC,
    MONSTER_GOBLIN,
    MONSTER_TROLL,
    MONSTER_OGRE,
    MONSTER_SKELETON,
};

int main()
{
    MonsterType monsterType{ MONSTER_TROLL };
    std::cout << monsterType << '\n';
}
