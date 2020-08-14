#include <iostream>
#include <string>

enum class MonsterType
{
    ogre,
    dragon,
    orc,
    giantSpider,
    slime,
};

struct Monster
{
    MonsterType monsterType;
    std::string name;
    int health;
};

void printMonster(Monster monster)
{
    std::string monsterType{};

    if (monster.monsterType == MonsterType::ogre)
        monsterType = "ogre";
    else if (monster.monsterType == MonsterType::dragon)
        monsterType = "dragon";
    else if (monster.monsterType == MonsterType::orc)
        monsterType = "orc";
    else if (monster.monsterType == MonsterType::giantSpider)
        monsterType = "giantSpider";
    else if (monster.monsterType == MonsterType::slime)
        monsterType = "slime";
        

    std::cout << "This " << monsterType << " is named " << monster.name << " and has " << monster.health << " health.\n";
}

int main()
{
    Monster ogre{MonsterType::ogre, "Torg", 145};
    Monster slime{MonsterType::slime, "Blurp", 23};
    printMonster(ogre);
    printMonster(slime);
}