#include <iostream>
#include <string>


class Monster {
public:
    enum class Type{
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        max_monster_types,
    };

    Monster(Type monsterType, std::string monsterName, std::string monsterRoar, int monsterHitPoint)
    : type(monsterType), name(monsterName), roar(monsterRoar), hitPoint(monsterHitPoint)
    {}

    void print() {
        std::cout << name << " the " << static_cast<int>(type) << " has " << hitPoint << " hit points and say " << roar << '\n';
    }

private:
    Type type;
    std::string name{};
    std::string roar{};
    int hitPoint{};
};


int main() {
    Monster skeleton{Monster::Type::Skeleton, "Bones", "*rattle*", 4};
    skeleton.print();
}

