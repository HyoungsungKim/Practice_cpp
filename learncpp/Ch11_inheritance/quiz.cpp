#include <iostream>
#include <string>

class Creature {
private:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_attack;
    int m_carrying;

public:
    Creature(std::string name, int symbol, int health, int attack, int carrying)
    : m_name(name), m_symbol(symbol), m_health(health), m_attack(attack), m_carrying(carrying) {}

    const std::string& getName() {
        return m_name;
    }
    const char& getSymbol() {
        return m_symbol;
    }
    const int& getHealth() {
        return m_health;
    }
    const int& getAttack() {
        return m_attack;
    }
    const int& getGold() {
        return m_carrying;
    }

    void reduceHealth(const int &reduction) {
        m_health -= reduction;
    }

    bool isDead() {
        return m_health <= 0;
    }

    void addGold(const int &gold) {
        m_carrying += gold;
    }
};

int main() {
    Creature o{ "orc", 'o', 4, 2, 10 };
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";
 
	return 0;
}

