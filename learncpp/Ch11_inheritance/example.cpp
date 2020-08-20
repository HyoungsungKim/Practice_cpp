#include <iostream>
#include <string>

class Person {
public:
    std::string m_name;
    int m_age;

    Person(std::string name = "", int age = 0)
    : m_name(name), m_age(age) {}

    std::string getName() const { return m_name;}
    int getAge() const {return m_age;}
};

class BaseBallPlayer: public Person {
public:
    double m_battingAverage;
    int m_homeRuns;

    BaseBallPlayer(double battingAverage = 0.0, int homeRuns = 0) 
    : m_battingAverage(battingAverage), m_homeRuns(homeRuns) {}
};

int main() {
    BaseBallPlayer joe;
    joe.m_name = "Joe";
    std::cout << joe.getName() << '\n';

    return 0;
}