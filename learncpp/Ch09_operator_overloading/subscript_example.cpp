#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>


struct StudentGrade {
    std::string s_name{};
    char s_grade{};
};

class GradeMap {
private:
    std::vector<StudentGrade> m_map{};

public:
    char& operator[](const std::string& name);
};

char& GradeMap::operator[](const std::string& name) {
    std::vector<StudentGrade>::iterator it { std::find_if(m_map.begin(), m_map.end(), 
    [&](const auto& student){
        return (student.s_name == name);
    })};

    if ( it != m_map.end()) {
        return it->s_grade;
        // It is same with
        //return (*it).s_grade;
    }

    m_map.push_back(StudentGrade{name});

    return m_map.back().s_grade;

}

int main() {
    GradeMap grades{};

    //grades["Joe"] = 'A';
    //grades["Frank"] = 'B';

    //std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    //std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    char& gradeJoe{ grades["Joe"] }; // does a push_back
	gradeJoe = 'A';
 
	char& gradeFrank{ grades["Frank"] }; // does a push_back
	gradeFrank = 'B';
 
	std::cout << "Joe has a grade of " << gradeJoe << '\n';
	std::cout << "Frank has a grade of " << gradeFrank << '\n';
 
}