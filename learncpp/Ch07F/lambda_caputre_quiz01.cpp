#include <iostream>
#include <string>
 
int main()
{
  std::string favoriteFruit{ "grapes" };
 
  auto printFavoriteFruit{
    [=]() {
      std::cout << "I like " << favoriteFruit << '\n';
    }
  };
 
  favoriteFruit = "bananas with chocolate";
 
  printFavoriteFruit();
 
  return 0;
}