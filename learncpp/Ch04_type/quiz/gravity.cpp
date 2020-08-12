#include "gravity.h"

double getNextHeight(int sec, double currentHeight)
{
    double nextHeight{currentHeight - constant::gravity * sec * sec / 2};
    if ( nextHeight < 0)
        return 0;
    else        
    {
        return nextHeight;
    }
}