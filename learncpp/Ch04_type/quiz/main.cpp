#include <iostream>
#include "gravity.h"

int main()
{
    double currentHeight{};
    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> currentHeight;

    for(int sec = 0; sec <= 5; ++sec) {
        double nextHeight{getNextHeight(static_cast<double>(sec), currentHeight)};
        if (nextHeight > 0)
            std::cout << "At " << sec << " seconds, the ball is at height: " << nextHeight << " meters\n";
        else
            std::cout << "At " << sec << " seconds, the ball is on the ground.\n";
    }

    return 0;
}