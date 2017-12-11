#include "level.h"
#include <iostream>
#include <stdio.h>

void Level::create()
{
    if (createflag == 1)
    {
        freopen ("1.txt", "r", stdin);
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                std::cin >> map[i][j];
    }
}
