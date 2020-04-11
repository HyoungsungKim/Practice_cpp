#include "../common/std_lib_facilities.h"

int main(){
    cout << "please enter your name(followed by 'enter'):\n";
    string first_name = "???";
    int age;

    cin >> first_name >> age;
    cout << "Hello " << first_name << "(age" << age <<")\n";
}